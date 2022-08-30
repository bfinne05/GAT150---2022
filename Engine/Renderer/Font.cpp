#include "Font.h"
#include <SDL_ttf.h>
#include <Core/Logger.h>

namespace gre
{

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

    bool gre::Font::Load(const std::string& filename, int fontSize)
    {
	    m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

        return true;
    }

    bool gre::Font::Create(std::string filename, ...)
    {
            // va_list - type to hold information about variable arguments 
            va_list args;

            // va_start - enables access to variadic function arguments 
            va_start(args, filename);

            // va_arg - accesses the next variadic function arguments 
            int fontSize = va_arg(args, int);

            // va_end - ends traversal of the variadic function arguments 
            va_end(args);

            // create texture (returns true/false if successful) 
            return Load(filename, fontSize);
    }

     SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
     {
        // !! convert Color color to SDL_Color c 
        // !! get address of color (&) 
        // !! cast to SDL_Color 
        // !! dereference 
        SDL_Color c = *((SDL_Color*)(&color));
        SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);

        // !! check if surface is nullptr, if so then LOG error 
        if (surface == nullptr)
        {
            LOG(SDL_GetError());
        }

        return surface;
    } 
}
