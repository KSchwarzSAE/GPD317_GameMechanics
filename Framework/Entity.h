#pragma once

#include "common.h"
#include "EntityFlags.h"

class Entity
{

public:
	Entity(
		const char* _name, 
		SDL_Surface* _pSprite, 
		SDL_Rect _bounds, 
		EntityFlags _flags = EntityFlags::NONE);
	virtual ~Entity();

	// Zeichnet die Entity auf Target
	virtual void Render(SDL_Surface* _pTarget, SDL_Point _offset);

	virtual void Update(Uint32 _dt) {}
	virtual void OnCollision(Entity* _other) {}

	void SetFlag(EntityFlags _flag, bool _state);
	bool HasFlag(EntityFlags _flag);

	SDL_Rect GetCollisionRect() { return m_bounds; }
	SDL_Rect& GetBounds() { return m_bounds; }

private:
	const char* m_name;
	EntityFlags m_flags;
	SDL_Surface* m_pSprite;
	SDL_Rect m_bounds;
};