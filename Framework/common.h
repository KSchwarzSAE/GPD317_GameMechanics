#pragma once

#ifndef __SDL_INCLUDED__
#define __SDL_INCLUDED__

#define SDL_MAIN_NEEDED FALSE
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#undef main

#endif

#include <string>

std::string getParentDirectory(std::string _path, int _depth = 1);
std::string getAssetPath(const char* _path);

void Log(const char* _string);
void Log(std::string _string);

int RandomI(int _min, int _max);
float RandomF(float _min, float _max);

#define HANDLE_ERROR(CHECK)							\
if(CHECK)											\
{													\
	std::cout << SDL_GetError() << std::endl;		\
	return false;									\
}

#define ASSERT_SDL(CHECK)							\
if(CHECK)											\
{													\
	std::cout << SDL_GetError() << std::endl;		\
	return;											\
}

#define SAFE_DELETE(VAR) if(VAR) { delete VAR; VAR = nullptr; }