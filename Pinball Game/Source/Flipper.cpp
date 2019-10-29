#include "..\Include\Flipper.h"
#include "Ball.h"
#include "Circle.h"

Flipper::Flipper(float posX, float posY,
                 float endPosX, float endPosY,
                 float botPosX, float botPosY)
{
   mAnchorPos = {posX, posY};
   mLine1 = { endPosX, endPosY };
   mLine2 = { botPosX, botPosY };

   mState = DOWN;
   mPaddle = new Paddle(mLine1, mLine2);
   mPaddle->mPos = mAnchorPos;

   Vector2 temp = Calculations::Subtraction(mAnchorPos, mLine1);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI / 2.0f);

   if (mNormal.y > 0)
   {
      mNormal = Calculations::Rotate(mNormal, C_PI);
   }
}

void Flipper::Update(int deltaTime)
{

   mPaddle->mLine1 = mLine1;
   mPaddle->mLine2 = mLine2;
   mPaddle->mPos = mAnchorPos;
}

void Flipper::Draw()
{
   mPaddle->Draw();
}

void Flipper::BallKicker(Ball* ball)
{
   //Is ball close enough?
   // Kick it

   Vector2 boostVector = Calculations::Multiplication(mNormal, 100.0f);
   
   float minX = mAnchorPos.x < mLine1.x ? mAnchorPos.x : mLine1.x;
   float maxX = mAnchorPos.x > mLine1.x ? mAnchorPos.x : mLine1.x;
   float minY = mAnchorPos.y < mLine2.y ? mAnchorPos.y : mLine2.y;
   float maxY = mAnchorPos.y > mLine2.y ? mAnchorPos.y : mLine2.y;

   Vector2 closestPoint;

   closestPoint.x = Calculations::Clamp(ball->mPos.x, minX, maxX);
   closestPoint.y = Calculations::Clamp(ball->mPos.y, minY, maxY);

   float distance = Calculations::Magnitude(Calculations::Subtraction(closestPoint, ball->mPos));

   if (distance <= ball->mCircle->mRadian)
   {
      ball->mSpeed = Calculations::Addition(ball->mSpeed, boostVector);
   }
}