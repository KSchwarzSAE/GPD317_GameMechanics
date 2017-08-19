#pragma once
#include "Entity.h"

class Renderer;
class Texture;

class Enemy : public Entity
{
public:
	Enemy(
		const char* _name,
		Texture* _pSprite,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Enemy();
	
	virtual void Render(Renderer* _pRenderer, SDL_Point _offset) override;
	virtual void Update(Uint32 _dt) override;

	bool HasFlag(EntityFlags _flag);
	
	
};

