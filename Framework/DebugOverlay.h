#pragma once

class Font;
class System;
struct SDL_Surface;

class DebugOverlay
{
public:
	DebugOverlay(System* _pSystem, Font* _pFont);
	~DebugOverlay();

	void Render(SDL_Surface* _pTarget);

private:
	System* m_pSystem;
	Font* m_pFont;

};