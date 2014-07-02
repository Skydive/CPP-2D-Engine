/*
 * RendererOpenGL.cpp
 *
 *  Created on: 7 Mar 2014
 *      Author: Khalid
 */
#include "RendererOpenGL.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "SDL2/SDL_opengl.h"

#include "Engine.h"

void RendererOpenGL::Initialize()
{
	//Use OpenGL 2.1
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	GameWindow = SDL_CreateWindow(Engine::Properties.Name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Engine::Properties.Width, Engine::Properties.Height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(GameWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); return;
	}

	UtilityRenderer = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(UtilityRenderer == nullptr)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	GLContext = SDL_GL_CreateContext(GameWindow);
	if(GLContext == NULL)
	{
		printf("OpenGL context creation failed!"); return;
	}

	if(SDL_GL_SetSwapInterval(1) < 0)
	{
		printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
	}

	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString( error )); return;
	}

	GLenum state = glewInit();
	if(state != GLEW_OK)
	{
		printf("Error initializing OpenGL GLEW!\n"); return;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0f, Engine::Properties.Width, Engine::Properties.Height, 0.0f, -1.0f, 1.0f);


	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
}

void RendererOpenGL::PrecacheTexture(const std::string& name, const std::string& path)
{

	//ATTN: GET THIS WORKING
}

void RendererOpenGL::RenderImage(const char* textureID, Vector2 position)
{
	std::string ID = std::string(textureID);
	int width = GLTextureRepository[ID]->Extrai["Width"];
	int height = GLTextureRepository[ID]->Extrai["Height"];

	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.f);

	glBindTexture(GL_TEXTURE_2D, 0);

	//Render textured quad
	glBegin(GL_QUADS);
		glTexCoord2f(    0,    0.f); glVertex2f(    0,      0);
		glTexCoord2f(width,    0.f); glVertex2f(width,      0);
		glTexCoord2f(width, height); glVertex2f(width, height);
		glTexCoord2f(    0, height); glVertex2f(    0, height);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);


	printf("%d %d\n", (int)width, (int)height);
}

void RendererOpenGL::RenderImage(const char* textureID, Vector2 position, double scale, double rotation, SDL_RendererFlip flip)
{
	this->RenderImage(textureID, position);
}


void RendererOpenGL::RenderDrawRect(Vector2 position, Vector2 dimensions, SDL_Color color)
{
	glLoadIdentity();
	glLineWidth(1.5);
	glTranslatef(position.x, position.y, 0.0f);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_LINES);
		glVertex2d(			  0, 			  0);
		glVertex2d(dimensions.x,			  0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2d(			  0,           	    dimensions.y);
		glVertex2d(dimensions.x,   dimensions.x+dimensions.y);
	glEnd();
	/*
	glBegin(GL_LINES)
		glVertex2d(			  0,			  dimensions.y);
		glVertex2d(dimensions.x, dimensions.x+dimensions.y);
	glEnd();
	glBegin(GL_LINES)
		glVertex2d(			  0, dimensions.x+dimensions.y);
	glEnd();*/
}

void RendererOpenGL::RenderFillRect(Vector2 position, Vector2 dimensions, SDL_Color color)
{
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_QUADS);
		glVertex2d(0, dimensions.y);
		glVertex2d(dimensions.x, dimensions.y);
		glVertex2d(dimensions.x, 0);
		glVertex2d(0, 0);
	glEnd();
}

void RendererOpenGL::RenderPresent()
{
	SDL_GL_SwapWindow(GameWindow);
}

void RendererOpenGL::RenderClear()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set Black Background
	glClear(GL_COLOR_BUFFER_BIT); //Clear color buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// Reset current matrix (Modelview)
}

void RendererOpenGL::Cleanup()
{
	SDL_GL_DeleteContext(GLContext);
	for(auto iter = GLTextureRepository.begin(); iter != GLTextureRepository.end(); iter++)
	{
		iter->second->Data = 0;
		delete iter->second;
		iter->second = nullptr;
	}
	SDL_DestroyRenderer(UtilityRenderer);
	SDL_DestroyWindow(GameWindow);
	printf("Renderer Destroyed");
}
