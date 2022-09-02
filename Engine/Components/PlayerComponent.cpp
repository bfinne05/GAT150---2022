#include "PlayerComponent.h"
#include "Engine.h"
#include "Math/Vector2.h"
#include <iostream>

namespace gre
{
	void PlayerComponent::Initialize()
	{
		CharacterComponent::Initialize();
		g_eventManager.Subscribe("EVENT_PICKUP", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_owner);
	}

	void gre::PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;
		// set camera 
		auto camera = m_owner->GetScene()->GetActorFromName("Camera");
		if (camera)
		{
			camera->m_transform.position = m_owner->m_transform.position;
		}


		if (gre::g_inputSystem.GetKeyState(gre::key_right) == gre::InputSystem::KeyState::Held)
		{
			direction = Vector2::right;
		}

		if (gre::g_inputSystem.GetKeyState(gre::key_left) == gre::InputSystem::KeyState::Held)
		{
			direction = Vector2::left;
		}

		float thrust = 0;
		if (gre::g_inputSystem.GetKeyState(gre::key_up) == gre::InputSystem::KeyState::Held)
		{

			thrust = 500;

		}

		Vector2 velocity;
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
			velocity = component->velocity;
		}

		//jump
		if (m_groundCount > 0 && g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
		{
			Vector2 velocity;
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				g_audioSystem.PlayAudio("jump");
				std::cout << "i jumped!!!" << std::endl;
				// if in the air (m_groundCount == 0) then reduce force 
				float multiplier = (m_groundCount > 0) ? 1 : 0.2f;
				component->ApplyForce(Vector2::up * jump * multiplier);
				velocity = component->velocity;
				m_groundCount = 0;
			}
		}

		if (g_inputSystem.GetKeyState(key_z) == InputSystem::KeyState::Pressed)
		{
			if (!attackState)
			{
				g_audioSystem.PlayAudio("sword");
				std::cout << "Attack" << std::endl;
				attackState = true;
				attackTimer = 0.5f;
			}
		}

		if (attackState)
		{
			attackTimer -= g_time.deltaTime;
			if (attackTimer <= 0)
			{
				attackState = false;
			}
		}


  		auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
		if (animComponent)
		{
			if (velocity.x != 0) animComponent->SetFlipHorizontal(velocity.x < 0);
			if (std::fabs(velocity.x) > 0)
			{
				animComponent->SetSequence("run");
			}
			else if(attackState)
			{
				animComponent->SetSequence("attack");
				
			}
			else
			{
				animComponent->SetSequence("idle");
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		CharacterComponent::Read(value);
		READ_DATA(value, jump);

		return true;
	}

	void PlayerComponent::OnNotify(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			std::cout << health << std::endl;
			if (health <= 0)
			{
				m_owner->SetDestroy();

				Event event;
				event.name = "EVENT_PLAYER_DEAD";

				g_eventManager.Notify(event);
			}
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			std::cout << "player enter\n";
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;

			g_eventManager.Notify(event);

			other->SetDestroy();
		}
		if (other->GetTag() == "Enemy" && attackState == true)
		{
			std::cout << "player Hit Enemy\n";
			gre::Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.reciever = other;

			gre::g_eventManager.Notify(event);
		}
		if (other->GetTag() == "Ground")
		{
			std::cout << m_groundCount << std::endl;
			std::cout << "player enter ground\n";
			m_groundCount++;
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "player exit\n"; 
	}

}

