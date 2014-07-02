#include <stdio.h>
#include <windows.h>

#include "SDL2\SDL.h"

#include "SpaceGame.h"



int G(void *ptr)
{
	GameProperties props;
	props.Name = "Hello, World!";
	props.Height = 600;
	props.Width = 800;
	SpaceGame game = SpaceGame();
	game.Initialize(props);
	return 0;
}

int main( int argc, char* args[] )
{
	SDL_Thread* gameThread = SDL_CreateThread(G, "GameThread", NULL);
	SDL_WaitThread(gameThread, NULL);
	//system("PAUSE");

	return 0;
}
