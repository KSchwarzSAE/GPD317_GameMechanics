#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite(Texture* _pSource, SDL_Rect _sourceRect)
{
	m_pSource = _pSource;
	m_sourceRect = _sourceRect;
}

Sprite::Sprite(Texture* _pSource, int _x, int _y, int _w, int _h)
{
	m_pSource = _pSource;
	m_sourceRect.x = _x;
	m_sourceRect.y = _y;
	m_sourceRect.w = _w;
	m_sourceRect.h = _h;
}

Sprite::Sprite(Texture* _pSource)
	: Sprite(_pSource, _pSource->GetBounds())
{
}

Sprite::~Sprite()
{
}
