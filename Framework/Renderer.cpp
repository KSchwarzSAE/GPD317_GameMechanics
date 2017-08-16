#include "Renderer.h"
#include "IRenderable.h"
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

void Renderer::Draw(IRenderable* _pRenderable, SDL_Rect _dest)
{
	SDL_Texture* pTex = _pRenderable->GetSourceTexture()->m_pTexture;
	
	int result
		= SDL_RenderCopy(m_pRenderer, pTex, &_pRenderable->GetSourceBounds(), &_dest);

	if (result < 0)
	{
		Log(std::string("Draw failed for IRenderable: ").append(_pRenderable->GetDebugInfo()));
	}
}