#pragma once

#include "common.h"

enum Key
{
	ESC = 0, W = 1, A = 2, S = 3, D = 4, COUNT = 5
};

class Scene;
class DebugOverlay;
struct SDL_Window;
struct SDL_Surface;

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

private:
	void render();
	void update(Uint32 _dt);
	void input();

private:
	DebugOverlay* m_pDebug;
	SDL_Window* m_pWindow;
	SDL_Surface* m_pWindowSurface;
	Scene* m_pScene;

	bool m_keyState[Key::COUNT];
	bool m_lastKeyState[Key::COUNT];
	bool m_shouldStop;

	Uint32 m_tps;
	Uint32 m_fps;
	Uint32 m_desiredTPS;
	Uint32 m_desiredFPS;
};