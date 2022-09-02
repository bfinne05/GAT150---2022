#include "EventManager.h"

void gre::EventManager::Initialize()
{
}

void gre::EventManager::Shutdown()
{
}

void gre::EventManager::Update()
{
}

void gre::EventManager::Subscribe(const std::string& name, Event::functionPtr function, GameObject* reciever)
{
	Observer observer;
	observer.receiver = reciever;
	observer.function = function;

	m_events[name].push_back(observer);
}

void gre::EventManager::Unsubscribe(const std::string& name, GameObject* receiver)
{
	// get list of observers for event
	auto& observers = m_events[name];

	// remove observer with matching receiver from observers
	for (auto iter = observers.begin(); iter != observers.end(); iter++)
	{
		if (iter->receiver == receiver)
		{
			observers.erase(iter);
			break;
		}
	}
}

void gre::EventManager::Notify(const Event& event)
{
	auto observers = m_events[event.name];
	for (auto& observer : observers)
	{
		if (event.reciever == nullptr || event.reciever == observer.receiver)
		{
			observer.function(event);
		}
	}
}
