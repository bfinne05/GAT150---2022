#pragma once
#include "../Math/Transform.h"

namespace gre
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}
		GameObject(Transform& transform) : m_transform{ transform } {}

		Transform& GetTransform() { return m_transform; }

		virtual void Update() = 0;

		Transform m_transform;
	protected:


	};
}