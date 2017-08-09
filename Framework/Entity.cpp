#include "Entity.h"

Entity::Entity(
	const char* _name,
	SDL_Surface* _pSprite,
	SDL_Rect _bounds,
	EntityFlags _flags)
	: m_name(_name), m_pSprite(_pSprite), m_bounds(_bounds), m_flags(_flags)
{
	m_pSprite->refcount++;
}

Entity::~Entity()
{
	if (m_pSprite->refcount--)
	{
		delete m_pSprite;
	}	
}

void Entity::Render(SDL_Surface* _pTarget, SDL_Point _offset)
{
	SDL_Rect bounds = SDL_Rect(m_bounds);
	bounds.x -= _offset.x;
	bounds.y -= _offset.y;

	SDL_BlitScaled(m_pSprite, 0, _pTarget, &bounds);
}

void Entity::SetFlag(EntityFlags _flag, bool _state)
{
	if (_state)
	{
		m_flags = (EntityFlags)(m_flags | _flag);
	}
	else
	{
		m_flags = (EntityFlags)(m_flags & !_flag);
	}
}

bool Entity::HasFlag(EntityFlags _flag)
{
	return m_flags & _flag;
}
