#pragma once
#include "RendererBase.h"
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "ResourceWrapper.h"

CreateFakeWrapper(SDLTextureWrapper, ResourceWrapper<SDL_Texture*>);
CreateFakeWrapper(SDLFontWrapper, ResourceWrapper<TTF_Font*>);

class RendererSDL : public RendererBase
{
public:
	// Main rendering stuff
	void Initialize() override;
	void RenderPresent() override;
	void RenderClear() override;
	void Cleanup() override;

	// Basic Rendering
	void RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color) override;
	void RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color) override;

	// Texture Stuff
	void PrecacheTexture(const std::string& name, const std::string& path) override;
	void RenderImage(const char* textureID, Vector2 position) override;
	void RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip) override; // TODO: make SDL_RendererFlip my own type?
	bool TextureExists(const std::string& Texture) override;

	// Font Stuff
	void PrecacheFont(const std::string& name, const std::string& path, int fontsize) override;
	void RenderFont(const std::string& message, const char* fontID, Vector2 position, SDL_Color color) override;
	void RenderFont(const std::string& message, const char* fontID, Vector2 position, double rotation, SDL_RendererFlip flip, SDL_Color color) override;

	// Vector translation
	Vector2 VectorToRenderVector(Vector2 in) override;

public:
	std::map<std::string, SDLTextureWrapper*> TextureRepository;
	std::map<std::string, SDLFontWrapper*> FontRepository;

private:
	typedef RendererBase Super;

public:
	SDL_Window* GameWindow;
	SDL_Renderer* GameRenderer;

};
