#include "common.h"

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