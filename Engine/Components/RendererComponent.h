#pragma once
#include "FrameWork/Component.h"
#include "Math/Rect.h"
#include "Math/Vector2.h"

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
		void SetFlipHorizontal(bool flip = true) { flipHorizontal = flip; }
		bool GetFlipHorizontal() { return flipHorizontal; }


	protected:
		Rect source;
		Vector2 registration = Vector2{0.5f, 0.5f};
		bool flipHorizontal = false;
	};
}
