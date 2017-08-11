#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Player.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"

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

void TestScene::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);

	SDL_Rect rect;
	rect.x = 5;
	rect.y = 15;
	rect.w = m_pHello->GetWidth();
	rect.h = m_pHello->GetHeight();
	_pRenderer->DrawTexture(m_pHello, rect);
}

void TestScene::load(Renderer* _pRenderer)
{
	Texture* pEgg = new Texture(_pRenderer, getAssetPath("Images/egg.png").c_str());

	for (int i = 0; i < 100; ++i)
	{
		SDL_Rect boundsEgg;
		boundsEgg.w = 172;
		boundsEgg.h = 240;
		boundsEgg.x = RandomI(0, 628);
		boundsEgg.y = RandomI(0, 360);

		AddEntity(new Entity("Egg", pEgg, boundsEgg));
	}

	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12);
	m_pHello = m_pFont->Create("Hello World", _pRenderer);

	Texture* pLink = new Texture(_pRenderer, getAssetPath("Images/link.png").c_str());

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
	SAFE_DELETE(m_pHello);
	SAFE_DELETE(m_pFont);
}
