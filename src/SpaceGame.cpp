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
	Renderer->PrecacheTexture("Background", "/res/Background.png");
	Renderer->PrecacheTexture("ToiletMan", "/res/ToiletMan.png");
	Renderer->PrecacheFont("ArialSmall", "/res/arial.ttf", 15);
	Renderer->PrecacheMusic("FeintTowerOfHeaven", "/res/FormatFactoryFeint - Tower Of Heaven.mp3");
	Renderer->PrecacheSound("Thump","/res/Bounce.wav");
	Super::Precache();
}

void SpaceGame::Start()
{
	Renderer->PlayMusic("FeintTowerOfHeaven");
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
	Renderer->StopMusic();
	Super::Cleanup();
}

void SpaceGame::DefaultProperties()
{

}
