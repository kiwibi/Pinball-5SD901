#include "Time.h"

Time::Time()
{
   prevTick = SDL_GetTicks();
   currentTick = prevTick;
}

void Time::Update()
{
   prevTick = currentTick;
   currentTick = SDL_GetTicks();

   deltaTime = currentTick - prevTick;
}
