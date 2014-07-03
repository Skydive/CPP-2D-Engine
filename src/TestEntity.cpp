#include "TestEntity.h"

#include "Engine/Input.h"

void TestEntity::Render()
{
	SDL_Color c = {0, 255, 255};
	Renderer->RenderFillRect(position, Vector2(100, 100), c);
}

void TestEntity::Tick()
{
	velocity = velocity * 0.8;

	Vector2 BackgroundDimensions = Renderer->TexSizeRepository["Background"];
	if(position.x <= 0)
	{
		velocity.x *= -1.0f;
		if(velocity.x < 0)
			velocity.x = 1.5f;
	}
	else if(position.x >= BackgroundDimensions.x - dimensions.x)
	{
		velocity.x *= -1.0f;
		if(velocity.x > 0)
			velocity.x = -1.5f;
	}
	if(position.y <= 0)
	{
		velocity.y *= -1.0f;
		if(velocity.y < 0)
			velocity.y = 1.5f;
	}
	else if(position.y >= BackgroundDimensions.y - dimensions.y)
	{
		velocity.y *= -1.0f;
		if(velocity.y > 0)
			velocity.y = -1.5f;
	}

	position.x += velocity.x;
	position.y += velocity.y;
}

void TestEntity::Input()
{
	if(Input::GetKey(SDL_SCANCODE_UP))
	{
		velocity.y -= 5;
	}
	else if(Input::GetKey(SDL_SCANCODE_DOWN))
	{
		velocity.y += 5;
	}

	if(Input::GetKey(SDL_SCANCODE_LEFT))
	{
		velocity.x -= 5;
	}
	else if(Input::GetKey(SDL_SCANCODE_RIGHT))
	{
		velocity.x += 5;
	}
}
