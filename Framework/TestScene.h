#pragma once

#include "Scene.h"

class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update() override;
	virtual void render(SDL_Surface* _pSurface) override;

	virtual void load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask) override;
	virtual void unload() override;

private:
	SDL_Surface* m_pLink;

};