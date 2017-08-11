#include "Renderer.h"
#include "Texture.h"

Renderer::Renderer(SDL_Window* _pWindow)
{
	m_pRenderer = 
		SDL_CreateRenderer(_pWindow, -1, 
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
	if (m_pRenderer)
		SDL_DestroyRenderer(m_pRenderer);
}

void Renderer::BeginFrame()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_pRenderer);
}

void Renderer::FinishFrame()
{
	SDL_RenderPresent(m_pRenderer);
}

void Renderer::DrawTexture(Texture* _pTexture, SDL_Rect _dest)
{
	if (SDL_RenderCopy(m_pRenderer, _pTexture->m_pTexture, 0, &_dest) < 0)
	{
		Log(std::string("DrawTexture (").append(_pTexture->m_id).append(") failed!"));
	}
}
