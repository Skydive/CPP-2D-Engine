#pragma once

#include <map>
#include <string>

#include "ResourceWrapper.h"
#include "RendererBase.h"

class ResourceManager
{
	// Texture Management
public:
	void PrecacheTexture(RendererBase* renderer, const std::string& name, const std::string& path);
	void Cleanup();
};
