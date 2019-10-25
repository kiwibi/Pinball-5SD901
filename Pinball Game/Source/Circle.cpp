// Circle.cpp

#include "circle.h"
#include <cmath>

Circle::Circle()
{
   mPosX = 0;
   mPosY = 0;
   mRadian = 0;
   mSegments = 0;
}

Circle::Circle(float radian, float segments)
{
   mPosX = 0;
   mPosY = 0;
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

      glVertex2f(x + float(mPosX), y + float(mPosY));
   }
   glEnd();
}