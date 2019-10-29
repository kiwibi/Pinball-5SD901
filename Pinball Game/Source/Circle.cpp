// Circle.cpp

#include "circle.h"
#include <SDL_opengl.h>
#include <cmath>

Circle::Circle()
{
   mPos.x = 0;
   mPos.y = 0;
   mRadian = 0;
   mSegments = 0;
}

Circle::Circle(float radian, float segments)
{
   mPos.x = 0;
   mPos.y = 0;
   mRadian = radian;
   mSegments = segments;
}

void Circle::Draw()
{
   glBegin(GL_TRIANGLE_FAN);
   For (i,mSegments)
   {
      float theta = 2.0f * 3.1415926f * float(i) / float(mSegments);

      float x = float(mRadian) * cosf(theta);
      float y = float(mRadian) * sinf(theta);

      glColor3ub( -mPos.y / 3, mPos.x / 2, mPos.y / 3); glVertex2f(x + float(mPos.x), y + float(mPos.y)); // Cool
   }
   glEnd();
}