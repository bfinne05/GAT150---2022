#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName("Player");
    if (actor)
    {
        gre::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        gre::Vector2 force = direction.Normalized() * 2;

        auto component = m_owner->GetComponent<gre::PhysicsComponent>();
        if (component) component->ApplyForce(force);
        {
            auto component = m_owner->GetComponent<gre::RendererComponent>();
            if (component)
            {
                component->SetFlipHorizontal(direction.x < 0);
            }

        }
    }
}

void EnemyComponent::OnCollisionEnter(gre::Actor* other)
{
    if (other->GetTag() == "Player")
    {
        gre::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage;
        event.reciever = other;

        gre::g_eventManager.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(gre::Actor* other)
{

}

void EnemyComponent::OnNotify(const gre::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            gre::g_audioSystem.PlayAudio("destroy");
            gre::Event event;
            event.name = "EVENT_DROP";

            gre::g_eventManager.Notify(event);
            m_owner->SetDestroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}