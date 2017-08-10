#include "DebugOverlay.h"
#include "Font.h"
#include "System.h"


DebugOverlay::DebugOverlay(System* _pSystem, Font* _pFont)
	: m_pSystem(_pSystem), m_pFont(_pFont)
{
}

DebugOverlay::~DebugOverlay()
{
}

void DebugOverlay::Render(SDL_Surface* _pTarget)
{
	SDL_Point p;
	p.x = 700;
	p.y = 0;
	std::string s = "FPS: ";
	s.append(m_pSystem->GetFPS(true));
	m_pFont->Render(s.c_str(), _pTarget, p);

	p.y = 12;
	s = "TPS: ";
	s.append(m_pSystem->GetTPS(true));
	m_pFont->Render(s.c_str(), _pTarget, p);
}