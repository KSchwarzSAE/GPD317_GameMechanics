#pragma once

#include "common.h"

enum Key
{
	
	ESC = 0, W = 1, A = 2, S = 3, D = 4,  SPACE = 5, F3 = 6,  COUNT = 7
};

class Scene;
class DebugOverlay;
struct SDL_Window;
class Renderer;

class System
{

public:

	System();

	bool init();
	bool load();
	void run();
	void clean();

	void changeScene(Scene* _pNewScene);

	bool IsKeyPressed(Key _key) const;
	bool WasKeyPressed(Key _key) const;
	bool WasKeyReleased(Key _key) const;

	std::string GetFPS(bool _addDesired = false);
	std::string GetTPS(bool _addDesired = false);
	SDL_Window* m_pWindow;
	Renderer* m_pRenderer;

private:
	void render();
	void update(Uint32 _dt);
	void input();

private:
	DebugOverlay* m_pDebug;
	bool m_debugEnabled;
	Scene* m_pScene;

	bool m_keyState[Key::COUNT];
	bool m_lastKeyState[Key::COUNT];
	bool m_shouldStop;

	Uint32 m_tps;
	Uint32 m_fps;
	Uint32 m_desiredTPS;
	Uint32 m_desiredFPS;
};