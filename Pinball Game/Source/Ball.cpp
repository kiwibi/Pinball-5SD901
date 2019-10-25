// Ball.cpp

#include "Ball.h"
#include "Circle.h"

Ball::Ball(float posX, float posY, float radian, float segments)
{
   mPosX = posX; mPosY = posY;
   mSpeedX = 0; mSpeedY = 0;
   mCircle = new Circle(radian, segments);
}

void Ball::Update(int deltaTime)
{
   mSpeedY += 0.5f * deltaTime / 60;
   mPosX += mSpeedX * deltaTime / 60;
   mPosY += mSpeedY * deltaTime/ 60;
   mCircle->mPosX = mPosX;
   mCircle->mPosY = mPosY;
   return;
}

void Ball::Draw()
{
   mCircle->Draw();
}