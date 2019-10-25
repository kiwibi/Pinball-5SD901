// Ball.cpp

#include <ball.h>
#include <Circle.h>

Ball::Ball(float posX, float posY, float radian, float segments)
{
   mPosX = posX; mPosY = posY;
   mSpeedX = 0; mSpeedY = 0;
   mCircle = new Circle(radian, segments);
}

void Ball::Update(int deltaTime)
{
   mSpeedY += 1.0f * deltaTime / 60;
   mPosX += mSpeedX * deltaTime / 60;
   mPosY += mSpeedY * deltaTime/ 60;

   if (mPosY > 700)
      mPosY = 50;

   mCircle->mPosX = mPosX;
   mCircle->mPosY = mPosY;
   return;
}

void Ball::Draw()
{
   mCircle->Draw();
}