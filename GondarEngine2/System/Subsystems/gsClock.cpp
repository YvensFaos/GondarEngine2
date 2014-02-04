#include "gsClock.h"


#include "Dependencies\sdl\SDL_timer.h"

double gTotalTime; // Tempo total decorrido em segundos
double gDeltaTime; // Tempo decorrido entre os dois últimos updates. Em segundos.


void gsClock::init()
{
	gTotalTime = SDL_GetTicks() * 0.001; // to seconds
	gDeltaTime = gTotalTime;
}

void gsClock::update()
{
	double newTime = SDL_GetTicks() * 0.001;
	gDeltaTime = newTime - gTotalTime;
	gTotalTime = newTime;
}

double gsClock::getTotalTime()
{
	return gTotalTime;
}
double gsClock::getDeltaTime()
{
	return gDeltaTime;
}
