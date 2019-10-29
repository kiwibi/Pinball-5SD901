#include <Paddle.h>
#include <SDL_opengl.h>


Paddle::Paddle(Vector2 line1, Vector2 line2)
{
   mPos = { 0 };
   mLine1 = line1;
   mLine2 = line2;
}

void Paddle::Draw()
{
   glLineWidth(3);
   glBegin(GL_LINE_LOOP);
   glColor3ub(255,255,255);
   glVertex2f(mPos.x, mPos.y);
   glVertex2f(mLine1.x, mLine1.y);
   glVertex2f(mLine2.x + mPos.x, mLine2.y + mPos.y);
   glEnd();
}
