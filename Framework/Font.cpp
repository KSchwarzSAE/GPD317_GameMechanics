#include "Font.h"
#include <iostream>

Font::Font(const char* _path, int _size)
{
	m_pFont = TTF_OpenFont(_path, _size);
}

Font::~Font()
{
	TTF_CloseFont(m_pFont);
}

void Font::Render(const char* _text, SDL_Surface* _pTarget, SDL_Point _pos)
{
	SDL_Color fg;
	fg.a = 255;
	fg.r = fg.b = fg.g = 255;
	
	SDL_Surface* pText = TTF_RenderText_Blended(m_pFont, _text, fg);

	ASSERT_SDL(!pText);

	SDL_Rect rect;
	rect.x = _pos.x;
	rect.y = _pos.y;
	rect.w = pText->w;
	rect.h = pText->h;

	SDL_BlitSurface(pText, 0, _pTarget, &rect);

	SDL_FreeSurface(pText);
}