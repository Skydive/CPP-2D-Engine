//TODO: Create a Sprite class. (Useful for image property handling and collision detection).

#include "Player.h"
#include <stdio.h>
#include <math.h>

#include "Engine/Input.h"
#include "Engine/Engine.h"

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
	if(position.x <= 0)
	{
		velocity.x *= -1.0f;
		if(velocity.x < 0)
			velocity.x = 1.5f;
		OnCollision();
	}
	else if(position.x >= BackgroundDimensions.x - dimensions.x)
	{
		velocity.x *= -1.0f;
		if(velocity.x > 0)
			velocity.x = -1.5f;
		OnCollision();
	}
	if(position.y <= 0)
	{
		velocity.y *= -1.0f;
		if(velocity.y < 0)
			velocity.y = 1.5f;
		OnCollision();
	}
	else if(position.y >= BackgroundDimensions.y - dimensions.y)
	{
		velocity.y *= -1.0f;
		if(velocity.y > 0)
			velocity.y = -1.5f;
		OnCollision();
	}


	position.x += velocity.x;
	position.y += velocity.y;
}

void Player::OnCollision()
{
	if(Renderer->IsMusicPlaying())
		Renderer->StopMusic();
	Renderer->PlaySound("Thump", -1, 0);
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

	// Make the camera follow the player.
	// -position to make the camera render at the players position. Dimensions used to make it centre in the middle of the player.
	// TODO: Fix stutter caused by Vector2 and Vector2f conversion
	// Why is it -position. TODO: Resolve this.
	Renderer->SetRenderView((-position.ToInteger())-(dimensions/2));

	Renderer->RenderImage("ToiletMan", position.ToInteger(), scale, rotation, flip);

	Renderer->RenderFont("I am a man", "ArialSmall", position.ToInteger()-Vector2(0, 10), {0, 0, 0});
}


void Player::DefaultProperties()
{
	Vector2f CentrePosition = Vector2f(Engine::Properties.Width/2, Engine::Properties.Height/2);
	position = Renderer->LocalToWorldVector(CentrePosition.ToInteger());
	flip = SDL_FLIP_NONE;
	rotation = 0;
	scale = 0.25;
	velocity = Vector2f(0, 0);
	dimensions = Vector2f(40, 40);
}
