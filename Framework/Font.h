#pragma once

#include "common.h"

class Renderer;
class Texture;

class Font
{

public:
	Font(const char* _path, int _size);
	~Font();

	Texture* Create(const char* _text, SDL_Color _col, Renderer* _pRenderer);
	void Render(const char* _text, SDL_Color _col, Renderer* _pRenderer, SDL_Point _pos);

private:
	TTF_Font* m_pFont;

};