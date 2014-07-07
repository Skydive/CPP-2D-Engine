#include "RendererBase.h"
#include "Engine.h"
#include <math.h>

// Temporary
#include <stdlib.h>
#include <stdio.h>

void RendererBase::Initialize()
{
	// Temporary
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		system("PAUSE");
		exit(EXIT_SUCCESS);
	}
}
void RendererBase::PrecacheTexture(const std::string& name, const std::string& path){}
void RendererBase::RenderImage(const char* textureID, Vector2 worldposition){}
void RendererBase::RenderImage(const char* textureID, Vector2 worldposition, double scale, double rotation, SDL_RendererFlip flip){}
void RendererBase::RenderDrawRect(Vector2 worldposition, Vector2 dimensions, SDL_Color color){}
void RendererBase::RenderFillRect(Vector2 worldposition, Vector2 dimensions, SDL_Color color){}
void RendererBase::RenderPresent(){}
void RendererBase::RenderClear(){}
void RendererBase::Cleanup()
{
	for(auto iter = SoundRepository.begin(); iter != SoundRepository.end(); iter++)
	{
		Mix_FreeChunk(iter->second->Data);
		iter->second->Data = nullptr;
		delete iter->second;
		iter->second = nullptr;
	}
	for(auto iter = MusicRepository.begin(); iter != MusicRepository.end(); iter++)
	{
		Mix_FreeMusic(iter->second->Data);
		iter->second->Data = nullptr;
		delete iter->second;
		iter->second = nullptr;
	}
	Mix_Quit();
}
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
void RendererBase::RenderFont(const std::string& message, const char* fontID, Vector2 worldposition, SDL_Color color){}
void RendererBase::RenderFont(const std::string& message, const char* fontID, Vector2 worldposition, double rotation, SDL_RendererFlip flip, SDL_Color color){}


// Vector Translation
Vector2 RendererBase::WorldToLocalVector(Vector2 in)
{
	//TODO: Improve this
	// Displace coordinates.
	in.x += floor(RenderView.x+(Engine::Properties.Width/2));
	in.y += floor(RenderView.y+(Engine::Properties.Height/2));
	return in;
}

Vector2 RendererBase::LocalToWorldVector(Vector2 in)
{
	//TODO: Improve this
	// Displace coordinates.
	in.x -= floor(RenderView.x+(Engine::Properties.Width/2));
	in.y -= floor(RenderView.y+(Engine::Properties.Height/2));
	return in;
}



// Sound Stuff (Temporary)
void RendererBase::PrecacheSound(const std::string& name, const std::string& path)
{
	Mix_Chunk* ChunkyChunk = Mix_LoadWAV((Engine::BasePath+path).c_str());
	SoundRepository[name] = new SDLSoundWrapper(ChunkyChunk);
	SoundRepository[name]->Extras["Path"] = path;

}
void RendererBase::PrecacheMusic(const std::string& name, const std::string& path)
{
	Mix_Music* ChunkyChunk = Mix_LoadMUS((Engine::BasePath+path).c_str());

	MusicRepository[name] = new SDLMusicWrapper(ChunkyChunk);
	MusicRepository[name]->Extras["Path"] = path;
}

// TODO: Add validation
void RendererBase::PlaySound(const std::string& name, int channel, int loops)
{
	Mix_PlayChannel(channel, SoundRepository[name]->Data, loops);
}
void RendererBase::PlayMusic(const std::string& name)
{
	Mix_PlayMusic(MusicRepository[name]->Data, -1);
}
bool RendererBase::IsMusicPlaying()
{
	return !(bool)Mix_PausedMusic();
}
void RendererBase::ResumeMusic()
{
	Mix_ResumeMusic();
}
void RendererBase::PauseMusic()
{
	Mix_PauseMusic();
}
void RendererBase::StopMusic()
{
	Mix_HaltMusic();
}
