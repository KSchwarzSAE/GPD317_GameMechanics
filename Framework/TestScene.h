#pragma once

#include "Scene.h"

class Player;
class Font;
class Texture;

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
	Player* m_pFirst;
};