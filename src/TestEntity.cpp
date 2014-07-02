#include "TestEntity.h"

#include "Engine\input.h"

void TestEntity::Render()
{
	SDL_Color c = {0, 255, 255};
	Renderer->RenderFillRect(position, Vector2(100, 100), c);
}

void TestEntity::Input()
{
	if(Input::GetKey(SDL_SCANCODE_UP))
	{
		position.y -= 1;
	}
	else if(Input::GetKey(SDL_SCANCODE_DOWN))
	{
		position.y += 1;
	}

	if(Input::GetKey(SDL_SCANCODE_LEFT))
	{
		position.x -= 1;
	}
	else if(Input::GetKey(SDL_SCANCODE_RIGHT))
	{
		position.x += 1;
	}
}
