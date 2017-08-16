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

Texture* Font::Create(const char* _text, SDL_Color _col, Renderer* _pRenderer)
{
	SDL_Surface* pText = TTF_RenderText_Blended(m_pFont, _text, _col);

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

void Font::Render(const char* _text, SDL_Color _col, Renderer* _pRenderer, SDL_Point _pos)
{
	Texture* pTex = Create(_text, _col, _pRenderer);

	if (!pTex) return;

	SDL_Rect rect;
	rect.x = _pos.x;
	rect.y = _pos.y;
	rect.w = pTex->GetWidth();
	rect.h = pTex->GetHeight();
	_pRenderer->Draw(pTex, rect);

	delete pTex;
}