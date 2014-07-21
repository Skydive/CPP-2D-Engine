#include "Player.h"
#include <stdio.h>
#include <math.h>

#include "Engine/Input.h"
#include "Engine/Engine.h"

///TODO: Rotary collisions

void Player::Spawn()
{
	// Move to centre
	position.x = (int)floor((Engine::Properties.Width/2)-(dimensions.x/2));
	position.y = (int)floor((Engine::Properties.Height/2)-(dimensions.y/2));
}

void Player::Initialize()
{
	Super::Initialize();
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
	if(SoundController->IsMusicPlaying())
		SoundController->StopMusic();
	SoundController->PlaySound("Thump", -1, 0);
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
	/// TODO: Resolve -position issue.
	Renderer->SetRenderView(position);

	Super::Render();

	Renderer->RenderFont("I am a man", "ArialSmall", position.ToInteger()-Vector2(0, 10), {0, 0, 0});
}


void Player::DefaultProperties()
{
	Super::DefaultProperties();
	Vector2f CentrePosition = Vector2f(Engine::Properties.Width/2, Engine::Properties.Height/2);
	position = Renderer->LocalToWorldVector(CentrePosition.ToInteger());

	velocity = Vector2f(0, 0);




	Texture = "ToiletMan";
	TexturePath = "/res/ToiletMan.png";
	dimensions = Vector2f(40, 40);
	flip = SDL_FLIP_NONE;
	rotation = 0;
	scale = 0.25;
}
