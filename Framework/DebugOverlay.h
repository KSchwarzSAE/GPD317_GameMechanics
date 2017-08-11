#pragma once

class Font;
class System;
class Renderer;

class DebugOverlay
{
public:
	DebugOverlay(System* _pSystem, Font* _pFont);
	~DebugOverlay();

	void Render(Renderer* _pRenderer);

private:
	System* m_pSystem;
	Font* m_pFont;

};