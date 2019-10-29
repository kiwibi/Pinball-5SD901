#include "..\Include\Flipper.h"

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

   mPaddle->mPos = mAnchorPos;
}

void Flipper::Draw()
{
   mPaddle->Draw();
}

void Flipper::BallKicker(Ball* ball)
{

}
