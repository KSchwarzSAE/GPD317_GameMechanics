#pragma once

#include "Entity.h"

class Level : public Entity
{

public:
	Level(
		const char* _name,
		Texture* _pSprite,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Level();

	virtual void Update(Uint32 _dt) override;
	SDL_Rect m_allowBounds;

};