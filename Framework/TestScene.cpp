#include "TestScene.h"
#include "System.h"

TestScene::TestScene(System* _pSystem)
	: Scene(_pSystem)
{
	m_pLinkPos = new SDL_Rect();
	m_pLinkPos->x = 0;
	m_pLinkPos->y = 0;
	m_pLinkPos->w = 30;
	m_pLinkPos->h = 60;
}

TestScene::~TestScene()
{
	delete m_pLinkPos;
}

void TestScene::update()
{
	m_pLinkPos->y++;

	if (m_pSystem->WasKeyPressed(Key::W))
	{
		m_pLinkPos->y -= 150;
	}

	if (m_pSystem->IsKeyPressed(Key::A))
	{
		m_pLinkPos->x -= 1;
	}

	if (m_pSystem->IsKeyPressed(Key::D))
	{
		m_pLinkPos->x += 1;
	}

	if (m_pLinkPos->y >= 540)
		m_pLinkPos->y = 540;
}

void TestScene::render(SDL_Surface* _pSurface)
{
	SDL_BlitScaled(m_pLink, 0, _pSurface, m_pLinkPos);
}

void TestScene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
	LOAD_OPTIMIZED_IMAGE("Images/link.png", m_pLink);
}

void TestScene::unload()
{
	if (m_pLink)
	{
		SDL_FreeSurface(m_pLink);
		m_pLink = nullptr;
	}
}
