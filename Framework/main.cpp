#include "common.h"
#include "System.h"
#include "TestScene.h"

int main(int argc, char *argv[])
{
	// System anlegen
	System s;

	// sdl starten und alle images laden
	if (s.init() && s.load())
	{
		// testszene laden
		TestScene scene = TestScene();
		s.changeScene(&scene);

		// programm ausfuehren
		s.run();
	}

	// speicher bereinigen
	s.clean();
}