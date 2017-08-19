#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Player.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"
#include "Timer.h"
#include "Enemy.h"
#include "Level.h"
#include "Projectile.h"
#include <iostream>

System s2;


TestScene::TestScene(System* _pSystem)
	: Scene(_pSystem)
{
	m_FireDelay = 200;
	m_FireWaitingTime = 0;
}

TestScene::~TestScene()
{

}

void TestScene::update(Uint32 _dt)
{
	if (WinTimer.TicksTicked() >= 30000)
	{
		std::cout << "Kaffe Kevin sleepy, you win, now leave this place fool!" << std::endl;
		s2.clean();
	}


	m_FireWaitingTime += _dt;

#pragma region EnemySpawns

	if (SpawnKevin.TicksTicked() >= 100)
	{
		if (pKevin)
		{
			AddEntity(new Enemy("Kevin", pKevin, boundsKevin, EntityFlags::SHOULD_UPDATE));

			SpawnKevin.Restart();
		}

	}
	if (SpawnMattis.TicksTicked() >= 700)
	{
		if (pMattis)
		{
			AddEntity(new Enemy("Mattis", pMattis, boundsMattis, EntityFlags::SHOULD_UPDATE));

			SpawnMattis.Restart();
		}

	}
	if (SpawnPit.TicksTicked() >= 1000)
	{
		if (pPit)
		{
			AddEntity(new Enemy("Pit", pPit, boundsPit, EntityFlags::SHOULD_UPDATE));

			SpawnPit.Restart();
		}

	}
#pragma endregion

#pragma region Backgroundmovement
	m_pSpace1->GetBounds().y += _dt / 4;
	m_pSpace2->GetBounds().y += _dt / 4;

	if (m_pSpace1->GetBounds().y >= 600) {
		m_pSpace1->GetBounds().y = m_pSpace2->GetBounds().y - 1024;
	}

	if (m_pSpace2->GetBounds().y >= 600) {
		m_pSpace2->GetBounds().y = m_pSpace1->GetBounds().y - 1024;
	}
#pragma endregion

#pragma region Controlls
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

	if (m_pSystem->IsKeyPressed(Key::SPACE))
	{
		if (m_FireWaitingTime >= m_FireDelay)
		{
			
			boundsBeam.x = m_pFirst->GetBounds().x + 15;
			boundsBeam.y = m_pFirst->GetBounds().y - 50;
			boundsBeam.w = 80;
			boundsBeam.h = 80;

			AddEntity(m_pBeamObject = new Projectile("Beam", m_pBeam, boundsBeam));

			m_pBeamObject->m_allowBounds.x = 0;
			m_pBeamObject->m_allowBounds.y = 0;
			m_pBeamObject->m_allowBounds.w = 800;
			m_pBeamObject->m_allowBounds.h = 600;

			m_FireWaitingTime = 0;
		}


	}

#pragma endregion
	Scene::update(_dt);
}

void TestScene::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);

	
}

void TestScene::load(Renderer* _pRenderer)
{
	
#pragma region EnemySection
	//Enemy section

	boundsKevin.x = -50;
	boundsKevin.y = 200;
	boundsKevin.w = 200;
	boundsKevin.h = 200;

	
	boundsMattis.x = 0;
	boundsMattis.y = 100;
	boundsMattis.w = 100;
	boundsMattis.h = 100;

	
	boundsPit.x = 0;
	boundsPit.y = 100;
	boundsPit.w = 150;
	boundsPit.h = 150;

	pKevin = new Texture(_pRenderer, getAssetPath("Images/kevin.jpg").c_str());

	pMattis = new Texture(_pRenderer, getAssetPath("Images/mattis.jpg").c_str());
	pPit = new Texture(_pRenderer, getAssetPath("Images/pit.jpg").c_str());

	//AddEntity(new Enemy("Kevin", pKevin, boundsKevin, EntityFlags::SHOULD_UPDATE));
	//AddEntity(new Enemy("Mattis", pMattis, boundsMattis, EntityFlags::SHOULD_UPDATE));
	//AddEntity(new Enemy("Pit", pPit, boundsMattis, EntityFlags::SHOULD_UPDATE));

	SpawnPit.Start();
	SpawnKevin.Start();
	SpawnMattis.Start();

	WinTimer.Start();
#pragma endregion

#pragma region LevelSection
	pSpace = new Texture(_pRenderer, getAssetPath("Images/space.png").c_str());


	
	boundsBack1.w = 800;
	boundsBack1.h = 1024;
	boundsBack1.x = 0;
	boundsBack1.y = -424;

	
	boundsBack2.w = 800;
	boundsBack2.h = 1024;
	boundsBack2.x = 0;
	boundsBack2.y = -1448;

	AddEntity(m_pSpace1 = new Level("BackG1", pSpace, boundsBack1));
	AddEntity(m_pSpace2 = new Level("BackG1", pSpace, boundsBack2));
#pragma endregion

	m_pBeam = new Texture(_pRenderer, getAssetPath("Images/beam.png").c_str());
	m_pPlayer = new Texture(_pRenderer, getAssetPath("Images/Player.png").c_str());



	SDL_Rect boundsPlayer;
	boundsPlayer.x = 350;
	boundsPlayer.y = 600;
	boundsPlayer.w = 80;
	boundsPlayer.h = 80;



	AddEntity(m_pFirst = new Player("Player", m_pPlayer, boundsPlayer));

	m_pFirst->m_allowBounds.x = 0;
	m_pFirst->m_allowBounds.y = 0;
	m_pFirst->m_allowBounds.w = 800;
	m_pFirst->m_allowBounds.h = 600;
}

void TestScene::unload()
{
	SAFE_DELETE(m_pSpace1);
	SAFE_DELETE(m_pSpace2);
}
