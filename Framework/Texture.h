#pragma once

#include "common.h"
#include "Object.h"

class Renderer;

class Texture : public Object
{
	friend class Renderer;

public:
	Texture(Renderer* _pRenderer, SDL_Surface* _pSurface, const char* _id);
	Texture(Renderer* _pRenderer, const char* _path);
	~Texture();

	bool Valid() const { return m_pTexture != nullptr; }
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }

protected:
	const char* m_id;
	int m_width;
	int m_height;
	
	SDL_Texture* m_pTexture;

};