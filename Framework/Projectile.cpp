#include "Projectile.h"
#include "System.h"
#include "Entity.h"
#include "TestScene.h"
#include "Scene.h"
#include "Texture.h"


Projectile::Projectile(const char* _name,
	Texture* _pSprite,
	SDL_Rect _bounds,
	EntityFlags _flags)
	: Entity(_name, _pSprite, _bounds, (EntityFlags)(_flags | EntityFlags::SHOULD_UPDATE))
{
	m_Speed = 1;
}

Projectile::~Projectile()
{
}

void Projectile::Update(Uint32 _dt)
{
	GetBounds().y -= _dt* m_Speed;
	if (GetBounds().y <= -100)
	{

	}
}
