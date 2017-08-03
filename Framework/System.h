#pragma once

enum Key
{
	ESC = 0, W = 1, A = 2, S = 3, D = 4, COUNT = 5
};

class Scene;
class SDL_Window;
class SDL_Surface;

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

private:
	void render();
	void update();
	void input();

private:
	SDL_Window* m_pWindow;
	SDL_Surface* m_pWindowSurface;
	Scene* m_pScene;

	bool m_keyState[Key::COUNT];
	bool m_lastKeyState[Key::COUNT];
	bool m_shouldStop;

};