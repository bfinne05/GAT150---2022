#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Engine.h"
#include "Physics/Collision.h"
#include "CharacterComponent.h"
namespace gre
{

	class PlayerComponent : public CharacterComponent
	{

	public:
		PlayerComponent() = default;
		CLASS_DECLARATION(PlayerComponent)
		void Initialize() override;
		void Update();

		virtual void OnNotify(const Event& event) override;
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float jump = 1000.0f;
		int m_groundCount = 0;
		bool attackState = false;
		float attackTimer = 0;
	};
}