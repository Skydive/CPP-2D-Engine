#pragma once

#include "Engine/Entity.h"
#include "Engine/LinkedList.h"

class TestEntity : public Entity
{
public:
	void Render();
	void Input();
	void Tick();

	void DefaultProperties() override;
	Vector2f velocity;
};
