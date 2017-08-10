#pragma once
#include "common.h"

class Timer
{

public:
	Timer();
	~Timer();

	void Start();
	void Stop();
	void Restart();

	// Gibt zurueck, wie viele Millisekunden seit Start() vergangen sind.
	Uint32 TicksTicked();

private:
	Uint32 m_ticks;

};