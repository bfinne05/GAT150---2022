#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Engine.h"
#include "Physics/Collision.h"

namespace gre
{

	class PlayerComponent : public Component, public ICollision
	{

	public:
		PlayerComponent() = default;
		CLASS_DECLARATION(PlayerComponent)
		void Initialize() override;
		void Update();

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float speed = 0;

	};
}