#pragma once
#include "Vector2.h"
#include <string>
#include <map>
#include "SDL2/SDL.h"

class RendererBase
{
public:
	virtual void Initialize();
	virtual void Cleanup();

	virtual void PrecacheTexture(const std::string& name, const std::string& path);
	virtual void RenderImage(const char* textureID, Vector2 position);
	virtual void RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip);
	virtual void RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color);
	virtual void RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color);
	virtual void RenderPresent();
	virtual void RenderClear();
	virtual bool TextureExists(const std::string& Texture);

	// Font Stuff
	virtual void PrecacheFont(const std::string& name, const std::string& path, int fontsize);
	virtual void RenderFont(const std::string& message, const char* fontID, Vector2 position, SDL_Color color);
	virtual void RenderFont(const std::string& message, const char* fontID, Vector2 position, double rotation, SDL_RendererFlip flip, SDL_Color color);

	virtual void SetRenderView(int x, int y);
	virtual void SetRenderView(Vector2 pos);
	virtual Vector2 VectorToRenderVector(Vector2 in);

	virtual ~RendererBase();

	std::map<std::string, Vector2> TexSizeRepository;
	Vector2 RenderView;
};
