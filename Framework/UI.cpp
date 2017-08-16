#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::OnMouseChanged(SDL_Point _p, bool _click)
{
	for (auto it = m_list.begin(); it != m_list.end(); ++it)
		(*it)->OnMouseChanged(_p, _click);
}

void UI::Render(Renderer* _pRenderer)
{
	for (auto it = m_list.begin(); it != m_list.end(); ++it)
		if((*it)->m_visible)
			(*it)->Render(_pRenderer);
}

void UI::Add(UIElement* _element)
{
	m_list.push_back(_element);
}

void UI::Remove(UIElement* _element)
{
	m_list.remove(_element);
}
