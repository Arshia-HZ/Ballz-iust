#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std ;

int main(){
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Renderer* ren ;
  SDL_Window* win ;
  SDL_CreateWindowAndRenderer(800,600,0,&win,&ren);
  SDL_SetWindowTitle(win,"SwipeBrickBreaker");
  SDL_SetRenderDrawColor(ren,255,0,0,255);
  SDL_Rect rect ;
  rect.x = 0 ;
  rect.y = 0 ;
  rect.w = 800 ;
  rect.h = 600 ;
  SDL_Rect dest;
  dest.x=50;
  dest.y=50;
  dest.w=600;
  dest.h=400;
  SDL_Rect src;
  src.x=0;
  src.y=0;
  src.w=600;
  src.h=400;
  SDL_Texture* tex ;
  string fn = "Ball.png";
  SDL_Surface* surf = IMG_Load(fn.c_str());
  tex = SDL_CreateTextureFromSurface(ren,surf);

  bool r = true ;
  while (r) {
    SDL_RenderFillRect(ren,&rect);
    SDL_RenderCopyEx(ren,tex,&src,&dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderPresent(ren);
    SDL_Delay(3000);
    SDL_Quit();
    break ;
  }
  return 0 ;
}
