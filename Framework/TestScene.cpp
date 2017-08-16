#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Player.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Animation.h"
#include "UI.h"

#define CREATE_SPRITE_FROM_SHEET(SHEET, X, Y, W, H) new Sprite(SHEET, X * W, Y * H, W, H)

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
		m_pFirst->GetBounds().y += _dt / 5;
		m_pLinkMove->Update(_dt);
	}

	if (m_pSystem->IsKeyPressed(Key::D))
	{
		m_pFirst->GetBounds().x += _dt;
	}

	if (m_pSystem->WasKeyPressed(Key::RETURN))
	{
		Mix_PlayChannel(-1, m_pSwing, -1);
	}

	Scene::update(_dt);
}

void TestScene::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);
}

void TestScene::load(Renderer* _pRenderer)
{
	/*
	Texture* pEgg = new Texture(_pRenderer, getAssetPath("Images/egg.png").c_str());
	
	for (int i = 0; i < 100; ++i)
	{
		SDL_Rect boundsEgg;
		boundsEgg.w = 172;
		boundsEgg.h = 240;
		boundsEgg.x = RandomI(0, 628);
		boundsEgg.y = RandomI(0, 360);

		AddEntity(new Entity("Egg", pEgg, boundsEgg));
	}*/

	m_pSwing = Mix_LoadWAV(getAssetPath("Sounds/sword.wav").c_str());

	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12);

	Texture* pLink = new Texture(_pRenderer, getAssetPath("Images/link.png").c_str());

	FrameList linkMoveFrames;
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 0, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 1, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 2, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 3, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 4, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 5, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 6, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 7, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 8, 4, 120, 130), 50));
	linkMoveFrames.push_front(AnimationFrame(CREATE_SPRITE_FROM_SHEET(pLink, 9, 4, 120, 130), 50));
	m_pLinkMove = new Animation(linkMoveFrames);

	SDL_Rect boundsLink;
	boundsLink.x = 0;
	boundsLink.y = 0;
	boundsLink.w = 80;
	boundsLink.h = 80;

	AddEntity(m_pFirst = new Player("Player", m_pLinkMove, boundsLink));

	m_pFirst->m_allowBounds.x = 0;
	m_pFirst->m_allowBounds.y = 0;
	m_pFirst->m_allowBounds.w = 800;
	m_pFirst->m_allowBounds.h = 600;

	m_pUI = new UI();

	SDL_Color col;
	col.a = 255;
	col.r = 255;
	col.g = 255;
	col.b = 255;
	Label* pLabel = new Label(m_pFont, "Hello World", col);
	pLabel->m_bounds.x = 5;
	pLabel->m_bounds.y = 15;

	m_pUI->Add(pLabel);
}

void TestScene::unload()
{
	if (m_pSwing)
	{
		Mix_FreeChunk(m_pSwing);
		m_pSwing = nullptr;
	}

	SAFE_DELETE(m_pFont);
}
