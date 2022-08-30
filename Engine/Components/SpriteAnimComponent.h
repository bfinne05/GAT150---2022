#pragma once
#include "RendererComponent.h"
#include "Math/Rect.h"
namespace gre
{
	class Texture;

	class SpriteAnimComponent : public RendererComponent
	{
	public:
		CLASS_DECLARATION(SpriteAnimComponent)
		// Inherited via RendererComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;
		Rect& GetSource() override;

		// Inherited via RendererComponent
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;

		int frame = 0;
		float frameTimer = 0;

		Rect source;
		//shared texture with model in model component
		std::shared_ptr<Texture> m_texture;

	};
}