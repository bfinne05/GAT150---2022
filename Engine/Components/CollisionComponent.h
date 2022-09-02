#pragma once
#include "FrameWork/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
#include <functional>
namespace gre
{
	class CollisionComponent : public Component, public ICollision
	{
	public:
		CLASS_DECLARATION(CollisionComponent)
		using functionPtr = std::function<void(Actor*)> ;
	public:

		// Inherited via Component
		virtual void Update() override;
		virtual void Initialize() override;


		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		void SetCollisionEnter(functionPtr function) { m_enterFunction = function; }
		void SetCollisionExit(functionPtr function) { m_exitFunction = function; }

	private:
		PhysicsSystem::CollisionData data;
		Vector2 scale_offset = Vector2{ 1,1 };

		functionPtr m_enterFunction;
		functionPtr m_exitFunction;
	};
}