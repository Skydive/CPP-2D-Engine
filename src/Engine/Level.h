#pragma once

#include "SDL2/SDL.h"

#include "LinkedList.h"
#include "Entity.h"


class Level
{
public:
	virtual ~Level();

	// Events
	virtual void Initialize(RendererBase* renderer);
	virtual void Cleanup();
	virtual void EventHandler(SDL_Event* e);
	virtual void Render();

	// Data
	RendererBase* Renderer;
	std::string LevelName;
	LinkedList<Entity*> EntityRepository;

	// Functions

	// Utility Functions
	Entity* Spawn(std::string name, Entity* entity);
	Entity* Spawn(Entity* entity);
	Entity* Spawn(Entity* entity, Vector2 position);
	Entity* Spawn(std::string ID, Entity* entity, Vector2 position);

	template<typename LoopF>
	void LoopEntsByID(std::string ID, LoopF &loopFunction);
};
