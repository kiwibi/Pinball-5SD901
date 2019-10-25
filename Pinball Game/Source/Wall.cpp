//wall.cpp

#include <Wall.h>
#include <SDL_opengl.h>

Wall::Wall(float startX, float startY, float endX, float endY)
{
   mStartPos.x = startX;
   mStartPos.y = startY;
   mEndPos.x = endX;
   mEndPos.y = endY;

   Vector2 temp = Calculations::Subtraction(mStartPos, mEndPos);

   mNormal = Calculations::Rotate(Calculations::Normalize(temp), C_PI);
};

void Wall::Draw()
{
   glBegin(GL_LINE_LOOP);
   glVertex2f(mStartPos.x, mStartPos.y);
   glVertex2f(mEndPos.x, mEndPos.y);
   glEnd();
};