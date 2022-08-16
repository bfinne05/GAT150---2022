#pragma once
#include "FrameWork/Component.h"
#include "Math/Vector2.h"

namespace gre
{

	class PhysicsComponent : public Component
	{

	public:
		PhysicsComponent() = default;

		void Update();
		void ApplyForce(Vector2& force) { m_acceleration += force; };

	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_damping = 1;
	};
}