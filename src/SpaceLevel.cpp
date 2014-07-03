#include "SpaceLevel.h"

#include "Engine/Engine.h"
#include "Engine/Input.h"

#include "Player.h"
#include "TestEntity.h"

void SpaceLevel::Initialize(RendererBase* r)
{
	Super::Initialize(r);
	Spawn("Player", new Player(), Vector2(0, 0));
	Spawn("TestEntity", new TestEntity(), Vector2(200, 200));
}

void SpaceLevel::Render()
{
	SDL_Color c = {0, 0, 0};
	Renderer->RenderImage("Background", Vector2(0, 0));
	Renderer->RenderDrawRect(Vector2(0, 0), Vector2(Renderer->TexSizeRepository["Background"].x,
													Renderer->TexSizeRepository["Background"].y), c);

	Super::Render();
}

void SpaceLevel::EventHandler(SDL_Event* e)
{
	Super::EventHandler(e);
}
