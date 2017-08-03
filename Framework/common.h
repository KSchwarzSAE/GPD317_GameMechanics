#pragma once

#ifndef __SDL_INCLUDED__
#define __SDL_INCLUDED__

#define SDL_MAIN_NEEDED FALSE
#include <SDL.h>
#include <SDL_image.h>
#undef main

#endif

#include <string>

std::string getParentDirectory(std::string _path, int _depth = 1);
std::string getAssetPath(const char* _path);