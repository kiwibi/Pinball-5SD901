#pragma once

#include <SDL.h>

struct Time
{
   int prevTick = 0;
   int currentTick = 0;

   int deltaTime = 0;

   Time();

   void Update();
};