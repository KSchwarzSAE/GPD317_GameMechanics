#pragma once

#include "Entity.h"

class Texture;
class Projectile : public Entity
{

public:
	Projectile(
		const char* _name,
		Texture* _pSprite,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Projectile();

	virtual void Update(Uint32 _dt) override;
	int x, y;
	SDL_Rect m_allowBounds;
	int m_Speed;

};