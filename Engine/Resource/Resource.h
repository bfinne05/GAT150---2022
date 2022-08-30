#pragma once
#include <string>
namespace gre
{
	class Resource
	{
	public:
		virtual bool Create(std::string name, ...) = 0;

	};

}