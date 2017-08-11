#include "common.h"
#include <time.h>
#include <iostream>

static int gTexCount = 0;

std::string getParentDirectory(std::string _path, int _depth)
{
	if (_depth > 1)
		_path = getParentDirectory(_path, _depth - 1);

	size_t pos = _path.find_last_of("\\/");
	return (std::string::npos == pos)
		? ""
		: _path.substr(0, pos);
}

std::string getAssetPath(const char* _path)
{
	std::string path = getParentDirectory(SDL_GetBasePath(), 3);
	path.append("/Assets/").append(_path);
	return path;
}

static bool randomInited = false;

int RandomI(int _min, int _max)
{
	if (!randomInited) { srand(time(NULL)); randomInited = true; }

	return _min + (int)(((float)rand() / RAND_MAX) * (_max - _min));
}

float RandomF(float _min, float _max)
{
	if (!randomInited) { srand(time(NULL)); randomInited = true; }

	return _min + ((float)rand() / RAND_MAX) * (_max - _min);
}

void Log(const char* _string)
{
	std::cout << _string << std::endl;
}

void Log(std::string _string)
{
	Log(_string.c_str());
}