#pragma once

#include "common.h"
#include "Object.h"
#include "IRenderable.h"

class Renderer;

class Texture : public Object, public IRenderable
{
	friend class Renderer;

public:
	Texture(Renderer* _pRenderer, SDL_Surface* _pSurface, const char* _id);
	Texture(Renderer* _pRenderer, const char* _path);
	~Texture();

	bool Valid() const { return m_pTexture != nullptr; }
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	SDL_Rect GetBounds() const;

	virtual std::string GetDebugInfo() override { return m_id; }
	virtual Texture* GetSourceTexture() override { return this; }
	virtual SDL_Rect GetSourceBounds() override { return GetBounds(); }

private:
	const char* m_id;
	int m_width;
	int m_height;
	
	SDL_Texture* m_pTexture;

};