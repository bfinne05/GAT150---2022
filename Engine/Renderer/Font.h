#pragma once 
#include "Renderer.h"
#include "Resource/Resource.h"
#include "Text.h"

struct _TTF_Font;

namespace gre
{// make this a resource
	class text;
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		//bool Create(const std::string& filename, void* data = nullptr) override; 
		bool Create(std::string filename, ...) override;
		bool Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
		friend class Text;
	};
}