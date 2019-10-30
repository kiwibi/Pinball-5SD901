//wall.cpp

#include <Wall.h>
#include <math.h>
#include <SDL_opengl.h>

Wall::Wall(bool up, bool right, float startX, float startY, float endX, float endY)
{
   mStartPos.x = startX;
   mStartPos.y = startY;
   mEndPos.x = endX;
   mEndPos.y = endY;

   Vector2 temp = Calculations::Subtraction(mStartPos, mEndPos);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI / 2.0f);

   if (up && mNormal.y >= 0 || !up && mNormal.y < 0)
   {
      mNormal.y *= -1;
   }
   if (right && mNormal.x <= 0 || !right && mNormal.x > 0)
   {
      mNormal.x *= -1;
   }
};
Wall::Wall(float startX, float startY, float endX, float endY)
{
   mStartPos.x = startX;
   mStartPos.y = startY;
   mEndPos.x = endX;
   mEndPos.y = endY;

   Vector2 temp = Calculations::Subtraction(mStartPos, mEndPos);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI / 2.0f);

   if (mNormal.y > 0)
   {
      mNormal = Calculations::Rotate(mNormal, C_PI);
   }
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