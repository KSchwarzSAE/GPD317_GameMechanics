#pragma once
#include "Entity.h"

class Bedrock : public Entity
{

public:

	Bedrock(const char* _name, Texture* _pSprite, SDL_Rect _bounds, EntityFlags _flags = EntityFlags::NONE);
	~Bedrock();

private:

	const char* m_name;
	EntityFlags m_flags;
	Texture* m_pSprite;
	SDL_Rect m_bounds;
};

