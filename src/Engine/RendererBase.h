#pragma once
#include "Vector2.h"
#include <string>
#include <map>
#include "SDL2\SDL.h"

class RendererBase
{
public:
	virtual void Initialize();
	virtual void PrecacheTexture(const std::string& name, const std::string& path);
	virtual void RenderImage(const char* textureID, Vector2 position);
	virtual void RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip);
	virtual void RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color);
	virtual void RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color);
	virtual void RenderPresent();
	virtual void RenderClear();


	virtual void SetRenderView(int x, int y);
	virtual void SetRenderView(Vector2 pos);

	virtual void Cleanup();
	virtual bool TextureExists(const std::string& Texture);

	virtual Vector2 VectorToRenderVector(Vector2 in);

	virtual ~RendererBase();

	std::map<std::string, Vector2> TexSizeRepository;
	Vector2 RenderView;
};
