/*
 * RendererOpenGL.h
 * Purpose: Why not add an OpenGL renderer?
 *  Created on: 7 Mar 2014
 *      Author: Khalid
 */
#pragma once

#include "RendererBase.h"

#include <map>

#include "GL/glew.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "ResourceWrapper.h"
CreateFakeWrapper(GLTextureWrapper, ResourceWrapper<GLuint>);

class RendererOpenGL: public RendererBase
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
private:
	//Vector2 VectorToRenderVector(Vector2 in) override;
	typedef RendererBase Super;
	SDL_Window* GameWindow;
	SDL_Renderer* UtilityRenderer;
	SDL_GLContext GLContext;

	std::map<std::string, GLTextureWrapper*> GLTextureRepository;
};

