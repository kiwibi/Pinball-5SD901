#include "..\Include\Flipper.h"

Flipper::Flipper(float posX, float posY, float endPosX, float endPosY)
{
   mPos.x = posX; mPos.y = posY;
   mLine = { endPosX, endPosY };
   mState = DOWN;
   Vector2 line2 = { posX, 20 };
   mPaddle = new Paddle(mLine, line2);
   mPaddle->mPos = mPos;

   Vector2 temp = Calculations::Subtraction(mPos, mLine);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI / 2.0f);

   if (mNormal.y > 0)
   {
      mNormal = Calculations::Rotate(mNormal, C_PI);
   }
}

void Flipper::Update(int deltaTime)
{

   mPaddle->mPos = mPos;
}

void Flipper::Draw()
{
   mPaddle->Draw();
}
