// Flipper.h

#ifndef FLIPPER_H_INCLUDED
#define FLIPPER_H_INCLUDED

#include <Calculations.h>

enum FlipperState
{
   UP,
   HELD,
   DOWN,
};

struct Flipper
{
   Vector2 mPos;
   float mLength;
   float mDirection;

   FlipperState mState;

   Flipper(float posX, float posY, float length, float direction);
   void Update(int deltaTime);
   void Draw();
};

#endif // !FLIPPER_H_INCLUDED
