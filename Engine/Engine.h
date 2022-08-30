#pragma once

#include"Serialization/Json.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "FrameWork/Factory.h"
#include "FrameWork/Singleton.h"
#include "FrameWork/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ModelComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TileMapComponent.h"
#include "Components/TextComponent.h"

#include "Physics/PhysicsSystem.h"

#include"Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"

#include "Resource/ResourceManager.h"

#include <memory>
#include <Vector>
#include <list>
#include <variant>

namespace gre
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;
	
	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}