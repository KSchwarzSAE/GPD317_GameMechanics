#pragma once

#include "Entity.h"

class Player : public Entity
{

public:
	Player(
		const char* _name,
		Texture* _pSprite,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Player();

	virtual void Update(Uint32 _dt) override;
	SDL_Rect m_allowBounds;
	bool LoseTriggered = false;

};