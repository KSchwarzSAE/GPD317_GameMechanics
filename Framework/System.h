#pragma once

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

private:
	void render();
	void update();
	void input();

private:
	SDL_Window* m_pWindow;
	SDL_Surface* m_pWindowSurface;
	Scene* m_pScene;

	bool m_shouldStop;

};