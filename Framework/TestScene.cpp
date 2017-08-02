#include "TestScene.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}


void TestScene::render()
{
	
}

void TestScene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
	LOAD_OPTIMIZED_IMAGE("D://link.png", m_pLink);
}

void TestScene::unload()
{
	if (m_pLink)
	{
		SDL_FreeSurface(m_pLink);
		m_pLink = nullptr;
	}
}
