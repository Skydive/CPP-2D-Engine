#pragma once

#include "Vector2.h"
#include "RendererBase.h"

class Entity
{
public:
	// Events
	virtual void Initialize();
	virtual void Spawn();
	virtual void EventHandler(SDL_Event &e);
	virtual void Render();
	virtual void Tick();
	virtual void Input();
	virtual void DefaultProperties();
	virtual void Cleanup();

	// Control
	std::string ID;
	static int IDCount;

	virtual ~Entity();

	// Entity
	Vector2f position;
	Vector2f dimensions;
	double scale;
	double rotation;
	SDL_RendererFlip flip;

	void Delete();
	bool ToDelete;

	virtual bool IsColliding(Entity* collider);

	// Pointers
	RendererBase* Renderer;

	// Debug
	bool bDrawCollisions;
	void DrawCollisions();
};
