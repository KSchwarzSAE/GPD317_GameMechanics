#pragma once

#include "common.h"
#include <list>

class System;
class Entity;
class Renderer;
class UI;

typedef std::list<Entity*> EntityList;

struct EntityChange
{
    // 1 => Add
    // 2 => Remove
    // 3 => Remove and delete
    int Mode;

    Entity* pEntity;
};

class Scene
{

	friend class System;

public:
	Scene(System* _pSystem);
	virtual ~Scene();

	virtual void render(Renderer* _pRenderer);
	virtual void update(Uint32 _dt);
	virtual void CheckCollisions();

	virtual void load(Renderer* _pRenderer);
	virtual void unload();

	void AddEntity(Entity* _pEntity);
	void RemoveEntity(Entity* _pEntity, bool _delete = false);

protected:
	EntityList m_entitiesToRender;
	EntityList m_entitiesToUpdate;
	EntityList m_entitiesToCollide;

    std::list<EntityChange> m_entitiesToChange;

	UI* m_pUI;
	SDL_Point m_offset;
	System* m_pSystem;

private:
    void HandleEntitiyChanges();

};