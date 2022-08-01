#pragma once 
// !! add necessary includes 
#include "Renderer.h"
#include "Text.h"

// !! forward declare the _TTF_Font struct 
struct _TTF_Font;

namespace gre
{
	class text;
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
		friend class Text;
	};
}