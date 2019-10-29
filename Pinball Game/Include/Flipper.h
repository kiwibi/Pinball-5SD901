// Flipper.h

#ifndef FLIPPER_H_INCLUDED
#define FLIPPER_H_INCLUDED

#include <Calculations.h>
#include <Paddle.h>

enum FlipperState
{
   UP,
   HELD,
   DOWN,
};

struct Flipper // This is the game logic represantation of the paddle
{
   Vector2 mPos;
   float mLength;
   float mDirection;
   Paddle* mPaddle;

   FlipperState mState;

   Flipper(float posX, float posY, float length, float direction); // this should setup it's graphical counter part as well

   void Update(int deltaTime);
   void Draw();
};

#endif // !FLIPPER_H_INCLUDED
