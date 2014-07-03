#pragma once

#include <list>

#include "SDL2/SDL.h"

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
	std::list<Entity*> EntityRepository;

	// Functions
	Entity* Spawn(std::string name, Entity* entity);
	Entity* Spawn(Entity* entity);
	Entity* Spawn(Entity* entity, Vector2 position);
	Entity* Spawn(std::string ID, Entity* entity, Vector2 position);

	template<typename LoopF>
	void LoopEntsByID(std::string ID, LoopF &loopFunction);
};
