#include "TestEntity.h"

#include "Engine/Input.h"

#include <iostream>

void TestEntity::Render()
{
	SDL_Color c = {0, 255, 255};
	Renderer->RenderFillRect(position, dimensions, c);
	Renderer->RenderFont("I am a box", "ArialSmall", position.ToInteger()+Vector2(0, (int)dimensions.y), c);
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

void TestEntity::DefaultProperties()
{
	std::cout << "Linked list test from: TestEntity::DefaultProperties" << std::endl;

	LinkedList<int> LinkyLink = LinkedList<int>();
	LinkyLink.push_back(1);
	LinkyLink.push_back(100);
	LinkyLink.push_back(1000);
	LinkyLink.push_back(10000);
	LinkyLink.push_front(0);
	LinkedNode<int>* A = LinkyLink.push_back(5);
	LinkyLink.set_head(A);

	LinkyLink.iterate([&] (int value)
	{
		std::cout << value << std::endl;
	});

	dimensions = Vector2(100, 100);
}
