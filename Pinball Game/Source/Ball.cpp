// Ball.cpp

#include <ball.h>
#include <Circle.h>
#include <Wall.h>
#include <Calculations.h>

Ball::Ball(float posX, float posY, float radian, float segments)
{
   mPosX = posX; mPosY = posY;
   mSpeedX = 0; mSpeedY = 0;
   mCircle = new Circle(radian, segments);
}

void Ball::Update(int deltaTime)
{
   mPosX += mSpeedX * deltaTime / 60;
   mPosY += mSpeedY * deltaTime/ 60;
   mSpeedY += 1.0f * deltaTime / 60;

   if (mPosY > 700 && mSpeedY > 0)
      mSpeedY *= -1;

   if (mPosX > 462 && mSpeedX > 0 ||
       mPosX < 18 && mSpeedX < 0)
      mSpeedX *= -1;

   mCircle->mPosX = mPosX;
   mCircle->mPosY = mPosY;
   return;
}

void Ball::Draw()
{
   mCircle->Draw();
}

void Ball::Collide()
{
   
}

float max(float rhs, float lhs)
{
   return rhs > lhs ? rhs : lhs;
}

float min(float rhs, float lhs)
{
   return rhs < lhs ? rhs : lhs;
}

bool Ball::CollisionCheck(Wall wall)
{
   Vector2 ballPos;
   ballPos.x = mPosX;
   ballPos.y = mPosY;

   float maxX = max(wall.mStartPos.x, wall.mEndPos.x);
   float minX = min(wall.mStartPos.x, wall.mEndPos.x);
   float maxY = max(wall.mStartPos.y, wall.mEndPos.y);
   float minY = min(wall.mStartPos.y, wall.mEndPos.y);

   // The naming here succs, but I can't come upp with a better alternative.
   Vector2 pa = Calculations::Subtraction(ballPos, wall.mStartPos); //ballPos - wall.mStartPos;
   Vector2 wallDir = ( Calculations::Subtraction(wall.mEndPos, wall.mStartPos));
   wallDir = Calculations::Normalize(wallDir);
   float d = Calculations::Dot(pa, wallDir);//pa.dot(abDir);
   Vector2 D = ( Calculations::Addition(wall.mStartPos, Calculations::Multiplication(wallDir, d)));

   // If D is outside of of min max bounds set it to be inside bounds.

  /* clamp(D.x_, minX, maxX);
   clamp(D.y_, minY, maxY);*/

   Vector2 dDupe = D;
   Vector2 dDir = Calculations::Multiplication(wallDir, d);

   if (D.x < minX)
      D.x = minX;
   if (D.x > maxX)
      D.x = maxX;
   if (D.y < minY)
      D.y = minY;
   if (D.y > maxY)
      D.y = maxY;

   Vector2 test = Calculations::Subtraction(D, ballPos);

   float distance = Calculations::Magnitude(test);

   return ( distance <= mCircle->mRadian);

   //return intersect(circle, D);
};