#include "Texture.h"
#include "Renderer.h"

Texture::Texture(Renderer* _pRenderer, SDL_Surface* _pSurface, const char* _id)
	: Object()
{
	// texture aus dem bild erstellen (es wird eine kopie erstellt!)
	m_pTexture = SDL_CreateTextureFromSurface(_pRenderer->m_pRenderer, _pSurface);

	if(!m_pTexture)
		Log(std::string("Could not create Texture ").append(m_id));

	m_width = _pSurface->w;
	m_height = _pSurface->h;
	m_id = _id;
}

Texture::Texture(Renderer* _pRenderer, const char* _path)
	: Object()
{
	m_id = _path;

	// image laden
	SDL_Surface* pSurface = IMG_Load(_path);

	// falls das bild geladen werden konnte
	if (pSurface)
	{
		// texture aus dem bild erstellen (es wird eine kopie erstellt!)
		m_pTexture = SDL_CreateTextureFromSurface(_pRenderer->m_pRenderer, pSurface);

		m_width = pSurface->w;
		m_height = pSurface->h;

		// bild freigeben
		SDL_FreeSurface(pSurface);
	}
	else
	{
		Log(std::string("Could not load Texture ").append(m_id));
	}
}

Texture::~Texture()
{
	if(m_pTexture)
		SDL_DestroyTexture(m_pTexture);
}
