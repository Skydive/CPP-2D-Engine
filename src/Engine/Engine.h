#pragma once
#include <string>
#include <stdio.h>

/// BOSS
// TODO: FIX THIS MESS

#include "SDL2/SDL.h"

#include "Level.h"
#include "ResourceManager.h"
#include "RendererBase.h"

// Struct to hold the desired size of the window, e.t.c.
struct GameProperties
{
	std::string Name;
	int Height;
	int Width;
};




// Struct to hold the boolean values
struct States
{
	bool Quit;
	bool Paused;
};

class Engine
{

public:
	virtual ~Engine();

	// Component Variables
	ResourceManager Resources;
	RendererBase* Renderer;

	// Base Functions
	virtual void Initialize(GameProperties props);
	void BaseEventHandler(SDL_Event& e);

	// Events
	virtual void Precache();
	virtual void Start();
	virtual void GameLoop();
	virtual void Tick();
	virtual void EventHandler(SDL_Event& e);
	virtual void Render();
	virtual void Cleanup();
	virtual void DefaultProperties();

	// Functions
	virtual void LaunchMessage();

	// Data
	static States State;
	static GameProperties Properties;

	// Game
	Level* CurrentLevel;
};
