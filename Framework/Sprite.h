#pragma once

#include "common.h"
#include "IRenderable.h"
#include "Texture.h"

class Sprite : public IRenderable
{

	friend class Renderer;
	
public:
	Sprite(Texture* _pSource, SDL_Rect _sourceRect);
	Sprite(Texture* _pSource, int _x, int _y, int _w, int _h);
	Sprite(Texture* _pSource);
	~Sprite();

	virtual std::string GetDebugInfo() override { return m_pSource->GetDebugInfo(); }
	virtual Texture* GetSourceTexture() override { return m_pSource; }
	virtual SDL_Rect GetSourceBounds() override { return m_sourceRect; }

private:
	Texture* m_pSource;
	SDL_Rect m_sourceRect;

};