#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Player.h"
#include "Font.h"

TestScene::TestScene(System* _pSystem)
	: Scene(_pSystem)
{
}

TestScene::~TestScene()
{

}

void TestScene::update(Uint32 _dt)
{
	if (m_pSystem->IsKeyPressed(Key::W))
	{
		m_pFirst->GetBounds().y -= _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::A))
	{
		m_pFirst->GetBounds().x -= _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::S))
	{
		m_pFirst->GetBounds().y += _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::D))
	{
		m_pFirst->GetBounds().x += _dt;
	}

	Scene::update(_dt);
}

void TestScene::render(SDL_Surface* _pSurface)
{
	Scene::render(_pSurface);

	m_pFont->Render("Hello World", _pSurface, SDL_Point());
}

void TestScene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12);

	SDL_Surface* pLink;
	LOAD_OPTIMIZED_IMAGE("Images/link.png", pLink);

	SDL_Rect boundsLink;
	boundsLink.x = 0;
	boundsLink.y = 0;
	boundsLink.w = 80;
	boundsLink.h = 80;

	AddEntity(m_pFirst = new Player("Player", pLink, boundsLink));

	m_pFirst->m_allowBounds.x = 0;
	m_pFirst->m_allowBounds.y = 0;
	m_pFirst->m_allowBounds.w = 800;
	m_pFirst->m_allowBounds.h = 600;
}

void TestScene::unload()
{
	if (m_pFont)
	{
		delete m_pFont;
		m_pFont = nullptr;
	}
}
