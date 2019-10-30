//---------------------------------------------------------------------
//---------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------
#include <cmath>
#include <SDL.h>
#include <SDL_opengl.h>
#include <Ball.h>
#include <Wall.h>
#include <Flipper.h>

//#include <OpenGL/glu.h>
//---------------------------------------------------------------------
#define For(i,N) for (int (i) = 0; (i) < (N); (i)++)



//---------------------------------------------------------------------

enum KeyState {
   KEY_DOWN,
   KEY_PRESSED,
   KEY_RELEASED,
   DEFAULT
};

//---------------------------------------------------------------------
class Game {
public:
    //-------------------------------------------------------
    Game(void);
    //-------------------------------------------------------
    void  ChangeSize(int w, int h);
    void CheckCollision(int deltaTime);
    void Update(int deltaTime);
    void  Draw(int deltaTime);
    //-------------------------------------------------------
    void  NormalKeys(unsigned char key, int state);
    void  SpecialKeys(int key, int state);
    void SpecialKeys(int key, KeyState state);
    void  Mouse(int button, int state, int x, int y);
    void  MouseMotion(int x, int y);
    //-------------------------------------------------------
	void  InitMtxFont();
	void  Draw_MtxText(float x, float y, const char *fmt,...);
	void  Draw_MtxFont(float x, float y, Uint8 c);
    //-------------------------------------------------------
    float mW, mH;
    int   mCounter;
    int   mMouseX, mMouseY, mMouseMotionX, mMouseMotionY;
    int   mMouseButton, mMouseState;
    //-------------------------------------------------------
    char  (*mMtxFont)[7][5];
    //-------------------------------------------------------

    Ball mBall;
    Wall mWall1;
    Wall mWall2;
    Flipper mFlipper1;
    Flipper mFlipper2;

    Wall mWallSquare1; // Hade varit smart om vi gjorde så att våra väggar tillät segment
    Wall mWallSquare2;
    Wall mWallSquare3;
    Wall mWallSquare4;

    KeyState mLeft;
    KeyState mRight;
};
//---------------------------------------------------------------------
//---------------------------------------------------------------------
