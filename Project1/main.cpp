// SDL Main Deaktivieren
#define SDL_MAIN_NEEDED FALSE
#include <SDL.h>
#include <SDL_image.h>
#undef main

#include <iostream>

int main(int argc, char *argv[])
{
	// SDL Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	// Image Plugin Initialisieren, und wenn der Rueckgabewert kleiner 0 ist, ist ein Fehler aufgetreten
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_Window* pWindow = SDL_CreateWindow(
		"Hello SDL World!",		// Titel des Fensters
		SDL_WINDOWPOS_CENTERED,	// Fenster Horizontal Zentrieren
		SDL_WINDOWPOS_CENTERED, // Fenster Vertikal Zentrieren
		800,					// Breite
		600,					// Hoehe
		SDL_WINDOW_SHOWN		// Extra Flags
		);

	if (pWindow == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;

		// SDL stoppen und aufraeumen
		SDL_Quit();

		return -1;
	}

	// Zeichenflaeche des Fensters holen
	SDL_Surface* pWindowSurface = SDL_GetWindowSurface(pWindow);

	if (pWindowSurface == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;

		// Fenster loeschen
		SDL_DestroyWindow(pWindow);
		pWindow = nullptr;

		// SDL stoppen und aufraeumen
		SDL_Quit();

		return -1;
	}
	
	SDL_Surface* pImage = IMG_Load("../../Assets/Images/test.png");

	if (pImage == nullptr)
	{
		std::cout << SDL_GetBasePath() << std::endl;
		std::cout << SDL_GetError() << std::endl;

		// Fenster loeschen
		SDL_DestroyWindow(pWindow);
		pWindow = nullptr;

		// SDL stoppen und aufraeumen
		SDL_Quit();

		return -1;
	}

	SDL_BlitSurface(pImage, 0, pWindowSurface, 0);

	// geaenderte fenster oberflaeche an die graka schicken zur anzeige
	SDL_UpdateWindowSurface(pWindow);

	SDL_Delay(8000);

	// Fenster loeschen
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	// SDL stoppen und aufraeumen
	SDL_Quit();

	return 0;
}