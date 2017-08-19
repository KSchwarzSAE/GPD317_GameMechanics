#pragma once

#include "common.h"
#include "EntityFlags.h"
#include "Object.h"

class Renderer;
class Texture;

class Entity : public Object
{

public:
	Entity(
		const char* _name, 
		Texture* _pSprite,
		SDL_Rect _bounds, 
		EntityFlags _flags = EntityFlags::NONE);
	virtual ~Entity();

	// Zeichnet die Entity auf Target
	virtual void Render(Renderer* _pRenderer, SDL_Point _offset);

	virtual void Update(Uint32 _dt) {}
	virtual void OnCollision(Entity* _other) {}

	void SetFlag(EntityFlags _flag, bool _state);
	bool HasFlag(EntityFlags _flag);

	SDL_Rect GetCollisionRect() { return m_bounds; }
	SDL_Rect& GetBounds() { return m_bounds; }


protected:
	const char* m_name;
	EntityFlags m_flags;
	Texture* m_pSprite;
	SDL_Rect m_bounds;

};