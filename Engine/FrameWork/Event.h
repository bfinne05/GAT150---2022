#pragma once
#include <String>
#include <Variant>
#include <functional>

namespace gre
{
	class GameObject;

	class Event
	{
	public:
		using functionPtr = std::function<void(const Event&)>;
		

	public:
		std::string name;
		GameObject* reciever = nullptr;
		std::variant<int, bool, float, std::string> data;
	};

	class INotify
	{
	public:
		virtual void OnNotify(const Event& event) = 0;
	};
}