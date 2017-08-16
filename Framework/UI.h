#pragma once

#include "common.h"
#include <list>

class Renderer;
class Font;
class Texture;
class IRenderable;

class UIElement
{

public:

	virtual void OnMouseChanged(SDL_Point _p, bool _click) {}
	virtual void Render(Renderer* _pRenderer) = 0;

	bool m_visible;
	SDL_Rect m_bounds;

};

class Label : public UIElement
{

public:
	Label(Font* _pFont, const char* _text, SDL_Color _color);

	void Set(const char* _text, SDL_Color _color);
	virtual void Render(Renderer* _pRenderer) override;

	bool AutoCalcBounds;

private:
	Font* m_pFont;
	Texture* m_pText;
	SDL_Color m_color;
	SDL_Color m_lastColor;
	const char* m_lastText;
	const char* m_text;

};

class Image : public UIElement
{

};

class Button : public UIElement
{

public:
	Button(IRenderable* _pStandard, IRenderable* _pHover = nullptr, IRenderable* _pClicked = nullptr);

	virtual void OnMouseChanged(SDL_Point _p, bool _click) override;
	virtual void OnClick() = 0;
	virtual void Render(Renderer* _pRenderer) override;

private:
	IRenderable* m_pStandard;
	IRenderable* m_pHover;
	IRenderable* m_pClicked;

	int m_mode;
};

typedef std::list<UIElement*> UIList;

class UI
{

public:
	UI();
	~UI();

	void OnMouseChanged(SDL_Point _p, bool _click);
	void Render(Renderer* _pRenderer);

	void Add(UIElement* _element);
	void Remove(UIElement* _element);

private:
	UIList m_list;
};