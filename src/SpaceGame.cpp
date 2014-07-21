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
	Renderer->PrecacheFont("ArialSmall", "/res/arial.ttf", 15);

	SoundController->PrecacheMusic("FeintTowerOfHeaven", "/res/FormatFactoryFeint - Tower Of Heaven.mp3");
	SoundController->PrecacheSound("Thump","/res/Bounce.wav");

	Super::Precache();
}

void SpaceGame::Start()
{
	SoundController->PlayMusic("FeintTowerOfHeaven");
	printf("Space Game Started!\n");
	CurrentLevel = new SpaceLevel();
	CurrentLevel->Initialize(Renderer, SoundController);
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
	SoundController->StopMusic();
	Super::Cleanup();
}

void SpaceGame::DefaultProperties()
{

}
