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
	Resources.PrecacheTexture(Renderer, "Background", "./res/Background.png");
	Resources.PrecacheTexture(Renderer, "ToiletMan", "./res/ToiletMan.png");
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
