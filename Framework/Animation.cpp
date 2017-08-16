#include "Animation.h"
#include "Sprite.h"

Animation::Animation(FrameList _list)
	: m_list(_list), m_counter(0), m_currentFrame(0)
{
}

Animation::~Animation()
{
}

void Animation::Update(Uint32 _dt)
{
	m_counter += _dt;

	if (m_counter > Current().duration)
	{
		m_currentFrame++;
		m_counter = 0;
	}

	if (m_currentFrame == m_list.size())
		m_currentFrame = 0;
}

AnimationFrame Animation::Current()
{
	auto it = m_list.begin();
	std::advance(it, m_currentFrame);
	return *it;
}

std::string Animation::GetDebugInfo()
{
	return 
		std::string("Animation (Frames: ")
		.append(std::to_string(m_list.size()))
		.append(", Current: ")
		.append(std::to_string(m_currentFrame))
		.append(")");
}

Texture* Animation::GetSourceTexture()
{
	return Current().pSprite->GetSourceTexture();
}

SDL_Rect Animation::GetSourceBounds()
{
	return Current().pSprite->GetSourceBounds();
}
