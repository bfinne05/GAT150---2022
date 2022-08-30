#pragma once 
#include "Renderer.h"
#include "Resource/Resource.h"
#include "Text.h"

struct _TTF_Font;
struct SDL_Surface;

namespace gre
{// make this a resource
	class text;
	struct Color;

	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(std::string filename, ...) override;
		bool Load(const std::string& filename, int fontSize);
		SDL_Surface* CreateSurface(const std::string& text, const Color& color);

	private:
		_TTF_Font* m_ttfFont = nullptr;
		friend class Text;
	};
}