#pragma once
#include "RendererBase.h"
#include <map>
#include "SDL2\SDL.h"
#include "SDL2\SDL_image.h"

#include "ResourceWrapper.h"
CreateFakeWrapper(SDLTextureWrapper, ResourceWrapper<SDL_Texture*>);

class RendererSDL : public RendererBase
{
public:
	void Initialize() override;
	void PrecacheTexture(const std::string& name, const std::string& path) override;
	void RenderImage(const char* textureID, Vector2 position) override;
	void RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip) override;
	void RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color) override;
	void RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color) override;
	void RenderPresent() override;
	void RenderClear() override;
	void Cleanup() override;

	bool TextureExists(const std::string& Texture) override;

	Vector2 VectorToRenderVector(Vector2 in) override;

public:
	std::map<std::string, SDLTextureWrapper*> TextureRepository;

private:
	typedef RendererBase Super;

public:
	SDL_Window* GameWindow;
	SDL_Renderer* GameRenderer;

};
