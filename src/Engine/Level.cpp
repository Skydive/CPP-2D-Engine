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
	for(auto iter = EntityRepository.begin(); iter != EntityRepository.end(); iter++)
	{
		if((*iter) != nullptr)
		{
			//TODO: Reference or Pointer generalisation
			(*iter)->EventHandler(*e);
		}
	}
}

void Level::Render()
{
	for(auto iter = EntityRepository.begin(); iter != EntityRepository.end();)
	{
		if((*iter) != nullptr)
		{
			(*iter)->Input();
			(*iter)->Tick();
			if((*iter)->Renderer != nullptr)
			{
				(*iter)->Render();
			}
			if((*iter)->ToDelete)
			{
				delete (*iter);
				iter = EntityRepository.erase(iter);
				continue;
			}
		}
		iter++;
	}
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
}

void Level::Cleanup()
{
	for(auto iter = EntityRepository.begin(); iter != EntityRepository.end(); iter++)
	{
		delete (*iter);
		iter = EntityRepository.erase(iter);
		(*iter) = nullptr;
	}
}
