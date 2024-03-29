// Wall.h

#ifndef WALL_H_INCLUDE
#define WALL_H_INCLUDE

#include <Calculations.h>

struct Wall
{
   Vector2 mStartPos;
   Vector2 mEndPos;

   Vector2 mNormal;

   Wall(float startX, float startY, float endX, float endY); // Tries to point the normal upwards.
   Wall(bool up, bool right, float startX, float startY, float endX, float endY); // Tries to point the normal in a specified direction.
   void Draw();
};

#endif // !WALL_H_INCLUDE
