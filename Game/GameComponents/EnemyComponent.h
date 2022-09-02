#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public gre::CharacterComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(gre::Actor* other) override;
	virtual void OnCollisionExit(gre::Actor* other) override;

	virtual void OnNotify(const gre::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:

};