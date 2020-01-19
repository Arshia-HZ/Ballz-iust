#include <vector>
Obj Speed , Pause , Highscore , Score , UpBar , BtBar , ballcount;
vector <Obj> blGame ;
vector <Obj> brick ;
vector <Obj> Addball ;
int mousex_game,mousey_game ;
bool running_game = true ;
SDL_Renderer* ren_game;
SDL_Surface* surf_game ;
void WriteMessage_game(const char * msg , int x , int y , int r , int g , int b , int size,SDL_Renderer* ren_fm) {

  TTF_Font* font = TTF_OpenFont("data/GTA.ttf",size);
  SDL_Color color_fm ;
  color_fm.r = r ;
  color_fm.g = g ;
  color_fm.b = b ;
  color_fm.a = 255 ;
  SDL_Rect rect_fm ;
  surf_fm = TTF_RenderText_Solid(font,msg,color_fm);
  tex = SDL_CreateTextureFromSurface(ren_fm,surf_fm);
  rect_fm.x=x;
  rect_fm.y=y;
  rect_fm.w=surf_fm->w;
  rect_fm.h=surf_fm->h;
  SDL_FreeSurface(surf_fm);
  SDL_RenderCopy(ren_fm,tex,NULL,&rect_fm);
  SDL_DestroyTexture(tex);
}

void input_game() {
  SDL_Event e ;
  while (SDL_PollEvent(&e)) {
    SDL_GetMouseState(&mousex_game,&mousey_game) ;
    if (e.type == SDL_QUIT) {
      running_game = false ;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == SDLK_ESCAPE) {
        running_game = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      // nothing
    }
  }
}

void game() {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  running_game = true ;
  ren_game = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect rect_game ;
  rect_game.x = 0 ;
  rect_game.y = 0 ;
  rect_game.w = 350 ;
  rect_game.h = 600 ;

  // Pause
  Pause.setDest(126,11,98,98);
  Pause.setSource(0,0,980,980);
  Pause.setImage("data/Pause.png",ren_game) ;
  // Speed
  Speed.setDest(289,37,46,46);
  Speed.setSource(0,0,512,512);
  Speed.setImage("data/Speed.png",ren_game) ;
  // Score
  Score.setDest(15,10,46,46);
  Score.setSource(0,0,980,980);
  Score.setImage("data/Score.png",ren_game) ;
  // Highscore
  Highscore.setDest(15,64,46,46);
  Highscore.setSource(0,0,512,512);
  Highscore.setImage("data/HighScore.png",ren_game) ;
  // UpBar
  UpBar.setDest(0,120,350,5);
  UpBar.setSource(0,0,200,200);
  UpBar.setImage("data/Black.png",ren_game) ;
  // BtBar
  BtBar.setDest(0,475,350,5);
  BtBar.setSource(0,0,200,200);
  BtBar.setImage("data/Black.png",ren_game) ;
  // ballcount
  ballcount.setDest(10,490,46,46);
  ballcount.setSource(0,0,512,512);
  ballcount.setImage("data/BallCount.png",ren_game) ;

  // running part
  float hei = 0 ;
  while (running_game) {
    int framecount = 0 ;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0 ;
    if (lastframe >= lasttime+1000) {
      lasttime = lastframe ;
      framecount = 0 ;
    }
    SDL_SetRenderDrawColor(ren_game,255-(hei/2.7),148-(hei/2.7),194-(hei/2.7),255);
    SDL_RenderFillRect(ren_game,&rect_game);

    SDL_RenderCopyEx(ren_game,Pause.tex,&Pause.src,&Pause.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,Score.tex,&Score.src,&Score.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,Highscore.tex,&Highscore.src,&Highscore.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,Speed.tex,&Speed.src,&Speed.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,ballcount.tex,&ballcount.src,&ballcount.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,UpBar.tex,&UpBar.src,&UpBar.dest,0,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_game,BtBar.tex,&BtBar.src,&BtBar.dest,0,NULL,SDL_FLIP_NONE);

    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/10)) {
      SDL_Delay((1000/10)-timerFPS);
    }

    SDL_RenderPresent(ren_game);
    input();
  }
}
