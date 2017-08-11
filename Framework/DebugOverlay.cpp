#include "DebugOverlay.h"
#include "Font.h"
#include "System.h"
#include "Texture.h"
#include "Entity.h"

DebugOverlay::DebugOverlay(System* _pSystem, Font* _pFont)
	: m_pSystem(_pSystem), m_pFont(_pFont)
{
}

DebugOverlay::~DebugOverlay()
{
}

void DebugOverlay::Render(Renderer* _pRenderer)
{
	SDL_Point p;
	p.x = 700;
	p.y = 0;
	std::string s = "FPS: ";
	s.append(m_pSystem->GetFPS(true));
	m_pFont->Render(s.c_str(), _pRenderer, p);

	p.y = 12;
	s = "TPS: ";
	s.append(m_pSystem->GetTPS(true));
	m_pFont->Render(s.c_str(), _pRenderer, p);

	p.y = 24;
	s = "Textures: ";
	s.append(std::to_string(Texture::Count()));
	m_pFont->Render(s.c_str(), _pRenderer, p);

	p.y = 36;
	s = "Entities: ";
	s.append(std::to_string(Entity::Count()));
	m_pFont->Render(s.c_str(), _pRenderer, p);
}