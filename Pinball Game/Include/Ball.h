// Ball.h

#ifndef BALL_H_INCLUDE
#define BALL_H_INCLUDE

#include <Calculations.h>

struct Circle;
struct Wall;
struct Flipper;
//struct Vector2;

struct Ball
{
   
   Vector2 mPos;
   Vector2 mSpeed;

   float mBouncy;
   Circle* mCircle;

   Ball(float posX, float posY, float radian, float segments);
   void Update(int deltaTime);
   void Collide(Vector2 wallNorm, int deltaTime);
   bool CollisionCheck(Wall wall);
   bool CollisionCheck(Flipper flipper);
   void Draw();
};

#endif // !BALL_H_INCLUDE