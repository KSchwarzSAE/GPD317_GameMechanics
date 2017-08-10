#pragma once

#include "common.h"

class Font
{

public:
	Font(const char* _path, int _size);
	~Font();

	void Render(const char* _text, SDL_Surface* _pTarget, SDL_Point _pos);

private:
	TTF_Font* m_pFont;

};