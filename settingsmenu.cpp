Obj high_sm,about_sm, ball_sm ;
int mousex_sm,mousey_sm ;
SDL_Renderer* ren_sm ;
bool smenu = true ;
void input_sm() {
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex_sm,&mousey_sm) ;
    if (e.type == SDL_QUIT) {
      smenu = false ;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        smenu = false ;
        windowloop = false;
       SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex_sm>=play.dest.x)&&(mousex_sm<=play.dest.x+play.dest.w)&&(mousey_sm>=play.dest.y)&&(mousey_sm<=play.dest.y+play.dest.h)) {
        cout << "Audio Clicked" << endl ;
        bool musicstatus = checkaudio();
        if(musicstatus){
          stopaudio();
        }else{
          startaudio();
        }
        // Open The Game Page
      }

      if ((mousex_sm>=about_sm.dest.x)&&(mousex_sm<=about_sm.dest.x+about_sm.dest.w)&&(mousey_sm>=about_sm.dest.y)&&(mousey_sm<=about_sm.dest.y+about_sm.dest.h)) {
        cout << "Clear Highscore Clicked" << endl ;
        openfile(true);
        cout<<"High score cleared"<<endl;
        // Open The about_smUs Page
      }
      if ((mousex_sm>=ball_sm.dest.x)&&(mousex_sm<=ball_sm.dest.x+ball_sm.dest.w)&&(mousey_sm>=ball_sm.dest.y)&&(mousey_sm<=ball_sm.dest.y+ball_sm.dest.h)) {
      //  SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren_sm);
        smenu = false;
        status = 0;
        return;

      }

    }
  }
}
void settingsmenu(){
  smenu = true ;
  ren_sm = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect rect ;
  rect.x = 0 ;
  rect.y = 0 ;
  rect.w = 350 ;
  rect.h = 600 ;
  // play
  play.setDest(150,100,70,70);
  play.setSource(0,0,1500,1500);
  play.setImage("data/sound.png",ren_sm) ;
  // settings_sm
  // about_sm
  about_sm.setDest(150,225,70,70);
  about_sm.setSource(0,0,1500,1500);
  about_sm.setImage("data/highscore_setting.png",ren_sm) ;
  // high_sm

  // ball_sm
  ball_sm.setDest(150,475,70,70);
  ball_sm.setSource(0,0,1500,1500);
  ball_sm.setImage("data/back_icon.png",ren_sm) ;

  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (smenu) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    SDL_SetRenderDrawColor(ren_sm,255,255,255,255);
    SDL_RenderFillRect(ren_sm,&rect);

    SDL_RenderCopyEx(ren_sm,play.tex,&play.src,&play.dest,0,NULL,SDL_FLIP_NONE);
    //SDL_RenderCopyEx(ren_sm,settings_sm.tex,&settings_sm.src,&settings_sm.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sm,about_sm.tex,&about_sm.src,&about_sm.dest,0,NULL,SDL_FLIP_NONE);
  //  SDL_RenderCopyEx(ren_sm,high_sm.tex,&high_sm.src,&high_sm.dest,0+rot,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sm,ball_sm.tex,&ball_sm.src,&ball_sm.dest,0,NULL,SDL_FLIP_NONE);
    rot += 2 ;

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
    if (timerFPS < (1000/60)) {
      SDL_Delay((1000/60)-timerFPS);
    }

    SDL_RenderPresent(ren_sm);
    input_sm();
  }
}
