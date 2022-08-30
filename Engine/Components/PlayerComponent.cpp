#include "PlayerComponent.h"
#include "Engine.h"
#include "Math/Vector2.h"
#include <iostream>

namespace gre
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisoinEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisoinExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}
	void gre::PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;

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
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}

		if (gre::g_inputSystem.GetKeyState(gre::key_down) == gre::InputSystem::KeyState::Held)
		{
			//direction = Vector2::down;

		}
		//jump
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 500);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "Event Add Points";
			event.data = 100;

			g_eventManager.Notify(event);

			other->SetDestroy();
		}
		std::cout << "player enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "player exit\n"; 
	}

}

