#pragma once
#include "Entity.h"


class Enemy : public Entity
{

public:

	Enemy(const char* _name, Texture* _pSprite, SDL_Rect _bounds, EntityFlags _flags = EntityFlags::NONE);
	~Enemy();

	virtual void Update(Uint32 _dt) override;
	virtual void OnCollision(Entity* _other) override;
	virtual void Kill();


private:

	const char* m_name;
	EntityFlags m_flags;
	Texture* m_pSprite;
	SDL_Rect m_bounds;
};

