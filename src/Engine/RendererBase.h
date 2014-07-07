#pragma once
#include <string>
#include <map>

#include "Vector2.h"

// Temporary
#include "SDL2/SDL_mixer.h"

#include "ResourceWrapper.h"
CreateFakeWrapper(SDLMusicWrapper, ResourceWrapper<Mix_Music*>);
CreateFakeWrapper(SDLSoundWrapper, ResourceWrapper<Mix_Chunk*>);

class RendererBase
{
public:
	virtual void Initialize();
	virtual void Cleanup();

	virtual void PrecacheTexture(const std::string& name, const std::string& path);
	virtual void RenderImage(const char* textureID, Vector2 worldposition);
	virtual void RenderImage(const char* textureID, Vector2 worldposition, double scale, double rotation, SDL_RendererFlip flip);
	virtual void RenderDrawRect(Vector2 worldposition, Vector2 dimensions, SDL_Color color);
	virtual void RenderFillRect(Vector2 worldposition, Vector2 dimensions, SDL_Color color);
	virtual void RenderPresent();
	virtual void RenderClear();
	virtual bool TextureExists(const std::string& Texture);

	// Font Stuff
	virtual void PrecacheFont(const std::string& name, const std::string& path, int fontsize);
	virtual void RenderFont(const std::string& message, const char* fontID, Vector2 worldposition, SDL_Color color);
	virtual void RenderFont(const std::string& message, const char* fontID, Vector2 worldposition, double rotation, SDL_RendererFlip flip, SDL_Color color);

	// Sound Stuff (Temporary)
	virtual void PrecacheSound(const std::string& name, const std::string& path);
	virtual void PrecacheMusic(const std::string& name, const std::string& path);
	virtual void PlaySound(const std::string& name, int channel, int loops);
	virtual void PlayMusic(const std::string& name);
	virtual bool IsMusicPlaying();
	virtual void ResumeMusic();
	virtual void PauseMusic();
	virtual void StopMusic();

	std::map<std::string, SDLMusicWrapper*> MusicRepository;
	std::map<std::string, SDLSoundWrapper*> SoundRepository;

	virtual void SetRenderView(int x, int y);
	virtual void SetRenderView(Vector2 pos);
	virtual Vector2 WorldToLocalVector(Vector2 in);
	virtual Vector2 LocalToWorldVector(Vector2 in);

	virtual ~RendererBase();

	std::map<std::string, Vector2> TexSizeRepository;
	Vector2 RenderView;
};
