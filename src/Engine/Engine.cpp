#include "Engine.h"

#include "RendererSDL.h"
#include "RendererOpenGL.h"
#include "Input.h"

/// TODO: URGENT. ADD FPS AND DELTATIME!
// Static Variables
States Engine::State = States();
GameProperties Engine::Properties = GameProperties();

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
	State.Paused = false;
	State.Quit = false;
	Properties = props;

	Resources = ResourceManager();
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
}


void Engine::DefaultProperties()
{

}

Engine::~Engine(){}
