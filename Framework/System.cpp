#include "System.h"
#include "Scene.h"
#include "Timer.h"
#include "Font.h"
#include "DebugOverlay.h"
#include "Renderer.h"
#include "common.h"
#include "UI.h"

#include <iostream>

System::System()
{
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_pDebug = nullptr;
	m_desiredTPS = 30;
	m_desiredFPS = 60;
}

bool System::init()
{
	// SDL Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	HANDLE_ERROR(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0);
	
	// Image Plugin Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	HANDLE_ERROR(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0);

	// Fonts initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	HANDLE_ERROR(TTF_Init() < 0);

	HANDLE_ERROR(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0);

	m_pWindow = SDL_CreateWindow(
		"Hello SDL World!",		// Titel des Fensters
		SDL_WINDOWPOS_CENTERED,	// Fenster Horizontal Zentrieren
		SDL_WINDOWPOS_CENTERED, // Fenster Vertikal Zentrieren
		800,					// Breite
		600,					// Hoehe
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE		// Extra Flags
		);

	HANDLE_ERROR(m_pWindow == nullptr);

	// den renderer initialisieren
	m_pRenderer = new Renderer(m_pWindow);
	HANDLE_ERROR(!m_pRenderer->Valid());

	m_pDebug = new DebugOverlay(this, new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12));

	// fertig initialisiert
	return true;
}

bool System::load()
{
	return true;
}

void System::run()
{
	Timer tickCountTimer;
	Uint32 ticks = 0;
	Uint32 frames = 0;

	Timer tickTimer;
	Timer renderTimer;

	tickTimer.Start();
	renderTimer.Start();
	tickCountTimer.Start();

	// solange nicht gestoppt werden soll, wird die schleife laufen
	while (!m_shouldStop && m_pScene)
	{
		Uint32 dt = tickTimer.TicksTicked();
		if (dt >= (1000 / m_desiredTPS))
		{
			tickTimer.Restart();
			input();
			update(dt);
			ticks++;			
		}
		
		Uint32 df = renderTimer.TicksTicked();
		if (df >= (1000 / m_desiredFPS))
		{
			renderTimer.Restart();
			render();
			frames++;
		}

		if (tickCountTimer.TicksTicked() > 1000)
		{
			m_fps = frames;
			m_tps = ticks;
			ticks = 0;
			frames = 0;
			tickCountTimer.Restart();
		}
	}
}

void System::clean()
{
	if (m_pRenderer)
	{
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

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
		m_pScene->load(m_pRenderer);
	}
}

bool System::IsKeyPressed(Key _key) const
{
	return m_keyState[_key];
}

bool System::WasKeyPressed(Key _key) const
{
	return !m_lastKeyState[_key] && m_keyState[_key];
}

bool System::WasKeyReleased(Key _key) const
{
	return m_lastKeyState[_key] && !m_keyState[_key];
}

void System::render()
{
	// das bild clearen
	m_pRenderer->BeginFrame();

	// die scene rendern
	m_pScene->render(m_pRenderer);

	if (m_debugEnabled)
	{
		// das debug overlay anzeigen
		m_pDebug->Render(m_pRenderer);
	}

	// geaenderte fenster oberflaeche an die graka schicken zur anzeige
	m_pRenderer->FinishFrame();
}

void System::update(Uint32 _dt)
{
	m_pScene->update(_dt);

	if (WasKeyPressed(Key::F3))
	{
		m_debugEnabled = !m_debugEnabled;
	}
}

#define HANDLE_KEYCODE(CODE, KEY, BOOL) case CODE: m_keyState[KEY] = BOOL; break;
#define HANDLE_KEY(KEY, BOOL) HANDLE_KEYCODE(SDL_SCANCODE_##KEY, Key::##KEY, BOOL)

#define HANDLE_KEYS(BOOL)								\
HANDLE_KEY(W, BOOL)										\
HANDLE_KEY(A, BOOL)										\
HANDLE_KEY(S, BOOL)										\
HANDLE_KEY(D, BOOL)										\
HANDLE_KEYCODE(SDL_SCANCODE_ESCAPE, Key::ESC, BOOL)		\
HANDLE_KEY(F3, BOOL)									\
HANDLE_KEY(RETURN, BOOL)

void System::input()
{
	// keystate in lastKeyState kopieren
	memcpy(m_lastKeyState, m_keyState, sizeof(m_keyState));

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

			case SDL_EventType::SDL_MOUSEBUTTONUP:
			case SDL_EventType::SDL_MOUSEBUTTONDOWN:
				if (m_pScene->m_pUI)
				{
					SDL_Point p;
					p.x = e.button.x;
					p.y = e.button.y;
					m_pScene->m_pUI->OnMouseChanged(p, e.button.state == SDL_PRESSED);
				}
				break;
			case SDL_EventType::SDL_MOUSEMOTION:
				if (m_pScene->m_pUI)
				{
					SDL_Point p;
					p.x = e.motion.x;
					p.y = e.motion.y;
					m_pScene->m_pUI->OnMouseChanged(p, e.motion.state == SDL_PRESSED);
				}
				break;

			case SDL_EventType::SDL_KEYDOWN:
				// SWITCH_ON_KEY(e.key.keysym.scancode, true);
				switch (e.key.keysym.scancode)
				{
					HANDLE_KEYS(true)
				}
				break;
			case SDL_EventType::SDL_KEYUP:
				// SWITCH_ON_KEY(e.key.keysym.scancode, false);
				switch (e.key.keysym.scancode)
				{
					HANDLE_KEYS(false)
				}
				break;
		}
	}
}

std::string System::GetFPS(bool _addDesired)
{
	std::string s = std::to_string(m_fps);

	if (_addDesired)
	{
		s.append(" / ").append(std::to_string(m_desiredFPS));
	}

	return s;
}

std::string System::GetTPS(bool _addDesired)
{
	std::string s = std::to_string(m_tps);

	if (_addDesired)
	{
		s.append(" / ").append(std::to_string(m_desiredTPS));
	}

	return s;
}