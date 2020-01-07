#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std ;
class Obj {
  public :
  SDL_Rect dest ;
  SDL_Rect src;
  SDL_Texture* tex ;
  void setDest(int x , int y , int w , int h) {
    dest.x = x ;
    dest.y = y ;
    dest.w = w ;
    dest.h = h ;
  }
  void setSource(int x , int y , int w , int h) {
    src.x = x ;
    src.y = y ;
    src.w = w ;
    src.h = h ;
  }
  void setImage(string filename , SDL_Renderer* ren) {
    SDL_Surface* surf = IMG_Load(filename.c_str());
    tex = SDL_CreateTextureFromSurface(ren,surf);
  }
};
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
  Obj ball ;
  ball.setDest(50,50,600,400);
  ball.setSource(0,0,600,400);
  ball.setImage("Ball.png",ren) ;
  bool r = true ;
  while (r) {
    SDL_RenderFillRect(ren,&rect);
    SDL_RenderCopyEx(ren,ball.tex,&ball.src,&ball.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderPresent(ren);
    SDL_Delay(3000);
    SDL_Quit();
    break ;
  }
  return 0 ;
}
