Obj playagain_lm,highscore_lm,firstmenu_lm ;
SDL_Renderer* ren_lm;
SDL_Surface* surf_lm ;
bool running_lm = true ;
void input_lm() {
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex,&mousey) ;
    if (e.type == SDL_QUIT) {
      running_lm = false ;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        running_lm = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex>=playagain_lm.dest.x)&&(mousex<=playagain_lm.dest.x+playagain_lm.dest.w)&&(mousey>=playagain_lm.dest.y)&&(mousey<=playagain_lm.dest.y+playagain_lm.dest.h)) {
        status = 2;
        SDL_DestroyRenderer(ren_lm);
        running_lm = false;
        return;
      }
      if ((mousex>=highscore_lm.dest.x)&&(mousex<=highscore_lm.dest.x+highscore_lm.dest.w)&&(mousey>=highscore_lm.dest.y)&&(mousey<=highscore_lm.dest.y+highscore_lm.dest.h)) {
      //  status = 1;
      //  SDL_DestroyRenderer(ren_lm);
      //  running_lm = false;
      //  return;
      cout<<"highscore_lm clicked";
      }
      if ((mousex>=firstmenu_lm.dest.x)&&(mousex<=firstmenu_lm.dest.x+firstmenu_lm.dest.w)&&(mousey>=firstmenu_lm.dest.y)&&(mousey<=firstmenu_lm.dest.y+firstmenu_lm.dest.h)) {
        status = 0;
        SDL_DestroyRenderer(ren_lm);
        running_lm = false;
        return;
      }
    /*  if ((mousex>=ball.dest.x)&&(mousex<=ball.dest.x+ball.dest.w)&&(mousey>=ball.dest.y)&&(mousey<=ball.dest.y+ball.dest.h)) {
        cout << "ball Clicked" << endl ;
        // Open The Balls Page
      }
      if ((mousex>=high.dest.x)&&(mousex<=high.dest.x+high.dest.w)&&(mousey>=high.dest.y)&&(mousey<=high.dest.y+high.dest.h)) {
        cout << "high Clicked" << endl ;
        // Open The highscoe Page
      }
    }*/
  }
}
}
void lastmenu(){
  running_lm = true ;
  //SDL_Window* win ;
  ren_lm = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  //SDL_CreateWindowAndRenderer(350,600,0,&win,&ren_lm);
  SDL_Rect rect_fm ;
  rect_fm.x = 0 ;
  rect_fm.y = 0 ;
  rect_fm.w = 350 ;
  rect_fm.h = 600 ;
  // playagain_lm
  playagain_lm.setDest(100,225,150,150);
  playagain_lm.setSource(0,0,1500,1500);
  playagain_lm.setImage("data/play.png",ren_lm) ;
  // firstmenu_lm
  highscore_lm.setDest(180,490,70,70);
  highscore_lm.setSource(0,0,1500,1500);
  highscore_lm.setImage("data/play.png",ren_lm) ;
  // highscore_lms
  firstmenu_lm.setDest(20,415,70,70);
  firstmenu_lm.setSource(0,0,1500,1500);
  firstmenu_lm.setImage("data/play.png",ren_lm) ;
  /* high
  high.setDest(260,415,70,70);
  high.setSource(0,0,1500,1500);
  high.setImage("data/playagain_lm.png",ren_lm) ;
  // ball
  ball.setDest(100,490,70,70);
  ball.setSource(0,0,1500,1500);
  ball.setImage("data/playagain_lm.png",ren_lm) ;
*/
  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (running_lm) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    SDL_SetRenderDrawColor(ren_lm,255-(hei/2.7),148-(hei/2.7),194-(hei/2.7),255);
    SDL_RenderFillRect(ren_lm,&rect_fm);

    SDL_RenderCopyEx(ren_lm,playagain_lm.tex,&playagain_lm.src,&playagain_lm.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_lm,highscore_lm.tex,&highscore_lm.src,&highscore_lm.dest,0+rot,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_lm,firstmenu_lm.tex,&firstmenu_lm.src,&firstmenu_lm.dest,0+rot,NULL,SDL_FLIP_NONE);
    //SDL_RenderCopyEx(ren_lm,high.tex,&high.src,&high.dest,0+rot,NULL,SDL_FLIP_NONE);
    //SDL_RenderCopyEx(ren_lm,ball.tex,&ball.src,&ball.dest,0+rot,NULL,SDL_FLIP_NONE);

    rot += 2 ;
    if (down) {
      WriteMessage("Swipe Brick Breaker",18,10+hei,155,0,0,35,ren_lm);
    } else {
      WriteMessage("Swipe Brick Breaker",18,10+hei,142,0,56,35,ren_lm);
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
    if (timerFPS < (1000/10)) {
      SDL_Delay((1000/10)-timerFPS);
    }

    SDL_RenderPresent(ren_lm);
    input_lm();
  }
}
