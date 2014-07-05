#include "RendererBase.h"

void RendererBase::Initialize(){}
void RendererBase::PrecacheTexture(const std::string& name, const std::string& path){}
void RendererBase::RenderImage(const char* textureID, Vector2 position){}
void RendererBase::RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip){}
void RendererBase::RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color){}
void RendererBase::RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color){}
void RendererBase::RenderPresent(){}
void RendererBase::RenderClear(){}
void RendererBase::Cleanup(){}
Vector2 RendererBase::VectorToRenderVector(Vector2 in){ return Vector2(0,0); }
RendererBase::~RendererBase(){}

void RendererBase::SetRenderView(int x, int y)
{
	this->RenderView.x = x;
	this->RenderView.y = y;
}

void RendererBase::SetRenderView(Vector2 pos)
{
	this->SetRenderView(pos.x, pos.y);
}

bool RendererBase::TextureExists(const std::string& Texture){ return false; }

// Font Stuff
void RendererBase::PrecacheFont(const std::string& name, const std::string& path, int fontsize){}
void RendererBase::RenderFont(const std::string& message, const char* fontID, Vector2 position, SDL_Color color){}
void RendererBase::RenderFont(const std::string& message, const char* fontID, Vector2 position, double rotation, SDL_RendererFlip flip, SDL_Color color){}
