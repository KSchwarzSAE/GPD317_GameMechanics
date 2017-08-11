#include "Entity.h"
#include "Renderer.h"

Entity::Entity(
	const char* _name,
	Texture* _pSprite,
	SDL_Rect _bounds,
	EntityFlags _flags)
	: m_name(_name), m_pSprite(_pSprite), m_bounds(_bounds), m_flags(_flags), Object()
{
	
}

Entity::~Entity()
{
}

void Entity::Render(Renderer* _pRenderer, SDL_Point _offset)
{
	SDL_Rect bounds = SDL_Rect(m_bounds);
	bounds.x -= _offset.x;
	bounds.y -= _offset.y;

	_pRenderer->DrawTexture(m_pSprite, bounds);
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
