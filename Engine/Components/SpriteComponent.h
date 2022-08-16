#pragma once
#include "RendererComponent.h"

namespace gre
{
	class Texture;

	class SpriteComponent : public RendererComponent
	{
	public:
		// Inherited via RendererComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		//shared texture with model in model component
	public:
		std::shared_ptr<Texture> m_texture;

	};
}