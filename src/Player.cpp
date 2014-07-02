//TODO: Create a Sprite class. (Useful for image property handling and collision detection).

#include "Player.h"
#include <stdio.h>
#include <math.h>

#include "Engine\input.h"
#include "Engine\Engine.h"

void Player::Spawn()
{
	dimensions = Renderer->TexSizeRepository["ToiletMan"].ToFloat()*scale;

	// Move to centre
	position.x = (int)floor((Engine::Properties.Width/2)-(dimensions.x/2));
	position.y = (int)floor((Engine::Properties.Height/2)-(dimensions.y/2));
}

void Player::Tick()
{
	velocity = velocity * 0.95;

	Vector2 BackgroundDimensions = Renderer->TexSizeRepository["Background"];

	if(position.x <= Renderer->RenderView.x)
	{
		velocity.x *= -1.0f;
		if(velocity.x < 0)
			velocity.x = 1.5f;
	}
	else if(position.x >= (Renderer->RenderView.x+BackgroundDimensions.x - dimensions.x))
	{
		velocity.x *= -1.0f;
		if(velocity.x > 0)
			velocity.x = -1.5f;
	}
	if(position.y <= Renderer->RenderView.y)
	{
		velocity.y *= -1.0f;
		if(velocity.y < 0)
			velocity.y = 1.5f;
	}
	else if(position.y >= (Renderer->RenderView.y+BackgroundDimensions.y - dimensions.y))
	{
		velocity.y *= -1.0f;
		if(velocity.y > 0)
			velocity.y = -1.5f;
	}

	//position.x += velocity.x;
	//position.y += velocity.y;

	// Constrain the player in the zone
	Renderer->RenderView.x -= velocity.x;
	Renderer->RenderView.y -= velocity.y;
}

void Player::Input()
{
	float Acceleration = 0.5;
	if(Input::GetKey(SDL_SCANCODE_W))
	{
		velocity.x += Acceleration*sin(rotation*M_PI/180);
		velocity.y -= Acceleration*cos(rotation*M_PI/180);

	}
	else if(Input::GetKey(SDL_SCANCODE_S))
	{
		velocity.x -= Acceleration*sin(rotation*M_PI/180);
		velocity.y += Acceleration*cos(rotation*M_PI/180);
	}

	if(Input::GetKey(SDL_SCANCODE_A))
	{
		rotation -= 3.25;
	}
	else if(Input::GetKey(SDL_SCANCODE_D))
	{
		rotation += 3.25;
	}
}

void Player::Render()
{
	// Movement independent to render view
	Vector2f CentrePosition = position - Renderer->RenderView.ToFloat();
	Renderer->RenderImage("ToiletMan", CentrePosition.ToInteger(), scale, rotation, flip);
}


void Player::DefaultProperties()
{
	position = Vector2f(40, 40);
	flip = SDL_FLIP_NONE;
	rotation = 0;
	scale = 0.25;
	velocity = Vector2f(0, 0);
	dimensions = Vector2f(40, 40);
}
