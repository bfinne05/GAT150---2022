#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Engine.h"
namespace gre
{

	class PlayerComponent : public Component
	{

	public:
		PlayerComponent() = default;
	
		void Update();
	};
}