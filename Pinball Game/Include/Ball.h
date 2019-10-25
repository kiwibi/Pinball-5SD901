// Ball.h

#ifndef BALL_H_INCLUDE
#define BALL_H_INCLUDE

struct Circle;
struct Wall;

struct Ball
{
   
   float mPosX; float mPosY; // This should be moved from circle.h to here I guess.
   float mSpeedX; float mSpeedY;
   Circle* mCircle;

   Ball(float posX, float posY, float radian, float segments);
   void Update(int deltaTime);
   void Collide();
   bool CollisionCheck(Wall wall);
   void Draw();
};

#endif // !BALL_H_INCLUDE