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
}
        if(ev.key.keysym.sym==SDL_MOUSEBUTTONDOWN)
        {
          if ((x1>=high.origin.x)&&(x1<=high.origin.x+high.origin.w)&&(y2>=high.origin.y)&&(y2<=high.origin.y+high.origin.h)) {
            cout << "high Clicked" << endl ;
          }
          if ((x1>=sound.origin.x)&&(x1<=sound.origin.x+sound.origin.w)&&(y2>=sound.origin.y)&&(y2<=sound.origin.y+sound.origin.h)) {
            cout << "sound Clicked" << endl ;
          }
          if ((x1>=back.origin.x)&&(x1<=back.origin.x+back.origin.w)&&(y2>=back.origin.y)&&(y2<=back.origin.y+back.origin.h)) {
            cout << "back Clicked" << endl ;
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
/*SDL_Surface* surf ;
  SDL_Texture* tex ;
  TTF_Font* font = TTF_OpenFont("GTA.ttf",8);
  SDL_Color color ;
  color.r = 0 ;
  color.g = 0 ;
  color.b = 142 ;
  color.a = 255 ;
  SDL_Rect rect ;
  surf = TTF_RenderText_Solid(font,"project",color);
  tex = SDL_CreateTextureFromSurface(r2,surf);
  rect.x=20;
  rect.y=20;
  rect.w=surf->w;
  rect.h=surf->h;
  SDL_FreeSurface(surf);
  SDL_RenderCopy(r2,tex,NULL,&rect);
  SDL_DestroyTexture(tex);*/


  back.sizeorigin(30,300,60,60);
  back.sizeobj(0,0,2000,2000);
  back.creatpic("setting.png",r2);

  high.sizeorigin(110,160,140,140);
  high.sizeobj(0,0,2000,2000);
  high.creatpic("setting.png",r2);

  sound.sizeorigin(270,300,60,60);
  sound.sizeobj(0,0,2000,2000);
  sound.creatpic("setting.png",r2);

  while (b) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    /*static*/ int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    double i=0;
    SDL_SetRenderDrawColor(r2,255-(i/2.7),210-(i/2.7),240-(i/2.7),150);
    SDL_RenderFillRect(r2,&r4);
    SDL_RenderCopyEx(r2,back.tx,&back.obj,&back.origin,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(r2,sound.tx,&sound.obj,&sound.origin,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(r2,high.tx,&high.obj,&high.origin,0,NULL,SDL_FLIP_NONE);

    framecount++ ;
    static int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/15)) {
      SDL_Delay((1000/15)-timerFPS);
    }
    SDL_RenderPresent(r2);
    in2();
  }
  return 0;
}
