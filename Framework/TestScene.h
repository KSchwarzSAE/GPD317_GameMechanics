#pragma once

#include "Scene.h"

class Texture;
class Font;
class Player;
class Enemy;
class Bedrock;
class Stone;

class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update(Uint32 _dt) override;
	virtual void render(Renderer* _pRenderer) override;

	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

private:
	Texture* m_pHello;
	Font* m_pFont;
	Player* m_pEntityPlayer;
	Enemy* m_pEntityEnemy;
	Bedrock* m_pEntityBedrock;
	Stone* m_pEntityStone;

	int groundPlaced = 0;
	int bedrocksPlaced = 0;
	int stonesPlaced = 0;

	bool playerExists = false;
	bool enemyExists = false;
};