#include "Scene.h"
#include "Entity.h"

Scene::Scene(System* _pSystem)
	: m_pSystem(_pSystem)
{

}

Scene::~Scene()
{
}

void Scene::render(SDL_Surface* _pSurface)
{
	for (auto itr = m_entitiesToRender.begin();
			itr != m_entitiesToRender.end();
			++itr)
	{
		(*itr)->Render(_pSurface, m_offset);
	}
}

void Scene::update(Uint32 _dt)
{
	for (auto itr = m_entitiesToUpdate.begin();
			itr != m_entitiesToUpdate.end();
			++itr)
	{
		(*itr)->Update(_dt);
	}

	CheckCollisions();
}

void Scene::CheckCollisions()
{
	EntityList toCheck = m_entitiesToCollide;

	for (auto itr = m_entitiesToCollide.begin(); itr != m_entitiesToCollide.end(); ++itr)
	{
		// aktuelle entity muss nicht noch mal geprueft werden
		toCheck.remove(*itr);
		
		// alle entities welche noch nicht geprueft wurden checken
		for (auto itr2 = toCheck.begin(); itr2 != toCheck.end(); ++itr2)
		{
			// wenn die bounds sich ueberlappen, dann findet eine kollision statt
			if (SDL_HasIntersection(&(*itr)->GetCollisionRect(), &(*itr2)->GetCollisionRect()))
			{
				(*itr)->OnCollision(*itr2);
				(*itr2)->OnCollision(*itr);
			}
		}
	}
}

void Scene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
}

void Scene::unload()
{
	EntityList toRemove = m_entitiesToRender;
	for each (Entity* pEntity in toRemove)
	{
		RemoveEntity(pEntity);
		delete pEntity;
	}
}

void Scene::AddEntity(Entity* _pEntity)
{
	m_entitiesToRender.push_back(_pEntity);

	if (_pEntity->HasFlag(EntityFlags::SHOULD_UPDATE))
		m_entitiesToUpdate.push_back(_pEntity);

	if (_pEntity->HasFlag(EntityFlags::CAN_COLLIDE))
		m_entitiesToCollide.push_back(_pEntity);
}

void Scene::RemoveEntity(Entity* _pEntity)
{
	m_entitiesToRender.remove(_pEntity);
	m_entitiesToUpdate.remove(_pEntity);
	m_entitiesToCollide.remove(_pEntity);
}
