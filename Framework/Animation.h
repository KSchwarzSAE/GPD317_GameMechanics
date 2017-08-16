#pragma once

#include "common.h"
#include <list>
#include "IRenderable.h"

class Sprite;

struct AnimationFrame
{

	AnimationFrame(Sprite* _pSprite, Uint32 _duration)
	{
		pSprite = _pSprite;
		duration = _duration;
	}

	Sprite* pSprite;
	Uint32 duration;

};

typedef std::list<AnimationFrame> FrameList;

class Animation : public IRenderable
{

public:
	Animation(FrameList _list);
	~Animation();

	void Update(Uint32 _dt);
	AnimationFrame Current();

	virtual std::string GetDebugInfo() override;
	virtual Texture* GetSourceTexture() override;
	virtual SDL_Rect GetSourceBounds() override;

private:
	int m_currentFrame;
	Uint32 m_counter;
	FrameList m_list;

};