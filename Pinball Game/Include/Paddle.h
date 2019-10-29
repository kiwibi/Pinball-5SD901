//Paddle.h

#ifndef PADDLE_H_DEFINED
#define PADDLE_H_DEFINED

#define For(i,N) for (int (i) = 0; (i) < (N); (i)++)
#include <Calculations.h>

struct Paddle // This is the graphical struct for the paddle
{
   Vector2 mPos;
   Vector2 mLine1;
   Vector2 mLine2;

   Paddle(Vector2 line1, Vector2 line2);
   void Draw();
};

#endif // !PADDLE_H_DEFINED
