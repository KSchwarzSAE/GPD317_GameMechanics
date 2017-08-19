#include "Enemy.h"
#include "TestScene.h"
#include "Renderer.h"







Enemy::Enemy(
	const char* _name,
	Texture* _pSprite,
	SDL_Rect _bounds,
	EntityFlags _flags)
	:Entity(_name, _pSprite, _bounds, _flags)
{
	m_name = _name;
	m_pSprite = _pSprite;
	m_bounds = _bounds;
	m_flags = _flags;
	m_flags = EntityFlags::SHOULD_UPDATE;
	

}


Enemy::~Enemy()
{

}



void Enemy::Render(Renderer* _pRenderer, SDL_Point _offset)
{
	SDL_Rect bounds = SDL_Rect(m_bounds);
	bounds.x -= _offset.x;
	bounds.y += _offset.y;
	
	_pRenderer->DrawTexture(m_pSprite, bounds);
}

void Enemy::Update(Uint32 _dt)
{
	
	if (m_bounds.x < 200 && m_name == "Kevin")
		m_bounds.x += _dt / 2;

	else if (m_bounds.x < 200)
		m_bounds.x += _dt/3;

	if (m_bounds.x >= 200)
		m_bounds.y -= _dt;



}



bool Enemy::HasFlag(EntityFlags _flag)
{
	return m_flags & _flag;
}

