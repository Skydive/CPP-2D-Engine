#include "Level.h"
#include <sstream>
#include <stdio.h>
#include <algorithm>

Level::~Level(){}

void Level::Initialize(RendererBase* renderer)
{
	Renderer = renderer;
}

void Level::EventHandler(SDL_Event* e)
{
	EntityRepository.iterate([&] (Entity* ent)
	{
		if(ent != nullptr)
		{
			ent->EventHandler(*e);
		}
	});
}

void Level::Render()
{
	EntityRepository.iterate([&] (Entity* ent)
	{
		if(ent != nullptr)
		{
			ent->Input();
			ent->Tick();
			if(ent->Renderer != nullptr)
			{
				ent->Render();
			}
			if(ent->ToDelete)
			{
				delete ent;
				// TODO: Implement nodes being passed to the iterate method.
				//iter = EntityRepository.erase(iter);
				//continue;
				return;
			}
		}
	});
}

Entity* Level::Spawn(Entity* entity)
{
	 return this->Spawn(entity, Vector2(0, 0));
}

Entity* Level::Spawn(Entity* entity, Vector2 pos)
{
	std::stringstream ss;
	ss << "Entity" << Entity::IDCount;
	return this->Spawn(ss.str(), entity, pos);
}

Entity* Level::Spawn(std::string ID, Entity* s, Vector2 pos)
{
	printf("Spawned: %s\n", ID.c_str());
	s->Renderer = Renderer;
	Entity::IDCount++;
	s->ToDelete = false;
	s->position.x = pos.x;
	s->position.y = pos.y;
	s->ID = ID;

	EntityRepository.push_front(s);
	s->Initialize();
	s->DefaultProperties();
	s->Spawn();
	return s;
}

template<typename LoopF>
void Level::LoopEntsByID(std::string ID, LoopF &loopFunction)
{
	EntityRepository.iterate([&] (Entity* ent)
	{
		if(ent != nullptr)
		{
			std::string str(ent->ID); std::transform(str.begin(), str.end(), str.begin(), ::tolower);
			std::string sub(ID); std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
			if(str.find(sub) != std::string::npos)
			{
				loopFunction(*ent);
			}
		}
	});
	/*
	for(auto iter = EntityRepository.begin(); iter != EntityRepository.end(); iter++)
	{
		if(*iter != nullptr)
		{
			std::string str((*iter)->ID); std::transform(str.begin(), str.end(), str.begin(), ::tolower);
			std::string sub(ID); std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
			if(str.find(sub) != std::string::npos)
			{
				loopFunction(**iter);
			}
		}
	}
	*/
}

void Level::Cleanup()
{
	EntityRepository.iterate([&] (Entity* ent)
	{
		delete ent;
		//iter = EntityRepository.erase(iter);
		//(*iter) = nullptr;
	});
}
