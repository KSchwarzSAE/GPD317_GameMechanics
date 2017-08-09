#include "TestScene.h"
#include "System.h"
#include "Entity.h"

TestScene::TestScene(System* _pSystem)
	: Scene(_pSystem)
{
}

TestScene::~TestScene()
{

}

void TestScene::update()
{
	if (m_pSystem->IsKeyPressed(Key::W))
	{
		m_offset.y -= 1;
	}

	if (m_pSystem->IsKeyPressed(Key::A))
	{
		m_offset.x -= 1;
	}

	if (m_pSystem->IsKeyPressed(Key::S))
	{
		m_offset.y += 1;
	}

	if (m_pSystem->IsKeyPressed(Key::D))
	{
		m_offset.x += 1;
	}

}

void TestScene::render(SDL_Surface* _pSurface)
{
	Scene::render(_pSurface);
}

void TestScene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
	LOAD_OPTIMIZED_IMAGE("Images/link.png", m_pLink);

	SDL_Rect boundsLink;
	boundsLink.x = 0;
	boundsLink.y = 0;
	boundsLink.w = 30;
	boundsLink.h = 60;

	AddEntity(new Entity("Link", m_pLink, boundsLink));
}

void TestScene::unload()
{
	if (m_pLink)
	{
		SDL_FreeSurface(m_pLink);
		m_pLink = nullptr;
	}
}
