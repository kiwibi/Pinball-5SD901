// Ball.cpp

#include <ball.h>
#include <Circle.h>
#include <Wall.h>
#include <Flipper.h>
#include <math.h>

Ball::Ball(float posX, float posY, float radian, float segments)
{
   mPos.x = posX;
   mPos.y = posY;
   mSpeed = { 0 , 0 }; //
   mCircle = new Circle(radian, segments);
   mBouncy = 0.7f;

   lastStoredDistance =  {0};
}

void Ball::Update(int deltaTime)
{
   mPos.x += mSpeed.x * deltaTime / 60;
   mPos.y += mSpeed.y * deltaTime/ 60;
   mSpeed.y += 1.0f * deltaTime / 60;

   if (mPos.y < 18 && mSpeed.y < 0)
      mSpeed.y *= -mBouncy;
   if (mPos.y > 700 && mSpeed.y > 0)
	   Reset();

   if (mPos.x > 462 && mSpeed.x > 0 ||
       mPos.x < 18 && mSpeed.x < 0)
      mSpeed.x *= -mBouncy;

   mCircle->mPos.x = mPos.x;
   mCircle->mPos.y = mPos.y;
   return;
}

void Ball::Draw()
{
   mCircle->Draw();
}

void Ball::Collide(Vector2 wallNorm, int deltaTime)
{
	float disatanceAlongNormal = Calculations::Dot(mSpeed, wallNorm);
	mSpeed.x -= 2.0f * disatanceAlongNormal * wallNorm.x;
	mSpeed.y -= 2.0f * disatanceAlongNormal * wallNorm.y;
   //float angle = (Calculations::CollisionAngle(mSpeed, wallNorm));
   //mSpeed = Calculations::Rotate(mSpeed, angle);
   mSpeed = Calculations::Multiplication(mSpeed, mBouncy);

   mPos.x +=  (8 - fabsf(lastStoredDistance.x)) * wallNorm.x; // Should push the ball away 1 radia from the wall.
   mPos.y += ( 8 - fabsf(lastStoredDistance.y)) * wallNorm.y;
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
   float maxX = max(wall.mStartPos.x, wall.mEndPos.x);
   float minX = min(wall.mStartPos.x, wall.mEndPos.x);
   float maxY = max(wall.mStartPos.y, wall.mEndPos.y);
   float minY = min(wall.mStartPos.y, wall.mEndPos.y);

   // The naming here succs, but I can't come upp with a better alternative.
   Vector2 pa = Calculations::Subtraction(mPos, wall.mStartPos); //ballPos - wall.mStartPos;
   Vector2 wallDir = ( Calculations::Subtraction(wall.mEndPos, wall.mStartPos) );
   wallDir = Calculations::Normalize(wallDir);
   float d = Calculations::Dot(pa, wallDir);//pa.dot(abDir);
   Vector2 D = ( Calculations::Addition(wall.mStartPos, Calculations::Multiplication(wallDir, d)) );

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

   Vector2 distanceVector = Calculations::Subtraction(D, mPos);

   float distance = Calculations::Magnitude(distanceVector);

   lastStoredDistance = distanceVector;

   return ( distance <= mCircle->mRadian );

   //return intersect(circle, D);
};

bool Ball::CollisionCheck(Flipper flipper)
{
   float maxX = max(flipper.mAnchorPos.x, flipper.mLine1.x);
   float minX = min(flipper.mAnchorPos.x, flipper.mLine1.x);
   float maxY = max(flipper.mAnchorPos.y, flipper.mLine1.y);
   float minY = min(flipper.mAnchorPos.y, flipper.mLine1.y);

   // The naming here succs, but I can't come upp with a better alternative.
   Vector2 pa = Calculations::Subtraction(mPos, flipper.mAnchorPos); //ballPos - wall.mStartPos;
   Vector2 wallDir = ( Calculations::Subtraction(flipper.mLine1, flipper.mAnchorPos) );
   wallDir = Calculations::Normalize(wallDir);
   float d = Calculations::Dot(pa, wallDir);//pa.dot(abDir);
   Vector2 D = ( Calculations::Addition(flipper.mAnchorPos, Calculations::Multiplication(wallDir, d)) );

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

   Vector2 distanceVector = Calculations::Subtraction(D, mPos);

   float distance = Calculations::Magnitude(distanceVector);

   lastStoredDistance = distanceVector;

   return ( distance <= mCircle->mRadian );

   //return intersect(circle, D);
};

void Ball::Reset()
{
	mPos.x = 50;
	mPos.y = 50;
	mSpeed = { 0 , 0 };
	mCircle->mPos.x = mPos.x;
	mCircle->mPos.y = mPos.y;
}