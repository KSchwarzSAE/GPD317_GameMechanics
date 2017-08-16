#pragma once

#include <string>

class Texture;
struct SDL_Rect;

class IRenderable
{

public:

	virtual std::string GetDebugInfo() = 0;
	virtual Texture* GetSourceTexture() = 0;
	virtual SDL_Rect GetSourceBounds() = 0;

};