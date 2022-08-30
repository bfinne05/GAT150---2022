#pragma once
#include "FrameWork/Component.h"
#include "Math/Rect.h"

namespace gre
{
	class Renderer;
	struct Rect;

	class RendererComponent : public Component
	{
	public:
		RendererComponent() = default;
		virtual void Draw(Renderer& renderer) = 0;
		virtual void Update() override;

		virtual Rect& GetSource() { return source; }

	protected:
		Rect source;

	};
}
