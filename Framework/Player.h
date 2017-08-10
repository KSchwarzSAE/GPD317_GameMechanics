#pragma once

#include "Entity.h"

class Player : public Entity
{

public:
	Player(
		const char* _name,
		SDL_Surface* _pSprite,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Player();

	virtual void Update(Uint32 _dt) override;
	int x, y;
	SDL_Rect m_allowBounds;

};