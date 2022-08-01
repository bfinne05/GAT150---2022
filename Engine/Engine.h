#pragma once
#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "FrameWork/Game.h"

#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "FrameWork/Scene.h"

#include"Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"

#include <memory>

namespace gre
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}