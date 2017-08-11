#include "Font.h"
#include "Texture.h"
#include "Renderer.h"

Font::Font(const char* _path, int _size)
{
	m_pFont = TTF_OpenFont(_path, _size);
}

Font::~Font()
{
	TTF_CloseFont(m_pFont);
}

Texture* Font::Create(const char* _text, Renderer* _pRenderer)
{
	SDL_Color fg;
	fg.a = 255;
	fg.r = fg.b = fg.g = 255;

	SDL_Surface* pText = TTF_RenderText_Blended(m_pFont, _text, fg);

	Texture* pTex = new Texture(_pRenderer, pText, _text);

	SDL_FreeSurface(pText);

	if (!pTex->Valid())
	{
		Log("Could not render text");
		delete pTex;
		return nullptr;
	}

	return pTex;
}

void Font::Render(const char* _text, Renderer* _pRenderer, SDL_Point _pos)
{
	Texture* pTex = Create(_text, _pRenderer);

	if (!pTex) return;

	SDL_Rect rect;
	rect.x = _pos.x;
	rect.y = _pos.y;
	rect.w = pTex->GetWidth();
	rect.h = pTex->GetHeight();
	_pRenderer->DrawTexture(pTex, rect);

	delete pTex;
}