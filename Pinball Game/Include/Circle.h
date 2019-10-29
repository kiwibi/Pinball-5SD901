// Circle.h

#ifndef CIRCLE_H_INCLUDE
#define CIRCLE_H_INCLUDE

#define For(i,N) for (int (i) = 0; (i) < (N); (i)++)
#include <Calculations.h>

struct Circle  // This is just the graphical representation of what will be the ball
{
   Vector2 mPos;
   int mRadian; // The circles radian
   int mSegments; // The number of segments that make up the circle. Basically resolution

   

   Circle();
   Circle(float radian, float segments);
   void Draw();
}; 
#endif //CIRCLE_H_INCLUDE !