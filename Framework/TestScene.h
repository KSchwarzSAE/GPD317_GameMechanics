#pragma once

#include "Scene.h"

class Player;
class Font;

class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update(Uint32 _dt) override;
	virtual void render(SDL_Surface* _pSurface) override;

	virtual void load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask) override;
	virtual void unload() override;

private:
	Font* m_pFont;
	Player* m_pFirst;
};