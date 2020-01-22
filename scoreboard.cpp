Obj back_sm,clear_sm ;
SDL_Renderer* ren_sb;
SDL_Surface* surf_sb ;
bool running_sb = true ;
void input_sb(int lastpage = 0) {
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex,&mousey) ;
    if (e.type == SDL_QUIT) {
      running_sb = false ;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        running_sb = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex>=back_sm.dest.x)&&(mousex<=back_sm.dest.x+back_sm.dest.w)&&(mousey>=back_sm.dest.y)&&(mousey<=back_sm.dest.y+back_sm.dest.h)) {
        //cout << "Play Clicked" << endl ;
        status = 2;
      //  SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren_sb);
        running_sb = false;
        return;
        // Open The Game Page
      }
      if ((mousex>=clear_sm.dest.x)&&(mousex<=clear_sm.dest.x+clear_sm.dest.w)&&(mousey>=clear_sm.dest.y)&&(mousey<=clear_sm.dest.y+clear_sm.dest.h)) {
        status = 1;
      //  SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren_sb);
        running_sb = false;
        return;
      //  SDL_DestroySurface(surf_sb);
        // Open The settings Page
      }
    }
  }
}
// 0 = firstmenu | 1 = lastmenu
void scoreboard(int lastpage = 0){
  running_sb = true ;
  bool showingscore = false;
  returnscore();
  ren_sb = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  string playerinfo[10];
  SDL_Rect rect_sb ;
  rect_sb.x = 0 ;
  rect_sb.y = 0 ;
  rect_sb.w = 350 ;
  rect_sb.h = 600 ;
  // play
  play.setDest(100,500,70,70);
  play.setSource(0,0,1500,1500);
  play.setImage("data/play.png",ren_sb) ;
  // settings
  settings.setDest(200,500,70,70);
  settings.setSource(0,0,1500,1500);
  settings.setImage("data/play.png",ren_sb) ;

  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (running_sb) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    if(!showingscore){
      for(register int i = 0;i<10;i++){
        cout<<"enter";
        playerinfo[i] = to_string(i+1) + " " + player[i].name + ": " + to_string(player[i].score);
    //  WriteMessage(playerinfo[i].c_str(),18,10+i*20,155,0,0,35,ren_sb,surf_sb);
    }
    showingscore=true;
    }
    SDL_SetRenderDrawColor(ren_sb,255-(hei/2.7),148-(hei/2.7),194-(hei/2.7),255);
    SDL_RenderFillRect(ren_sb,&rect_sb);

    SDL_RenderCopyEx(ren_sb,play.tex,&play.src,&play.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sb,settings.tex,&settings.src,&settings.dest,0+rot,NULL,SDL_FLIP_NONE);


    rot += 2 ;
    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/10)) {
      SDL_Delay((1000/10)-timerFPS);
    }

    SDL_RenderPresent(ren_sb);
    input_sb();
  }
}
