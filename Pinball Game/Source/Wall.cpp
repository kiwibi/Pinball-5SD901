//wall.cpp

#include <Wall.h>
#include <math.h>
#include <SDL_opengl.h>

Wall::Wall(float startX, float startY, float endX, float endY)
{
   mStartPos.x = startX;
   mStartPos.y = startY;
   mEndPos.x = endX;
   mEndPos.y = endY;

   Vector2 temp = Calculations::Subtraction(mStartPos, mEndPos);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI / 2.0f);
};

void Wall::Draw()
{
   glLineWidth(6);
   glPointSize(6);
   float factorStart = 1 - (mStartPos.x / 480);
   float factorEnd = 1 - (mEndPos.x / 480);
   glBegin(GL_LINE_LOOP);
   glColor3ub(-mStartPos.y / 3, mStartPos.x / 2, (mStartPos.y / 3) * (factorStart));
   glVertex2f(mStartPos.x, mStartPos.y);
   glColor3ub(-mEndPos.y / 3, mEndPos.x / 2, (mEndPos.y / 3) * (factorStart));
   glVertex2f(mEndPos.x, mEndPos.y);
   glEnd();
};