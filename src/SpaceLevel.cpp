#include "SpaceLevel.h"

#include "Engine/Engine.h"
#include "Engine/Input.h"

#include "Player.h"
#include "TestEntity.h"

void SpaceLevel::Initialize(RendererBase* r, SoundManager* soundcontroller)
{
	Super::Initialize(r, soundcontroller);
	Spawn("Player", new Player(), Vector2(0, 0));
	for(int i=1; i<Renderer->TexSizeRepository["Background"].x; i+=100)
	{
		Spawn("TestEntity", new TestEntity(), Vector2(i, 200));
	}




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
