#include "Scene.h"
#include "Entity.h"
#include "UI.h"

Scene::Scene(System* _pSystem)
	: m_pSystem(_pSystem)
{

}

Scene::~Scene()
{
}

void Scene::render(Renderer* _pRenderer)
{
	for (auto itr = m_entitiesToRender.begin();
			itr != m_entitiesToRender.end();
			++itr)
	{
		(*itr)->Render(_pRenderer, m_offset);
	}

	if(m_pUI != nullptr)
		m_pUI->Render(_pRenderer);
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
    HandleEntitiyChanges();
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

void Scene::load(Renderer* _pRenderer)
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
    EntityChange change;
    change.Mode = 1;
    change.pEntity = _pEntity;

	m_entitiesToChange.push_back(change);
}

void Scene::RemoveEntity(Entity* _pEntity, bool _delete)
{
	EntityChange change;
    change.Mode = _delete ? 3 : 2;
    change.pEntity = _pEntity;

    m_entitiesToChange.push_back(change);
}

void Scene::HandleEntitiyChanges()
{
    for(auto it = m_entitiesToChange.begin(); it != m_entitiesToChange.end(); ++it)
    {
        if((*it).Mode == 1)
        {
            m_entitiesToRender.push_back((*it).pEntity);

            if ((*it).pEntity->HasFlag(EntityFlags::SHOULD_UPDATE))
                m_entitiesToUpdate.push_back((*it).pEntity);

            if ((*it).pEntity->HasFlag(EntityFlags::CAN_COLLIDE))
                m_entitiesToCollide.push_back((*it).pEntity);
        }
        else
        {
            m_entitiesToRender.remove((*it).pEntity);
            m_entitiesToUpdate.remove((*it).pEntity;
            m_entitiesToCollide.remove((*it).pEntity);

            if((*it).Mode == 3)
                delete (*it).pEntity;
        }
    }

    m_entitiesToChange = std::list<EntityChange>();
}