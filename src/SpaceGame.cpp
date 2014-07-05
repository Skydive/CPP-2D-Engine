/*
 * Brickbreaker.cpp
 *
 *  Created on: 6 Mar 2014
 *      Author: Khalid
 */

#include <stdio.h>
#include "SpaceGame.h"
#include "SpaceLevel.h"

void SpaceGame::Precache()
{
	//TODO: Remove resource manager
	Renderer->PrecacheTexture("Background", "./res/Background.png");
	Renderer->PrecacheTexture("ToiletMan", "./res/ToiletMan.png");

	// Why doesn't this work with local directories from the debugger? Hmm.
	// Just use windows fonts for now.
	Renderer->PrecacheFont("ArialSmall", "C:/Windows/Fonts/arial.ttf", 15);

	Super::Precache();
}

void SpaceGame::Start()
{
	printf("Space Game Started!\n");
	CurrentLevel = new SpaceLevel();
	CurrentLevel->Initialize(Renderer);
	Super::Start();
}

void SpaceGame::Tick()
{
	Super::Tick();
}

void SpaceGame::EventHandler(SDL_Event& e)
{
	Super::EventHandler(e);
}

void SpaceGame::Render()
{
	Super::Render();
}

void SpaceGame::Initialize(GameProperties props)
{
	Super::Initialize(props);
}

void SpaceGame::GameLoop()
{
	Super::GameLoop();
}

void SpaceGame::Cleanup()
{
	Super::Cleanup();
}

void SpaceGame::DefaultProperties()
{

}
