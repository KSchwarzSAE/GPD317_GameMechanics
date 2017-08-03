#include "Scene.h"

Scene::Scene(System* _pSystem)
	: m_pSystem(_pSystem)
{

}

Scene::~Scene()
{
}

void Scene::render(SDL_Surface* _pSurface)
{
}

void Scene::update()
{
}

void Scene::load(Uint32 _rmask, Uint32 _gmask, Uint32 _bmask, Uint32 _amask)
{
}

void Scene::unload()
{
}