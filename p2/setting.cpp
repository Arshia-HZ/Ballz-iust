#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std ;
class object
{
public:
  SDL_Rect origin;
  SDL_Rect obj;
  SDL_Texture* tx;
  void sizeorigin(int x,int y,int w,int h)
  {
    origin.x=x;
    origin.y=y;
    origin.w=w;
    origin.h=h;
  }

  void sizeobj(int x,int y,int w,int h) {
      obj.x=x;
      obj.y=y;
      obj.w=w;
      obj.h=h;
  }

  void creatpic(string f , SDL_Renderer* ren) {
    SDL_Surface* surf = IMG_Load(f.c_str());
    tx = SDL_CreateTextureFromSurface(ren,surf);
  }
};
bool b=true;
int x1;
int y2;
object back,high,sound;
  void in2()
  {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      SDL_GetMouseState(&x1,&y2);
      if (ev.type == SDL_QUIT) {
        b = false ;
        SDL_Quit();
      }

      if (ev.type == SDL_KEYDOWN) {
        if(ev.key.keysym.sym == SDLK_ESCAPE) {
          b = false ;
          SDL_Quit();
        }

        if(ev.key.keysym.sym==SDL_MOUSEBUTTONDOWN)
        {
          if ((x1>=high.origin.x)&&(x1<=high.origin.x+high.origin.w)&&(y2>=high.origin.y)&&(y2=high.origin.y+high.origin.h)) {
            cout << "high Clicked" << endl ;
            // Open The Game Page
          }
          if ((x1>=sound.origin.x)&&(x1<=sound.origin.x+sound.origin.w)&&(y2>=sound.origin.y)&&(y2<=sound.origin.y+sound.origin.h)) {
            cout << "sound Clicked" << endl ;
            // Open The settings Page
          }
          if ((x1>=back.origin.x)&&(x1<=back.origin.x+back.origin.w)&&(y2>=back.origin.y)&&(y2<=back.origin.y+back.origin.h)) {
            cout << "back Clicked" << endl ;
            // Open The aboutUs Page
          }
          }
        }
      }
    }


int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Renderer* r2;
  SDL_Window* w2;
  SDL_CreateWindowAndRenderer(350,600,0,&w2,&r2);
  SDL_SetWindowTitle(w2,"protject");


SDL_Rect r4;
  r4.x = 0 ;
  r4.y = 0 ;
  r4.w = 350 ;
  r4.h = 600 ;
  return 0;

  back.sizeorigin(80,120,200,200);
  back.sizeobj(0,0,2000,2000);
  back.creatpic("play.png",r2);

  high.sizeorigin(140,150,200,200);
  high.sizeobj(0,0,2000,2000);
  high.creatpic("play.png",r2);

  sound.sizeorigin(200,180,200,200);
  sound.sizeobj(0,0,2000,2000);
  sound.creatpic("play.png",r2);

  while (b) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    /*static*/ int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    double i=0;
    SDL_SetRenderDrawColor(r2,255-(i/2.7),148-(i/2.7),194-(i/2.7),255);
    SDL_RenderFillRect(r2,&r4);
    SDL_RenderCopyEx(r2,back.tx,&back.obj,&back.origin,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(r2,sound.tx,&sound.obj,&sound.origin,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(r2,high.tx,&high.obj,&high.origin,0,NULL,SDL_FLIP_NONE);

    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/15)) {
      SDL_Delay((1000/15)-timerFPS);
    }
    SDL_RenderPresent(r2);
    in2();
  }
}
