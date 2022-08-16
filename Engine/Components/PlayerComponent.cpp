#include "PlayerComponent.h"

#include <iostream>

namespace gre
{
	void gre::PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;

		if (gre::g_inputSystem.GetKeyState(gre::key_right) == gre::InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		}

		if (gre::g_inputSystem.GetKeyState(gre::key_left) == gre::InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
		}

		float thrust = 0;
		if (gre::g_inputSystem.GetKeyState(gre::key_up) == gre::InputSystem::KeyState::Held)
		{

			thrust = 500;

		}
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			//force
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);

			//gravitational force
			force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 100.0f;
			component->ApplyForce(force);
		}

		if (gre::g_inputSystem.GetKeyState(gre::key_down) == gre::InputSystem::KeyState::Held)
		{
			//direction = Vector2::down;

		}
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->play();
			}
		}
	}

}

