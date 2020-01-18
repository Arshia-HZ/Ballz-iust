#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std ;
#include "obj.h"
Obj play ;
Obj high ;
Obj about ;
Obj ball ;
Obj settings ;
int mousex,mousey ;
bool r = true ;
void WriteMessage(const char * msg , int x , int y , int r , int g , int b , int size,SDL_Renderer* ren) {
  SDL_Surface* surf ;
  SDL_Texture* tex ;
  TTF_Font* font = TTF_OpenFont("GTA.ttf",size);
  SDL_Color color ;
  color.r = r ;
  color.g = g ;
  color.b = b ;
  color.a = 255 ;
  SDL_Rect rect ;
  surf = TTF_RenderText_Solid(font,msg,color);
  tex = SDL_CreateTextureFromSurface(ren,surf);
  rect.x=x;
  rect.y=y;
  rect.w=surf->w;
  rect.h=surf->h;
  SDL_FreeSurface(surf);
  SDL_RenderCopy(ren,tex,NULL,&rect);
  SDL_DestroyTexture(tex);
}
void input() {
  SDL_Event e ;
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex,&mousey) ;
    if (e.type == SDL_QUIT) {
      r = false ;
      SDL_Quit();
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        r = false ;
        SDL_Quit();
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex>=play.dest.x)&&(mousex<=play.dest.x+play.dest.w)&&(mousey>=play.dest.y)&&(mousey<=play.dest.y+play.dest.h)) {
        cout << "Play Clicked" << endl ;
        // Open The Game Page
      }
      if ((mousex>=settings.dest.x)&&(mousex<=settings.dest.x+settings.dest.w)&&(mousey>=settings.dest.y)&&(mousey<=settings.dest.y+settings.dest.h)) {
        cout << "settings Clicked" << endl ;
        // Open The settings Page
      }
      if ((mousex>=about.dest.x)&&(mousex<=about.dest.x+about.dest.w)&&(mousey>=about.dest.y)&&(mousey<=about.dest.y+about.dest.h)) {
        cout << "about Clicked" << endl ;
        // Open The aboutUs Page
      }
      if ((mousex>=ball.dest.x)&&(mousex<=ball.dest.x+ball.dest.w)&&(mousey>=ball.dest.y)&&(mousey<=ball.dest.y+ball.dest.h)) {
        cout << "ball Clicked" << endl ;
        // Open The Balls Page
      }
      if ((mousex>=high.dest.x)&&(mousex<=high.dest.x+high.dest.w)&&(mousey>=high.dest.y)&&(mousey<=high.dest.y+high.dest.h)) {
        cout << "high Clicked" << endl ;
        // Open The highscoe Page
      }
    }
  }
}
int main(){
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  SDL_Renderer* ren ;
  SDL_Window* win ;
  SDL_CreateWindowAndRenderer(350,600,0,&win,&ren);
  SDL_SetWindowTitle(win,"Swipe Brick Breaker");
  SDL_Rect rect ;
  rect.x = 0 ;
  rect.y = 0 ;
  rect.w = 350 ;
  rect.h = 600 ;
  // play
  play.setDest(100,225,150,150);
  play.setSource(0,0,1500,1500);
  play.setImage("play.png",ren) ;
  // settings
  settings.setDest(180,490,70,70);
  settings.setSource(0,0,1500,1500);
  settings.setImage("play.png",ren) ;
  // about
  about.setDest(20,415,70,70);
  about.setSource(0,0,1500,1500);
  about.setImage("play.png",ren) ;
  // high
  high.setDest(260,415,70,70);
  high.setSource(0,0,1500,1500);
  high.setImage("play.png",ren) ;
  // ball
  ball.setDest(100,490,70,70);
  ball.setSource(0,0,1500,1500);
  ball.setImage("play.png",ren) ;

  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (r) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    SDL_SetRenderDrawColor(ren,255-(hei/2.7),148-(hei/2.7),194-(hei/2.7),255);
    SDL_RenderFillRect(ren,&rect);

    SDL_RenderCopyEx(ren,play.tex,&play.src,&play.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,settings.tex,&settings.src,&settings.dest,0+rot,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,about.tex,&about.src,&about.dest,0+rot,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,high.tex,&high.src,&high.dest,0+rot,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,ball.tex,&ball.src,&ball.dest,0+rot,NULL,SDL_FLIP_NONE);

    rot += 2 ;
    if (down) {
      WriteMessage("Swipe Brick Breaker",18,10+hei,155,0,0,35,ren);
    } else {
      WriteMessage("Swipe Brick Breaker",18,10+hei,142,0,56,35,ren);
    }
    pos = 10 + hei ;
    if (down) {
      if (pos >= 170) {
        down = false ;
        hei -= sh ;
      } else {
        hei += sh ;
      }
    } else {
      if (pos <= 10) {
        down = true ;
        hei += sh ;
      } else {
        hei -= sh ;
      }
    }
    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/15)) {
      SDL_Delay((1000/15)-timerFPS);
    }

    SDL_RenderPresent(ren);
    input();
  }
  return 0 ;
}
