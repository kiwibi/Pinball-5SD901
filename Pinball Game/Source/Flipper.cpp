#include "..\Include\Flipper.h"

Flipper::Flipper(float posX, float posY, float length, float direction)
{
   mPos.x = posX; mPos.y = posY;
   mLength = length;
   mDirection = direction;

   mState = DOWN;

   Vector2 line1 = { 10, 20};
   Vector2 line2 = { 10, 20};
   mPaddle = new Paddle(line1, line2);
   mPaddle->mPos = mPos;
}

void Flipper::Update(int deltaTime)
{

   mPaddle->mPos = mPos;
}

void Flipper::Draw()
{
   mPaddle->Draw();
}
