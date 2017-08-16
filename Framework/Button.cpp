#include "UI.h"
#include "Renderer.h"

Button::Button(IRenderable* _pStandard, IRenderable* _pHover, IRenderable* _pClicked)
	: m_pStandard(_pStandard), m_pHover(_pHover), m_pClicked(_pClicked), m_mode(0)
{
	m_visible = true;
}

void Button::OnMouseChanged(SDL_Point _p, bool _click)
{
	if (!m_visible)
		return;

	if (m_mode == 2 && !_click)
	{
		OnClick();
		m_mode = 1;
	}

	// ist der button noch gedrueckt
	if (m_mode == 2)
		return;

	// der button ist nicht gedrueckt und die maus ist nicht im button
	if (!SDL_PointInRect(&_p, &m_bounds))
	{
		m_mode = 0;
	}
	// der button ist nicht gedrueckt und die maus ist im button
	else
	{
		if (_click)
			m_mode = 2;
		else
			m_mode = 1;
	}

}

void Button::Render(Renderer* m_pRenderer)
{
	int actualMode = m_mode;
	if (actualMode == 2 && m_pClicked == nullptr)
		actualMode = 1;

	if (actualMode == 1 && m_pHover == nullptr)
		actualMode = 0;

	switch (actualMode)
	{
		case 0: m_pRenderer->Draw(m_pStandard, m_bounds); break;
		case 1: m_pRenderer->Draw(m_pHover, m_bounds); break;
		case 2: m_pRenderer->Draw(m_pClicked, m_bounds); break;
	}
}