#include <stdio.h>
#include <algorithm>


#include <windows.h>

#include "Engine.h"
#include "RendererSDL.h"
#include "RendererOpenGL.h"
#include "Input.h"
#include "Globals.h"

///TODO: Platform independent basepath location.
///TODO: ADD FPS AND DELTATIME!
///TODO: Fix Tick. (Make it an ACTUAL tick rather than being called when render is) {TICK IS A LIE}
///TODO: Implement pausing

// Static Variables
States Engine::State = States();
GameProperties Engine::Properties = GameProperties();
std::string Engine::BasePath = std::string();

Engine::~Engine(){}

void Engine::Start(){}
void Engine::Tick(){}
void Engine::EventHandler(SDL_Event& e){}
void Engine::Precache(){}


void Engine::BaseEventHandler(SDL_Event &e)
{
	switch(e.type)
	{
		case SDL_QUIT:
			State.Quit = true;
			break;
		case SDL_KEYUP:
			if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				SDL_ShowCursor(!SDL_ShowCursor(-1));
			break;
	}
}

void Engine::Initialize(GameProperties props)
{
	// Store the base path. (Eww. Windows API calls)
	using namespace std;
	char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    string path = string( buffer ).substr( 0, pos);
    replace( path.begin(), path.end(), '\\', '/');
	Engine::BasePath = path;

	this->LaunchMessage();

	State.Paused = false;
	State.Quit = false;
	Properties = props;

	SoundController = new SoundManager();
	Renderer = new RendererSDL();
	//Renderer = new RendererOpenGL();

	if(SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); return;
	}

	Renderer->Initialize();

	DefaultProperties();

	Precache();

	Start();

	GameLoop();

	Cleanup();

	SDL_Quit();
}

void Engine::Render()
{
	if(CurrentLevel != nullptr)
	{
		CurrentLevel->Render();
	}
}

void Engine::GameLoop()
{
    SDL_Event event;

	while(!State.Quit)
	{
		Input::Update();
		// Update Input Here
		while (SDL_PollEvent(&event))
		{
			Input::EventHandler(&event);
			BaseEventHandler(event);
			EventHandler(event);
			if(CurrentLevel != nullptr)
			{
				CurrentLevel->EventHandler(&event);
			}
		}

		Renderer->RenderClear();

		// Rendering
		Render();

		Renderer->RenderPresent();

	}
}

void Engine::Cleanup()
{
	if(CurrentLevel != nullptr)
	{
		CurrentLevel->Cleanup();
	}
	Renderer->Cleanup();

	delete Renderer;
	delete SoundController;
}


void Engine::DefaultProperties()
{

}


void Engine::LaunchMessage()
{
	printf("C++ 2D Engine Launched\n");
	printf("Version: %s\n", Global::ENGINE_VERSION.c_str());
	printf("Created By Khalid Aleem\n\n");
}
