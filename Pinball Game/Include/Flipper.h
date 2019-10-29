// Flipper.h

#ifndef FLIPPER_H_INCLUDED
#define FLIPPER_H_INCLUDED

#include <Calculations.h>
#include <Paddle.h>

struct Ball;

enum FlipperState
{
   UP,
   HELD,
   DOWN,
};

struct Flipper // This is the game logic represantation of the paddle
{
   Vector2 mAnchorPos;
   Vector2 mNormal;
   Vector2 mLine1;
   Vector2 mLine2;

   Vector2 mLine1Original;

   Paddle* mPaddle;

   FlipperState mState;

   Flipper(float posX, float posY,
           float endPosX, float endPosY,
           float botPosX, float botPosY); // this should setup it's graphical counter part as well

   void Update(int deltaTime);
   void Draw();

   void BallKicker(Ball * ball); // Adds a force to the ball in the paddles normal direction.
};

#endif // !FLIPPER_H_INCLUDED
