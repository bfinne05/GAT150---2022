#pragma once
#include "FrameWork/Component.h"
namespace gre
{
	class Renderer;

	class RendererComponent : public Component
	{
	public:
		RendererComponent() = default;
		virtual void Draw(Renderer& renderer) = 0;
	};
}
