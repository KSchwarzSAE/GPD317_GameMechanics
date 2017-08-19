#pragma once
#include "Entity.h"

class Stone : public Entity
{

public:

	Stone(const char* _name, Texture* _pSprite, SDL_Rect _bounds, EntityFlags _flags = EntityFlags::NONE);
	~Stone();

private:

	const char* m_name;
	EntityFlags m_flags;
	Texture* m_pSprite;
	SDL_Rect m_bounds;
};

