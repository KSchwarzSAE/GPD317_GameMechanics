#include "Level.h"

Level::Level(const char* _name,
	Texture* _pSprite,
	SDL_Rect _bounds,
	EntityFlags _flags)
	: Entity(_name, _pSprite, _bounds, (EntityFlags)(_flags | EntityFlags::SHOULD_UPDATE))
{
}

Level::~Level()
{
}

void Level::Update(Uint32 _dt)
{

}