#pragma once

#include "common.h"

class Texture;

class Renderer
{

	friend class Texture;

public:
	Renderer(SDL_Window* _pWindow);
	~Renderer();

	bool Valid() const { return m_pRenderer != nullptr; }

	void BeginFrame();
	void FinishFrame();

	void DrawTexture(Texture* _pTexture, SDL_Rect _dest);

private:
	SDL_Renderer* m_pRenderer;

};