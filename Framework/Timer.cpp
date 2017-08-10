#include "Timer.h"

Timer::Timer()
{
	SDL_GetTicks();
}

Timer::~Timer()
{
}

void Timer::Start()
{
	m_ticks = SDL_GetTicks();
}

void Timer::Stop()
{
	m_ticks = 0;
}

void Timer::Restart()
{
	Stop();
	Start();
}

Uint32 Timer::TicksTicked()
{
	return SDL_GetTicks() - m_ticks;
}
