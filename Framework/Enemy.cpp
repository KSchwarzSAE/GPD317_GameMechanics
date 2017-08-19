#include "Enemy.h"
#include "System.h"

System s;

Enemy::Enemy(const char* _name, Texture* _pSprite, SDL_Rect _bounds, EntityFlags _flags)
	: Entity(_name, _pSprite, _bounds, _flags)
{
}


Enemy::~Enemy()
{
}

void Enemy::Update(Uint32 _dt)
{

}

void Enemy::OnCollision(Entity * _other)
{
	// Tötet den Spieler bei Berührung
}

void Enemy::Kill()
{
	// Clean the game and free any used Memory
	s.clean();
	// Shut the Game down
	SDL_Quit();
}
