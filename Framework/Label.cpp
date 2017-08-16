#include "UI.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"

Label::Label(Font* _pFont, const char* _text, SDL_Color _color)
	: m_pFont(_pFont)
{
	Set(_text, _color);
	m_lastText = NULL;
	m_visible = true;
	AutoCalcBounds = true;
}

void Label::Set(const char* _text, SDL_Color _color)
{
	m_text = _text;
	m_color = _color;
}

void Label::Render(Renderer* _pRenderer)
{
	if (m_pText || m_lastText != m_text || memcmp(&m_lastColor, &m_color, sizeof(SDL_Color)))
	{
		m_lastText = m_text;
		m_lastColor = m_color;

		if (m_pText)
			delete m_pText;

		m_pText = m_pFont->Create(m_text, m_color, _pRenderer);

		if (AutoCalcBounds)
		{
			m_bounds.w = m_pText->GetWidth();
			m_bounds.h = m_pText->GetHeight();
		}
	}

	_pRenderer->Draw(m_pText, m_bounds);
}