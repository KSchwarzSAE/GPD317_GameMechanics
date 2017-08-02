#include "System.h"
#include "Scene.h"
#include "common.h"

#include <iostream>

#define HANDLE_ERROR(CHECK)							\
if(CHECK)											\
{													\
	std::cout << SDL_GetError() << std::endl;		\
	return false;									\
}													\

System::System()
{
	m_pWindow = nullptr;
	m_pWindowSurface = nullptr;
}

bool System::init()
{
	// SDL Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	HANDLE_ERROR(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0);
	
	// Image Plugin Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	HANDLE_ERROR(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0);

	m_pWindow = SDL_CreateWindow(
		"Hello SDL World!",		// Titel des Fensters
		SDL_WINDOWPOS_CENTERED,	// Fenster Horizontal Zentrieren
		SDL_WINDOWPOS_CENTERED, // Fenster Vertikal Zentrieren
		800,					// Breite
		600,					// Hoehe
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE		// Extra Flags
		);

	HANDLE_ERROR(m_pWindow == nullptr);

	// Zeichenflaeche des Fensters holen
	m_pWindowSurface = SDL_GetWindowSurface(m_pWindow);

	HANDLE_ERROR(m_pWindowSurface == nullptr);

	// fertig initialisiert
	return true;
}

bool System::load()
{
	return true;
}

void System::run()
{
	// solange nicht gestoppt werden soll, wird die schleife laufen
	while (!m_shouldStop && m_pScene)
	{
		input();
		update();
		render();
	}
}

void System::clean()
{
	if (m_pWindow)
	{
		SDL_DestroyWindow(m_pWindow);
		m_pWindow = nullptr;
	}

	// SDL stoppen und aufraeumen
	SDL_Quit();
}

void System::changeScene(Scene* _pNewScene)
{
	if(m_pScene) m_pScene->unload();
	m_pScene = _pNewScene;
	if (m_pScene)
	{
		m_pScene->load(
			m_pWindowSurface->format->Rmask,
			m_pWindowSurface->format->Bmask,
			m_pWindowSurface->format->Gmask,
			m_pWindowSurface->format->Amask
			);
	}
}

void System::render()
{
	// das bild mit blau clearen
	SDL_FillRect(
		m_pWindowSurface,
		0,
		SDL_MapRGB(m_pWindowSurface->format, 0, 0, 255)
		);

	// die scene rendern
	m_pScene->render();

	// geaenderte fenster oberflaeche an die graka schicken zur anzeige
	SDL_UpdateWindowSurface(m_pWindow);
}

void System::update()
{
	m_pScene->update();
}

void System::input()
{
	// alle events in der pipeline abarbeiten
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		// anhand des event types entscheiden was gemacht werden soll
		switch (e.type)
		{
			// bei einem quit event das flag zum beenden setzten
			case SDL_EventType::SDL_QUIT:
				m_shouldStop = true;
				break;
		}
	}
}