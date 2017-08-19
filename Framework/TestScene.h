#pragma once
#include "Timer.h"
#include "Scene.h"
#include "Projectile.h"

class Player;
class Font;
class Texture;
class Level;
class Projectile;


class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update(Uint32 _dt) override;
	virtual void render(Renderer* _pRenderer) override;

	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

protected:
	Texture* m_pHello;
	Font* m_pFont;
	Player* m_pFirst;

	Level* m_pSpace1;
	Level* m_pSpace2;
	Texture* pSpace;
	SDL_Rect boundsBack1;
	SDL_Rect boundsBack2;

	
	Projectile* m_pBeamObject;
	Uint32 m_FireDelay;
	Uint32 m_FireWaitingTime;
	Texture* m_pBeam;
	Texture* m_pPlayer;
	SDL_Rect boundsBeam;

	Texture* pKevin;
	Texture* pMattis;
	Texture* pPit;
	Timer SpawnKevin;
	Timer SpawnMattis;
	Timer SpawnPit;
	SDL_Rect boundsKevin;
	SDL_Rect boundsMattis;
	SDL_Rect boundsPit;

	Timer WinTimer;

};