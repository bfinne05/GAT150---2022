#pragma once
#include "RendererComponent.h"
#include "Math/Rect.h"
namespace gre
{
	class Texture;

	class SpriteComponent : public RendererComponent
	{
	public:
		CLASS_DECLARATION(SpriteComponent);
		// Inherited via RendererComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		// Inherited via RendererComponent
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		//shared texture with model in model component
		std::shared_ptr<Texture> m_texture;
		
	};
}