//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include "Game.h"
#include "Time.h"
Game G;

//----------------------------------
SDL_Window * gScreen;
//----------------------------------

//---------------------------------------------------------------------
//---------------------------------------------------------------------
static void initAttributes(){
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);//Depth Buffer 24-bit
    SDL_GL_SetSwapInterval(1);//Enable Vsync
    //----------------------------------
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
static void createSurface(){
	SDL_Init(SDL_INIT_EVERYTHING);
    initAttributes();//Context Attr
    gScreen = SDL_CreateWindow("GFX",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               G.mW, G.mH,
                               SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(gScreen);
    //----------------------------------
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
static void mainLoop (){
    SDL_Event event;
    bool quit = false;
    int key, state;
    Time time;
    int timeAcummumulator = 0;
    int refreshRate = 1; // The closer to 1 the faster it is.
    while (!quit) {
       time.Update();
        //----------------------------------
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
					//Keys
				case SDL_KEYDOWN:
                    key   = event.key.keysym.sym;
                    state = SDL_GetModState();
					//---------------------------------
                    if (key == SDLK_ESCAPE){quit = true; break;}
                    //---------------------------------
					if (key < 128) G.NormalKeys(key,state);
					else G.SpecialKeys(key,state);
					break;
            case SDL_KEYUP:
               key = event.key.keysym.sym;
               state = SDL_GetModState();
               G.SpecialKeys(key, KEY_RELEASED);
               break;
					//---------------------------------
				case SDL_QUIT: quit = true; break;
				default: break;
			}
        }
        //----------------------------------
      timeAcummumulator += time.deltaTime;
      while (timeAcummumulator > refreshRate)
      {
      G.CheckCollision(refreshRate);
      G.Update(1);
      timeAcummumulator -= refreshRate;
      }

      G.Draw(time.deltaTime);
      SDL_GL_SwapWindow(gScreen);

        //----------------------------------
	}
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
int main(int argc, char *argv[]){
	createSurface();
	G.ChangeSize(G.mW, G.mH);
	glClearColor(0.f,0.f,0.2f,1.f);
	mainLoop();
	return 0;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------



