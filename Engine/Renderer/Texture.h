#pragma once 
#include "..\Math\Vector2.h" 
#include <string> 

// !! forward declaration for SDL pointers below (SDL likes to use structs) 
struct SDL_Texture;
// !! add namespace 
namespace gre
{
// !! forward declaration for Renderer below 
class Renderer;
class Texture
{
public:
	Texture() = default;
	~Texture();

	bool Create(Renderer& renderer, const std::string& filename);

	Vector2 GetSize() const;

	// !! allow Renderer to access private texture data (friend) 
private:
	SDL_Texture* m_texture = nullptr;
	friend class Renderer;
};
}