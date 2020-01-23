Obj us,he ;
SDL_Renderer* ren_about=NULL;
SDL_Surface* surf_about =NULL;
bool running_about = true ;
SDL_Window* win_us ;
SDL_Window* win_he;
void input_about() {
  //  PrintKeyInfo( &e.key );
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex,&mousey) ;
    if (e.type == SDL_QUIT) {
      status = 0;
      running_about = false ;
      //windowloop = false;
      SDL_DestroyRenderer(ren_about);
      SDL_DestroyWindow(win_us);
      //SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        status = 0;
        running_about = false;
        //windowloop = false;
        SDL_DestroyRenderer(ren_about);
        SDL_DestroyWindow(win_us);

        //SDL_Quit();
        return;
      }
    }
  }
}
void about_us(){

  running_about = true ;

  //ren_about = SDL_CreateWindowAndRenderer(win_us, -1, SDL_RENDERER_ACCELERATED);
  SDL_CreateWindowAndRenderer(970,1296,0,&win_us,&ren_about);
  SDL_Rect rect_about ;
  rect_about.x = 0 ;
  rect_about.y = 0 ;
  rect_about.w = 970 ;
  rect_about.h = 1296 ;
  // play
  us.setDest(0,0,970,1296);
  us.setSource(0,0,970,1296);
  us.setImage("data/us.png",ren_about) ;
  // settings
  /*he.setDest(180,490,70,70);
  he.setSource(0,0,1500,1500);
  he.setImage("data/setting3.png",ren_about) ;*/

  float hei = 0 ;
  bool down = true ;
  float sh = 2.2 ;
  float pos = 0 ;
  float rot = 0 ;
  while (running_about) {

    SDL_SetRenderDrawColor(ren_about,255,255,255,255);
    SDL_RenderFillRect(ren_about,&rect_about);

    SDL_RenderCopyEx(ren_about,us.tex,&us.src,&us.dest,0,NULL,SDL_FLIP_NONE);
    //SDL_RenderCopyEx(ren_about,settings.tex,&settings.src,&settings.dest,0,NULL,SDL_FLIP_NONE);

    SDL_RenderPresent(ren_about);
    input_about();
  }
}
