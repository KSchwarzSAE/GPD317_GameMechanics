#pragma once

#include "common.h"
#include <list>

class System;
class Entity;
class Renderer;

typedef std::list<Entity*> EntityList;

class Scene
{

public:
	Scene(System* _pSystem);
	virtual ~Scene();

	virtual void render(Renderer* _pRenderer);
	virtual void update(Uint32 _dt);
	virtual void CheckCollisions();
	virtual void CollisionEvent(Entity* _entity);

	virtual void load(Renderer* _pRenderer);
	virtual void unload();

	void AddEntity(Entity* _pEntity);
	void RemoveEntity(Entity* _pEntity);

protected:
	EntityList m_entitiesToRender;
	EntityList m_entitiesToUpdate;
	EntityList m_entitiesToCollide;

	SDL_Point m_offset;
	System* m_pSystem;

};