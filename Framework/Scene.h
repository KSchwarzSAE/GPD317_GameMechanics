#pragma once

#include "common.h"
#include <list>

#pragma region optimization
#define LOAD_OPTIMIZED_IMAGE(PATH, VAR)								\
/* das bild	laden */												\
SDL_Surface* VAR##Image = IMG_Load(getAssetPath(PATH).c_str());		\
																	\
/* eine optimierte surface erstellen */								\
VAR = SDL_CreateRGBSurface(											\
	0,																\
	VAR##Image->w,													\
	VAR##Image->h,													\
	32,																\
	_rmask,															\
	_gmask,															\
	_bmask,															\
	_amask															\
	);																\
																	\
/* bild auf die optimierte surface kopieren */						\
SDL_BlitSurface(VAR##Image, 0, VAR, 0);								\
																	\
/* das geladene bild freigeben */									\
VAR = VAR##Image;
// SDL_FreeSurface(VAR##Image);										\

#pragma endregion

class System;
class Entity;

typedef std::list<Entity*> EntityList;

class Scene
{

public:
	Scene(System* _pSystem);
	virtual ~Scene();

	virtual void render(SDL_Surface* _pSurface);
	virtual void update(Uint32 _dt);
	virtual void CheckCollisions();

	virtual void load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask);
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