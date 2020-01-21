Obj Speed , Pause , Highscore , Score , UpBar , BtBar , ballcount , arrow ;
vector <Obj> blGame ;
double adad ;
bool hity,hitx;
double lasty,lastx ;
double xnew = 165 ,ynew = 455 ;
int counter_brick=1;
int aa = 0 ;
vector <Obj> brick ;
std::vector<int> brick_number;
double shib ;
bool run_ball=false;
double leftx = 165 ;
double centerx = 175 ;
double topy = 455 ;
double centery = 465 ;
bool Unzir = false;
vector <Obj> Addball ;
bool dwn = false , amoud = false , shot = false ; bool run_first=true;
int tedad = 1 ;
int mousex_game,mousey_game,mx,my ;
bool running_game = true ;
SDL_Renderer* ren_game;
SDL_Surface* surf_game ;

bool hit(SDL_Rect r1 , SDL_Rect r2) {
  if (r1.x > r2.x+r2.w) return false ;
  if (r1.x + r1.w < r2.x) return false ;
  if (r1.y > r2.y+r2.h) return false ;
  if (r1.y + r1.h < r2.y) return false ;
  return true ;
}

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
        if ((mousey_game>125) && (mousey_game<475) && (shot == false)) {
          dwn = true ;
        }
    }
    if (e.type == SDL_MOUSEBUTTONUP) {
      if (dwn == true) {
        dwn = false;
        shot = true ;
        run_first = true ;
      }
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
  blGame.push_back(Obj());
  /*
  brick_hit_x.push_back(bool());
  brick_hit_x[0]=false;
  brick_hit_y.push_back(bool());
  brick_hit_y[0]=false;
  */
  blGame[0].setDest(165,455,20,20);
  blGame[0].setSource(0,0,715,715);
  blGame[0].setImage("data/BlueBall.png",ren_game) ;
  brick.push_back(Obj());
  brick[0].setDest(0,165,55,35);
  brick[0].setSource(0,0,600,600);
  brick[0].setImage("data/brick.png",ren_game);
  // Pause
  Pause.setDest(140,25,70,70);
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
  // arrow
  arrow.setDest((blGame[0].dest.x)+((blGame[0].dest.w)/2)-30,(blGame[0].dest.y)+((blGame[0].dest.h)/2)-30,60,60);
  arrow.setSource(0,0,512,512);
  arrow.setImage("data/BlueFlash.png",ren_game) ;
  // running part
  float hei = 0 ;
  while (running_game) {
    SDL_GetMouseState(&mousex_game,&mousey_game) ;
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
    SDL_RenderCopyEx(ren_game,brick[0].tex,&brick[0].src,&brick[0].dest,0,NULL,SDL_FLIP_NONE);
    brick_number.push_back(counter_brick);


    for (int i = 0 ; i < tedad ; i++) {
      SDL_RenderCopyEx(ren_game,blGame[i].tex,&blGame[i].src,&blGame[i].dest,0,NULL,SDL_FLIP_NONE);
    }

    if (shot) {

      static double xx = 0 ;
      static double yy = 0;
      static  double cox=5;
      static  double coy=5;
      if (run_first) {
        mx = mousex_game ;
        my = mousey_game ;
        run_first=false;
        cox=5;
        coy=5;
      }
      if (aa==1) {
        aa--;
        cox/=2;
        coy/=2;
      } else if (aa>1) {
        aa-- ;
      }
    //  std::cout << leftx<<" "<<topy << '\n';
    if (hitx){
      hitx = false ;
    } else {
      lastx = xnew ;
    }
    if (hity){
      hity=false;
    } else {
      lasty = ynew ;
    }
        if (amoud) {
          ynew = (double)(ynew + coy) ;
        } else {
        //  cout << (shib*-1) << " " << atan((shib*-1)) << " " << cos(atan((shib*-1))) << " " << sin(atan((shib*-1))) << endl ;
          if ((shib*-1) > 0) {
              xnew =(double)(xnew + (cox*cos(atan((shib*-1)))) ) ;
              ynew =(double)(ynew + (coy*(-1)*(sin(atan((shib*-1))))) ) ;

          } else {
              xnew =(double)(xnew + (cox*(-1)*(cos(atan((shib*-1))))) ) ;
              ynew =(double)(ynew + (coy*sin(atan((shib*-1)))) ) ;
          }

        }
    //  std::cout << xnew << " " << ynew << endl ;

        /*
        if((ynew>=brick[i].dest.y-4 && ynew<=(brick[i].dest.y+brick[i].dest.h+4))&&((xnew>brick[i].dest.x-5 && xnew<brick[i].dest.x+2) || (xnew>brick[i].dest.x+brick[i].dest.w-5 && xnew<brick[i].dest.x+brick[i].dest.w+6)))
          brick_hit_x=true;
          if((xnew>=brick[i].dest.x-4&& xnew<=(brick[i].dest.x+brick[i].dest.w+4)) && ((ynew>brick[i].dest.y && ynew<brick[i].dest.y+6) || (ynew>brick[i].dest.y+brick[i].dest.h && ynew<brick[i].dest.y+brick[i].dest.h+6)))
          brick_hit_y=true;
        */
      if(ynew>455)
      {
      shot=false;
    }

      if (xnew < 0) {
        cox*=-1;
        //xnew = 0 ;
      }
      if (xnew > 330) {
        cox*=-1;
        //xnew = 330 ;
      }
      if (ynew < 125) {
        coy*=-1;
        //ynew = 125 ;
      }
      /*
      for (int i = 0 ; i<brick_hit_y.size() ; i++) {
        if(brick_hit_y[i]==true)
        {
          brick_hit_y[i]=false;
          coy*=-1;
  }
      }
      for (int i = 0 ; i<brick_hit_x.size() ; i++) {
        if(brick_hit_x[i]==true)
        {
          brick_hit_x[i]=false;
          cox*=-1;
  }
      }
*/
      if (ynew > 455) {
        coy*=-1;
        ynew = 455 ;
      }
      /*
      if(xnew < 0 || xnew > 335 )
      cox*=-1;
      if(ynew < 120 || ynew > 456 )
      coy*=-1;
      */
        if (shot) {
          blGame[0].setDest(xnew,lasty,20,20);
          if(hit(brick[0].dest,blGame[0].dest)) {
              cout<<"hit x"<<lastx<<"   "<<lasty<<"  "<<xnew<<"   "<<ynew<<endl;
              hitx = true ;
              cox *= (-1) ;
            }
              blGame[0].setDest(lastx,ynew,20,20);
              if(hit(brick[0].dest,blGame[0].dest)) {
                  cout<<"hit y"<<lastx<<"   "<<lasty<<"  "<<xnew<<"   "<<ynew<<endl;
                  hity=true ;
                  coy *= (-1) ;
                }
              blGame[0].setDest(xnew,ynew,20,20);
              if ((hitx)&&(hity)) {
                cox *= 2 ;
                coy *= 2 ;
                aa = 4 ;
              }
        } else if (!shot) {
          leftx = xnew;
          centerx = xnew+10 ;
          topy = 455;
          centery = 455+10;
          ynew = 455 ;
          blGame[0].setDest(xnew,455,20,20);
          std::cout << "safe" << xnew << " " << ynew << endl ;
          arrow.setDest(centerx-30,centery-30,60,60);
          int brick_new=rand()%6+1;
          for(int j=blGame.size();j<blGame.size()+brick_new;j++)
          {
          // blGame.push_back(Obj());
        }
          //for(int j=blGame.size();j<blGame.size()+brick_new;j++)
        //  {
        //  blGame.push_back(obj());
      //    blGame[j].setDest()
      //  }


      }
      /*
      if (shot) {
        xx += cox ;
        yy += coy;
      }
      */
    }
    if (dwn == true) {
      if (mousex_game==centerx) {
        amoud = true ;
      } else {
        amoud = false ;
        shib = (double)(mousey_game-centery)/(mousex_game-centerx);
      }
      if (mousey_game>centery) {
        Unzir = true ;
      } else {
        Unzir = false ;
      }
      if (Unzir == false) {
        if (amoud == true) {
          SDL_RenderCopyEx(ren_game,arrow.tex,&arrow.src,&arrow.dest,-90,NULL,SDL_FLIP_NONE);
        } else {
          adad = (double)atan(shib)*180/3.14 ;
          //cout << shib << " " << adad << endl ;
          if (adad > 0) {
            SDL_RenderCopyEx(ren_game,arrow.tex,&arrow.src,&arrow.dest,180+adad,NULL,SDL_FLIP_NONE);
          } else if (adad == 0) {
            if (mousex_game<centerx) {
              SDL_RenderCopyEx(ren_game,arrow.tex,&arrow.src,&arrow.dest,180,NULL,SDL_FLIP_NONE);
            } else {
              SDL_RenderCopyEx(ren_game,arrow.tex,&arrow.src,&arrow.dest,0,NULL,SDL_FLIP_NONE);
            }
          } else {
            SDL_RenderCopyEx(ren_game,arrow.tex,&arrow.src,&arrow.dest,adad,NULL,SDL_FLIP_NONE);
          }
        }
    }
    }
    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/90)) {
      SDL_Delay((1000/90)-timerFPS);
    }

    SDL_RenderPresent(ren_game);
    input_game();
  }
}
