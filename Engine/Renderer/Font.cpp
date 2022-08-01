#include "Font.h"
#include <SDL_ttf.h>
gre::Font::Font(const std::string& filename, int fontSize)
{
	Load(filename, fontSize);
}

gre::Font::~Font()
{
	if (m_ttfFont != NULL)
	{
		TTF_CloseFont(m_ttfFont);
	}
}

void gre::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
}
