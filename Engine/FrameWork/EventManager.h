#pragma once
#include "Event.h"
#include <map>
#include <list>

namespace gre
{
	class EventManager
	{
	public:
		struct Observer
		{
			GameObject* receiver;
			Event::functionPtr function;
		};
	public:
		void Initialize();
		void Shutdown();
		void Update();

		void Subscribe(const std::string& name, Event::functionPtr function, GameObject* reciever = nullptr);
		void Unsubscribe(const std::string& name, GameObject* reciever = nullptr);

		void Notify(const Event& event);

	private:
		std::map< std::string, std::list<Observer>> m_events;
	};
}