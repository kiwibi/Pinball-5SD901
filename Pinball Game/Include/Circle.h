// Circle.h

#include <SDL_opengl.h>

#define For(i,N) for (int (i) = 0; (i) < (N); (i)++)

struct Circle  // This is just the graphical representation of what will be the ball
{
   int mPosX; // The circle position in space, where to draw it.
   int mPosY; // ^
   int mRadian; // The circles radian
   int mSegments; // The number of segments that make up the circle. Basically resolution

   

   Circle();
   Circle(int posX, int posY, int radian, int segments);
   void Draw();
};