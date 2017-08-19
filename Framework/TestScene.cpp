#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Renderer.h"
#include "Texture.h"
#include "Font.h"
#include "Player.h"
#include "Enemy.h"
#include "Bedrock.h"
#include "Stone.h"

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
		m_pEntityPlayer->GetBounds().y -= _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::A))
	{
		m_pEntityPlayer->GetBounds().x -= _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::S))
	{
		m_pEntityPlayer->GetBounds().y += _dt;
	}

	if (m_pSystem->IsKeyPressed(Key::D))
	{
		m_pEntityPlayer->GetBounds().x += _dt;
	}
	// m_pEntityEnemy->Kill();

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
	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12);
	m_pHello = m_pFont->Create("Hello World", _pRenderer);

	// Textures laden
	Texture* pLink = new Texture(_pRenderer, getAssetPath("Images/link.png").c_str());
	Texture* pPlayer = new Texture(_pRenderer, getAssetPath("Images/player00.png").c_str());
	Texture* pEnemy = new Texture(_pRenderer, getAssetPath("Images/enemy00.png").c_str());
	Texture* pGem = new Texture(_pRenderer, getAssetPath("Images/gem.png").c_str());
	Texture* pBomb = new Texture(_pRenderer, getAssetPath("Images/bomb00.png").c_str());
	Texture* pStone = new Texture(_pRenderer, getAssetPath("Images/stone01.png").c_str());
	Texture* pBedrock = new Texture(_pRenderer, getAssetPath("Images/stone00.png").c_str());

	// Bounds setzen
	SDL_Rect boundsCharacters;
	boundsCharacters.x = 0;
	boundsCharacters.y = 0;
	boundsCharacters.w = 72;
	boundsCharacters.h = 72;

	SDL_Rect boundsEnvironment;
	boundsEnvironment.x = 0;
	boundsEnvironment.y = 0;
	boundsEnvironment.w = 80;
	boundsEnvironment.h = 80;

	// Entitys laden
	AddEntity(m_pEntityPlayer = new Player("Player", pPlayer, boundsCharacters));
	AddEntity(m_pEntityEnemy = new Enemy("Enemy", pEnemy, boundsCharacters));

	m_pEntityEnemy->GetBounds().x = 720;
	m_pEntityEnemy->GetBounds().y = 720;


	// "Allowed"Bounds setzen (Rahmen)
	m_pEntityPlayer->m_allowBounds.x = 0;
	m_pEntityPlayer->m_allowBounds.y = 0;
	m_pEntityPlayer->m_allowBounds.w = 800;
	m_pEntityPlayer->m_allowBounds.h = 800;

	int playerPos = RandomI(0, 17);
	int enemyPos = RandomI(17, 33);

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			int entityId = RandomI(0, 3);

			switch (entityId)
			{
			case 0:	// Ground-------------------------------------------------------
				if (groundPlaced <= 32)
				{
					// Ground or Characters
					
				}
				if (groundPlaced > 32)
				{
					int altId = RandomI(0, 2);

					switch (altId)
					{
					case 0:	// try Bedrock
						if (bedrocksPlaced <= 33)
						{
							AddEntity(m_pEntityBedrock = new Bedrock("Bedrock", pBedrock, boundsEnvironment));
							m_pEntityBedrock->GetBounds().x = x * 80;
							m_pEntityBedrock->GetBounds().y = y * 80;
							bedrocksPlaced++;
						}
						if (bedrocksPlaced > 33)
						{
							AddEntity(m_pEntityStone = new Stone("Stone", pStone, boundsEnvironment));
							m_pEntityStone->GetBounds().x = x * 80;
							m_pEntityStone->GetBounds().y = y * 80;
							stonesPlaced++;
						}
						break;

					case 1:	// Try Stone
						if (stonesPlaced <= 33)
						{
							AddEntity(m_pEntityStone = new Stone("Stone", pStone, boundsEnvironment));
							m_pEntityStone->GetBounds().x = x * 80;
							m_pEntityStone->GetBounds().y = y * 80;
							stonesPlaced++;
						}
						if (stonesPlaced > 33)
						{
							AddEntity(m_pEntityBedrock = new Bedrock("Bedrock", pBedrock, boundsEnvironment));
							m_pEntityBedrock->GetBounds().x = x * 80;
							m_pEntityBedrock->GetBounds().y = y * 80;
							bedrocksPlaced++;
						}
						break;

					default:
						break;
					}
				}
				break;
				
			case 1:	// Bedrock------------------------------------------------------
				if (bedrocksPlaced <= 33)
				{
					AddEntity(m_pEntityBedrock = new Bedrock("Bedrock", pBedrock, boundsEnvironment));
					m_pEntityBedrock->GetBounds().x = x * 80;
					m_pEntityBedrock->GetBounds().y = y * 80;
					bedrocksPlaced++;
				}
				if (bedrocksPlaced > 33)
				{
					int altId = RandomI(0, 2);

					switch (altId)
					{
					case 0:	// try Ground
						if (groundPlaced <= 32)
						{
							// Ground or Characters
							
						}
						if (groundPlaced > 32)
						{
							AddEntity(m_pEntityStone = new Stone("Stone", pStone, boundsEnvironment));
							m_pEntityStone->GetBounds().x = x * 80;
							m_pEntityStone->GetBounds().y = y * 80;
							stonesPlaced++;
						}
						break;

					case 1:	// Try Stone
						if (stonesPlaced <= 33)
						{
							AddEntity(m_pEntityStone = new Stone("Stone", pStone, boundsEnvironment));
							m_pEntityStone->GetBounds().x = x * 80;
							m_pEntityStone->GetBounds().y = y * 80;
							stonesPlaced++;
						}
						if (stonesPlaced > 33)
						{
							// Ground or Characters
							
						}
						break;

					default:
						break;
					}
				}
				break;

			case 2: // Stone--------------------------------------------------------
				if (stonesPlaced <= 33)
				{
					AddEntity(m_pEntityStone = new Stone("Stone", pStone, boundsEnvironment));
					m_pEntityStone->GetBounds().x = x * 80;
					m_pEntityStone->GetBounds().y = y * 80;
					stonesPlaced++;
				}
				if (stonesPlaced > 33)
				{
					int altId = RandomI(0, 2);

					switch (altId)
					{
					case 0:	// try Ground
						if (groundPlaced <= 32)
						{
							// Ground or Characters
							
						}
						if (groundPlaced > 32)
						{
							AddEntity(m_pEntityBedrock = new Bedrock("Bedrock", pBedrock, boundsEnvironment));
							m_pEntityBedrock->GetBounds().x = x * 80;
							m_pEntityBedrock->GetBounds().y = y * 80;
							bedrocksPlaced++;
						}
						break;

					case 1:	// try Bedrock
						if (bedrocksPlaced <= 33)
						{
							AddEntity(m_pEntityBedrock = new Bedrock("Bedrock", pBedrock, boundsEnvironment));
							m_pEntityBedrock->GetBounds().x = x * 80;
							m_pEntityBedrock->GetBounds().y = y * 80;
							bedrocksPlaced++;
						}
						if (bedrocksPlaced > 33)
						{
							// Ground or Characters
							
						}
						break;

					default:
						break;
					}
				}
				break;

			default:
				break;
			}
		}
	}


}

void TestScene::unload()
{
	SAFE_DELETE(m_pHello);
	SAFE_DELETE(m_pFont);
}
