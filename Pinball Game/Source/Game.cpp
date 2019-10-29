//---------------------------------------------------------------------
//---------------------------------------------------------------------
//  (c) Mikael Fridenfalk
//  Template for use in the course:
//  Linear Algebra, Trigonometry and Geometry, 7.5 c
//  Uppsala University, Sweden
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include "Game.h"
#include <stdio.h>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Game::Game()
   : mBall(Ball(50, 50, 8, 20)),
   mWall1(Wall(11, 530, 150, 650)),
   mWall2(Wall(468, 530, 330, 650)),
   mFlipper1(150, 650, 220, 670, 150, 670),
   mFlipper2(330, 650, 260, 670, 330, 670) // Float(C_PI) should hopefully make the paddle point the opposite direction
{
	mMtxFont = new char[128][7][5];
	InitMtxFont();
	mCounter = 0;
	mW = 900.0f, mH = 720.f;
	mMouseX = mMouseY = 0;
   mMouseButton = mMouseState = 0;

   mLeft = KEY_RELEASED;
   mRight = KEY_RELEASED;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::ChangeSize(int w, int h){
    mW = w, mH = h;
	glViewport(0,0,mW,mH);                         // Reset Viewport
	glMatrixMode(GL_PROJECTION); glLoadIdentity(); // Reset The Projection Matrix
	glOrtho(0.0f,mW,mH,0.0f,-1.0f,.0f);           // Create Ortho View (0,0 At Top Left)
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();  // Reset The Modelview Matrix
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::CheckCollision(int deltaTime)
{
   if (mBall.CollisionCheck(mWall1))
   {
      mBall.Collide(mWall1.mNormal, deltaTime);
   }
   else if ( mBall.CollisionCheck(mWall2) )
   {
      mBall.Collide(mWall2.mNormal, deltaTime);
   }

   if (mBall.CollisionCheck(mFlipper1))
   {
      mBall.Collide(mFlipper1.mNormal, deltaTime);
   }
   else if (mBall.CollisionCheck(mFlipper2))
   {
      mBall.Collide(mFlipper2.mNormal, deltaTime);
   }
   /*if (mBall.CollisionCheck(mWall1) || mBall.CollisionCheck(mWall2))
   {
      float memX = mBall.mSpeedX;
      mBall.mSpeedX = mBall.mSpeedY;
      mBall.mSpeedY = memX;
   }*/
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::Update(int deltaTime)
{
   // Update Flippers
   mFlipper1.Update(deltaTime);
   mFlipper2.Update(deltaTime);
   // Update Ball
   mBall.Update(deltaTime);
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::Draw(int deltaTime){
    
    //--------------------------------------------Clear
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	//--------------------------------------------Borders
	glLineWidth(3);
	glPointSize(3);

	glBegin(GL_LINE_LOOP);
	glColor3ub(255, 0, 0);   glVertex3f(10, 10, 0);  //left top
	glColor3ub(255, 255, 0); glVertex3f(470, 10, 0); //right top
	glColor3ub(0, 255, 0);   glVertex3f(470, mH - 10, 0); //right bottom
	glColor3ub(0, 0, 255);   glVertex3f(10, mH - 10, 0);   //left bottom
	glEnd();

   //----------------------------------------------Walls
   mWall1.Draw();
   mWall2.Draw();
   //----------------------------------------------Ball
   mBall.Draw();
   //----------------------------------------------Flippers
   mFlipper1.Draw();
   mFlipper2.Draw();
    //--------------------------------------------Geometry
    /*glLineWidth(3);
    glPointSize(10);
    
    int method[] = {GL_POINTS,GL_LINES,GL_LINE_STRIP,GL_LINE_LOOP,GL_POLYGON};
    
    For (i,5){
        glBegin(method[i]);
        float dx = 200 + 220*i;
        float dy = 350;
        glColor3ub(255,0,0);   glVertex3f(-50+dx,-50+dy,0);
        glColor3ub(127,127,0); glVertex3f(-50+dx, 50+dy,0);
        glColor3ub(0,255,0);   glVertex3f( 50+dx, 50+dy,0);
        glColor3ub(0,0,255);   glVertex3f( 50+dx,-50+dy,0);
        glEnd();
    }*/
	//--------------------------------------------Text
	int a = mW - 300;
	glColor3ub(255,0,0);
	Draw_MtxText(a, mH - 4*24, "X = %4d  Y = %4d",
                 int(mBall.mSpeed.x),int(mBall.mSpeed.y));
	glColor3ub(100,100,220);
	Draw_MtxText(a, mH - 3*24, "X = %4d  Y = %4d",
                int(mBall.mPos.x), int(mBall.mPos.y));
    Draw_MtxText(a, mH - 2*24, "TIME = %7u",
                 deltaTime);
                 //printf("[ret = %u\n",ret););
	//--------------------------------------------	
    //--------------------------------------------	
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::NormalKeys(unsigned char key, int state){
	if (key >= SDLK_0 && key <= SDLK_9){}
	if (key == SDLK_RETURN){}//Return
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::SpecialKeys(int key, int state){
    if (key == SDLK_LEFT ){
       switch (mLeft){
          case KEY_RELEASED:
            mLeft = KEY_DOWN;
            // Changle flipper state. Fling balls
            mFlipper1.BallKicker(&mBall);
            break;
          
          //case KEY_PRESSED:
          //   mLeft = KEY_DOWN;
          //   break;
          
          case KEY_DOWN:
             // Keep flipper in upright.
             break;
       }

    }
    if (key == SDLK_RIGHT){
       switch (mRight) {
       case KEY_RELEASED:
          mRight = KEY_DOWN;
          // Changle flipper state. Fling ball
          mFlipper2.BallKicker(&mBall);
          break;

          //case KEY_PRESSED:
          //   mLeft = KEY_DOWN;
          //   break;

       case KEY_DOWN:
          // Keep flipper in upright.
          break;
       }
    }
    if (key == SDLK_UP){}
    if (key == SDLK_DOWN){}
}
//---------------------------------------------------------------------
void Game::SpecialKeys(int key, KeyState state) {
   if (key == SDLK_LEFT) {
      mLeft = KEY_RELEASED;
      mFlipper1.mState = DOWN;
      // Other key released things
   }
   if (key == SDLK_RIGHT) {
      mRight = KEY_RELEASED;
      mFlipper2.mState = DOWN;
      // Other key released things

   }
   if (key == SDLK_UP) {}
   if (key == SDLK_DOWN) {}
}
//---------------------------------------------------------------------
void Game::Mouse(int button, int state, int x, int y){
	mMouseButton = button;//SDL_BUTTON_LEFT/SDL_BUTTON_MIDDLE/SDL_BUTTON_RIGHT
	mMouseState = state;//SDL_PRESSED/SDL_RELEASED
	mMouseX = x; mMouseY = y;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::MouseMotion(int x, int y){
    mMouseMotionX = x; mMouseMotionY = y;
};
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                              Font
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::InitMtxFont(){
	
	For (i,128) For (j,7) For (k,5) mMtxFont[i][j][k] = 1;
	
    const char F0[] =
    "00000" "00000" "00000" "11111" "00000" "00000" "00000"//-
    "00000" "00000" "00000" "00000" "00000" "01100" "01100"//.
    "11111" "11111" "11111" "11111" "11111" "11111" "11111"//
    "01110" "10001" "10011" "10101" "11001" "10001" "01110"//0
    "00100" "01100" "00100" "00100" "00100" "00100" "01110"//1
    "01110" "10001" "00001" "00010" "00100" "01000" "11111"//2
    "01110" "10001" "00001" "00110" "00001" "10001" "01110"//3
    "00010" "00110" "01010" "10010" "11111" "00010" "00111"//4
    "11111" "10000" "11110" "00001" "00001" "10001" "01110"//5
    "01110" "10001" "10000" "11110" "10001" "10001" "01110"//6
    "11111" "10001" "00010" "00010" "00100" "00100" "00100"//7
    "01110" "10001" "10001" "01110" "10001" "10001" "01110"//8
    "01110" "10001" "10001" "01111" "00001" "00001" "01110"//9
    "00000" "01100" "01100" "00000" "01100" "01100" "00000"//:
    "11111" "11111" "11111" "11111" "11111" "11111" "11111"//
    "11111" "11111" "11111" "11111" "11111" "11111" "11111"//
    "00000" "00000" "11111" "00000" "11111" "00000" "00000"//=
    "11111" "11111" "11111" "11111" "11111" "11111" "11111"//
    "01110" "10001" "10001" "00010" "00100" "00000" "00100"//?
    "11111" "11111" "11111" "11111" "11111" "11111" "11111"//
    "01110" "10001" "10001" "11111" "10001" "10001" "10001"//A
    "11110" "10001" "10001" "11110" "10001" "10001" "11110"//B
    "01110" "10001" "10000" "10000" "10000" "10001" "01110"//C
    "11110" "10001" "10001" "10001" "10001" "10001" "11110"//D
    "11111" "10000" "10000" "11110" "10000" "10000" "11111"//E
    "11111" "10000" "10000" "11110" "10000" "10000" "10000"//F
    "01110" "10001" "10000" "10111" "10001" "10001" "01110"//G
    "10001" "10001" "10001" "11111" "10001" "10001" "10001"//H
    "01110" "00100" "00100" "00100" "00100" "00100" "01110"//I
    "00001" "00001" "00001" "00001" "10001" "10001" "01110"//J
    "10001" "10010" "10100" "11000" "10100" "10010" "10001"//K
    "10000" "10000" "10000" "10000" "10000" "10000" "11111"//L
    "10001" "11011" "10101" "10101" "10001" "10001" "10001"//M
    "10001" "10001" "11001" "10101" "10011" "10001" "10001"//N
    "01110" "10001" "10001" "10001" "10001" "10001" "01110"//O
    "11110" "10001" "10001" "11110" "10000" "10000" "10000"//P
    "01110" "10001" "10001" "10001" "10101" "10010" "01101"//Q
    "11110" "10001" "10001" "11110" "10100" "10010" "10001"//R
    "01111" "10000" "10000" "01110" "00001" "00001" "11110"//S
    "11111" "00100" "00100" "00100" "00100" "00100" "00100"//T
    "10001" "10001" "10001" "10001" "10001" "10001" "01110"//U
    "10001" "10001" "10001" "10001" "10001" "01010" "00100"//V
    "10001" "10001" "10001" "10101" "10101" "10101" "01010"//W
    "10001" "10001" "01010" "00100" "01010" "10001" "10001"//X
    "10001" "10001" "10001" "01010" "00100" "00100" "00100"//Y
    "11111" "00001" "00010" "00100" "01000" "10000" "11111";//Z
	
	For (i,46) For (j,7) For (k,5) mMtxFont[i+45][j][k] = F0[35*i+5*j+k];
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void Game::Draw_MtxText(float x, float y, const char *fmt,...){
	//--------------------
	glPushMatrix();
	glLoadIdentity();
    //--------------------
	char text[256]; va_list	ap;
	if (fmt == NULL) return;
	va_start(ap, fmt); vsprintf_s(text, fmt, ap); va_end(ap);
	//--------------------
    int n = 0;
	glPointSize(2.f);
    glBegin(GL_POINTS);
	while (text[n] != 0){
		Draw_MtxFont(x+14.f*float(n), y, text[n]);
		n++;
	}
    glEnd();
    //--------------------
	glPopMatrix();
    //--------------------
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void inline Game::Draw_MtxFont(float x, float y, Uint8 c){
	if (c == ' ') return;	
    For (m,7) For (n,5){
        if (mMtxFont[c][m][n] == '0') continue;
		glVertex2f(x+2*n,y+2*m);
	}
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
