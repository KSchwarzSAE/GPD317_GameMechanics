#include "Stone.h"



Stone::Stone(const char* _name, Texture* _pSprite, SDL_Rect _bounds, EntityFlags _flags)
	: Entity(_name, _pSprite, _bounds, _flags)
{
}


Stone::~Stone()
{
}
