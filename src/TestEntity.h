#pragma once
#include "Engine/Entity.h"


class TestEntity : public Entity
{
public:
	void Render();
	void Input();
	void Tick() override;

	Vector2f velocity;
};
