Obj us,he ;
SDL_Renderer* ren_about=NULL;
SDL_Renderer* ren_about_he=NULL;
bool running_about = true ;
SDL_Window* win_us ;
SDL_Window* win_he;
SDL_Event about_event;
void input_about() {
  //  PrintKeyInfo( &e.key );
  while (SDL_PollEvent(&about_event)) {
    SDL_GetMouseState(&mousex,&mousey) ;
    if (about_event.type == SDL_QUIT) {
      running_about = false ;
      //windowloop = false;
      SDL_DestroyRenderer(ren_about_he);
      SDL_DestroyWindow(win_he);
      SDL_DestroyRenderer(ren_about);
      SDL_DestroyWindow(win_us);

      //status = 0;
      //SDL_Quit();
    }
    if (about_event.type == SDL_KEYDOWN) {
      if(about_event.key.keysym.sym == SDLK_ESCAPE) {
        running_about = false;
        //windowloop = false;
        SDL_DestroyRenderer(ren_about_he);
        SDL_DestroyWindow(win_he);
        SDL_DestroyRenderer(ren_about);
        SDL_DestroyWindow(win_us);

    //    status = 0;
        //SDL_Quit();
      }
    }
  }
}
void about_us(){

  running_about = true ;
  SDL_CreateWindowAndRenderer(750,1000,0,&win_he,&ren_about_he);
SDL_CreateWindowAndRenderer(970,1296,0,&win_us,&ren_about);


  SDL_Rect rect_about ;
  SDL_Rect rect_about_he ;
  rect_about.x = 0 ;
  rect_about.y = 0 ;
  rect_about.w = 970 ;
  rect_about.h = 1296 ;
  rect_about_he.x = 0 ;
  rect_about_he.y = 0 ;
  rect_about_he.w = 750 ;
  rect_about_he.h = 1000 ;
  // play
  us.setDest(0,0,970,1296);
  us.setSource(0,0,970,1296);
  us.setImage("data/us.png",ren_about) ;
   //settings
  he.setDest(0,0,750,1000);
  he.setSource(0,0,750,1000);
  he.setImage("data/he.png",ren_about_he) ;

  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (running_about) {
    SDL_SetRenderDrawColor(ren_about_he,255,255,255,255);
    SDL_RenderFillRect(ren_about,&rect_about_he);
    SDL_SetRenderDrawColor(ren_about,255,255,255,255);
    SDL_RenderFillRect(ren_about,&rect_about);
    SDL_RenderCopyEx(ren_about,us.tex,&us.src,&us.dest,0,NULL,SDL_FLIP_NONE);

    SDL_RenderCopyEx(ren_about_he,he.tex,&he.src,&he.dest,0,NULL,SDL_FLIP_NONE);

      SDL_RenderPresent(ren_about);
SDL_RenderPresent(ren_about_he);


    input_about();
  }
  status = 0;
}
