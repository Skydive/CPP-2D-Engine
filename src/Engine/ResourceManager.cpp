#include "ResourceManager.h"

#include "SDL2\SDL_image.h"

#include <stdlib.h>
#include <stdio.h>



void ResourceManager::PrecacheTexture(RendererBase* renderer, const std::string& name, const std::string& path)
{
	renderer->PrecacheTexture(name, path);
}

void ResourceManager::Cleanup(){}
