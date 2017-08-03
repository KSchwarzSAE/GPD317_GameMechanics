#pragma once

#include "common.h"

#define LOAD_OPTIMIZED_IMAGE(PATH, VAR)								\
/* das bild	laden */												\
SDL_Surface* VAR##Image = IMG_Load(getAssetPath(PATH).c_str());		\
																	\
/* eine optimierte surface erstellen */								\
VAR = SDL_CreateRGBSurface(											\
	0,																\
	VAR##Image->w,													\
	VAR##Image->h,													\
	16,																\
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

class System;

class Scene
{

public:
	Scene(System* _pSystem);
	virtual ~Scene();

	virtual void render(SDL_Surface* _pSurface);
	virtual void update();

	virtual void load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask);
	virtual void unload();

protected:
	System* m_pSystem;

};