
Obj Speed , Pause , Highscore , Score , UpBar , BtBar , ballcount , arrow ;
bool brick_add=false;
bool downward=false;
int downnumber=0;
int count_marhale=1;
bool first_ste=true;
class brick_class{
public:
  int number_brick;
  Obj brick_Obj;
  double xbrick;
  double ybrick;
};
std::vector <brick_class> brick;
#include <cstdlib>
#include <ctime>
bool occuy(double x,double y,int n){
  for(int i=0;i<brick.size();i++)
  {
    if(brick[i].xbrick==x && brick[i].ybrick==y && i!=n)
    {
      return false;
    }
  }
  return true;
}
//vector <Obj> blGame ;
int omg;
double adad ;
double cex = 175 ;
double cey = 465 ;
//bool hity,hitx;
//double lasty,lastx ;
//double xnew = 165 ,ynew = 455 ;
int gh = 3 ;
//int aa = 0 ;
std::vector<int> brick_number;
double shib ;
//double leftx = 165 ;
//double centerx = 175 ;
//double topy = 455 ;
//double centery = 465 ;
bool Unzir = false;
vector <Obj> Addball ;
bool dwn = false , amoud = false , shot = false ; bool run_first=true;
// bool shot = false ;
int tedad = 1 ;
int out = 0 ;
int mousex_game,mousey_game,mx,my ;
bool running_game = true ;
SDL_Renderer* ren_game;
SDL_Surface* surf_game ;
class Ballb {
  public :
  Obj blGame ;
  bool hity,hitx;
  double lasty,lastx ;
  double xnew = 165 ,ynew = 455 ;
  double leftx = 165 ;
  double centerx = 175 ;
  double topy = 455 ;
  double centery = 465 ;
  double cox = 5 ;
  double coy = 5 ;
  int aa = 0 ;
  bool moving = false ;
};
vector <Ballb> balla ;
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
        for (int i = 0 ; i<balla.size() ; i++) {
          balla[i].moving = true ;
        }
        run_first = true ;
      }
    }
  }
}

void game() {
  srand(time(NULL));
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  running_game = true ;
  ren_game = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect rect_game ;
  rect_game.x = 0 ;
  rect_game.y = 0 ;
  rect_game.w = 350 ;
  rect_game.h = 600 ;
  for (int i = 0 ; i<10 ; i++) {
    balla.push_back(Ballb());
  }
  //balla.push_back(Ballb());
  /*
  brick_hit_x.push_back(bool());
  brick_hit_x[0]=false;
  brick_hit_y.push_back(bool());
  brick_hit_y[0]=false;
  */
  for (int i = 0 ; i<balla.size() ; i++) {
    balla[i].blGame.setDest(165,455,20,20);
    balla[i].blGame.setSource(0,0,715,715);
    balla[i].blGame.setImage("data/BlueBall.png",ren_game) ;
  }
  if(first_ste)
  {

    brick.push_back(brick_class());
    brick[0].brick_Obj.setDest((rand()%6)*55+5,175,55,35);
    brick[0].brick_Obj.setSource(0,0,600,600);
    brick[0].brick_Obj.setImage("data/brick.png",ren_game);
    brick[0].number_brick=count_marhale;
  }
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
  arrow.setDest((balla[0].blGame.dest.x)+((balla[0].blGame.dest.w)/2)-30,(balla[0].blGame.dest.y)+((balla[0].blGame.dest.h)/2)-30,60,60);
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
    if(first_ste)
    {
    SDL_RenderCopyEx(ren_game,brick[0].brick_Obj.tex,&brick[0].brick_Obj.src,&brick[0].brick_Obj.dest,0,NULL,SDL_FLIP_NONE);
  }

    for (int i = 0 ; i < balla.size() ; i++) {
      SDL_RenderCopyEx(ren_game,balla[i].blGame.tex,&balla[i].blGame.src,&balla[i].blGame.dest,0,NULL,SDL_FLIP_NONE);
    }

    if (shot) {
      first_ste=false;
    //  cout << 194 << endl ;
    //cout << balla.size() << " " << out << " " << shot << " " << balla[0].moving << endl ;
      if (run_first) {
        //cout << "JHJKHJBJKBJKBJKKJJKB////???????????????????" ;
        mx = mousex_game ;
        my = mousey_game ;
        run_first=false;
        out = 0 ;
        tedad = 1 ;
        for (int i = 0 ; i < balla.size() ; i++) {
          balla[i].cox=5;
          balla[i].coy=5;
        }
      }
    //  cout << 204 << endl ;
      for (int i = 0 ; i < balla.size() ; i++) {
      if (balla[i].aa==1) {
        (balla[i].aa)--;
        balla[i].cox/=2;
        balla[i].coy/=2;
      } else if (balla[i].aa>1) {
        (balla[i].aa)-- ;
      }
      }
    //cout << 214 << endl ;
    //  std::cout << leftx<<" "<<topy << '\n';
    for (int i = 0 ; i<tedad ; i++) {
      if (balla[i].hitx){
        balla[i].hitx = false ;
      } else {
        balla[i].lastx = balla[i].xnew ;
      }
      if (balla[i].hity){
        balla[i].hity=false;
      } else {
        balla[i].lasty = balla[i].ynew ;
      }
    }
  //  cout << 228 << endl ;
      for (int i = 0 ; i<tedad ; i++) {
        if (amoud) {
          balla[i].ynew = (double)(balla[i].ynew + balla[i].coy) ;
        } else {
        //  cout << (shib*-1) << " " << atan((shib*-1)) << " " << cos(atan((shib*-1))) << " " << sin(atan((shib*-1))) << endl ;
          if ((shib*-1) > 0) {
              balla[i].xnew =(double)(balla[i].xnew + (balla[i].cox*cos(atan((shib*-1)))) ) ;
              balla[i].ynew =(double)(balla[i].ynew + (balla[i].coy*(-1)*(sin(atan((shib*-1))))) ) ;
          } else {
              balla[i].xnew =(double)(balla[i].xnew + (balla[i].cox*(-1)*(cos(atan((shib*-1))))) ) ;
              balla[i].ynew =(double)(balla[i].ynew + (balla[i].coy*sin(atan((shib*-1)))) ) ;
          }
        }
      }
      if (tedad < balla.size()) {
        if (gh == 0) {
          gh = 3 ;
          tedad +=1 ;
        } else {
          gh-- ;
        }
      }
    //  std::cout << xnew << " " << ynew << endl ;

        /*
        if((ynew>=brick[i].dest.y-4 && ynew<=(brick[i].destest.x+brick[i].dest.w-5 && xnew<brick[i].dest.x+brick[i].dest.w+6)))
          brick_hit_x=true;
          if((xnew>=brick[i].dest.x-4&& xnew<=(brick[i].de.dest.y+brick[i].dest.h && ynew<brick[i].dest.y+brick[i].dest.h+6)))
          brick_hit_y=true;
        */

      for (int i = 0 ; i<tedad ; i++) {
      if(balla[i].ynew>455)
      {
      balla[i].moving=false;
      out += 1 ;
      if (out == 1) {
        cex = balla[i].xnew + 10 ;
        cey = balla[i].ynew + 10 ;
        omg = i ;
      }
      if(out ==balla.size() && shot)
      {
        brick_add=true;
      }
      if (out == balla.size()) {
        shot = false ;
      }
    }

      if (balla[i].xnew < 0) {
        balla[i].cox*=-1;
        //xnew = 0 ;
      }
      if (balla[i].xnew > 330) {
        balla[i].cox*=-1;
        //xnew = 330 ;
      }
      if (balla[i].ynew < 125) {
        balla[i].coy*=-1;
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
      if (balla[i].ynew > 455 ) {
        balla[i].coy*=-1;
        balla[i].ynew = 455 ;
      }
      /*
      if(xnew < 0 || xnew > 335 )
      cox*=-1;
      if(ynew < 120 || ynew > 456 )
      coy*=-1;
      */
    }
    //cout << 309 << endl ;
    if(brick_add)
    {
      int random_brick;
                count_marhale++;
                if(count_marhale>20)
                random_brick=(rand()%6)+1;
                else
                random_brick=(rand()%2)+1;

                for(int i=1;i<=random_brick;i++)
                {
                  int xrandom_number;
                  int yrandom_number;
                  brick.push_back(brick_class());
                  brick[brick.size()-1].number_brick=count_marhale;
                  do {
                      xrandom_number=rand()%6;
                      yrandom_number=rand()%6;
                      brick[brick.size()-1].brick_Obj.setDest((xrandom_number*55)+5,132,52,32);
                      brick[brick.size()-1].xbrick=(xrandom_number*53)+5 ;
                      brick[brick.size()-1].ybrick=135 ;
                      brick[brick.size()-1].brick_Obj.setSource(0,0,600,600);
                  } while(!occuy((xrandom_number*55)+5 , 135,brick.size()-1));


}

                brick_add=false;
                downward=true;




}
if(downward)
{
while(downnumber<40)
{
  downnumber++;
  for(int i=0;i<brick.size();i++)
   {
     brick[i].brick_Obj.setDest( brick[i].brick_Obj.dest.x, brick[i].brick_Obj.dest.y+1,52,35);
     brick[i].ybrick= brick[i].brick_Obj.dest.y+40;
     brick[i].brick_Obj.setImage("data/brick.png",ren_game);
       SDL_RenderCopyEx(ren_game,brick[i].brick_Obj.tex,&brick[i].brick_Obj.src,&brick[i].brick_Obj.dest,0,NULL,SDL_FLIP_NONE);

     if(brick[i].ybrick>=470 )
       {
         cout<<"game lose"<<endl;
         running_game=false;
         for(int i=0;i<brick.size();i++)
         {
               brick.erase(brick.begin()+i);
         }
         WriteMessage("game over ", 100, 350, 255,255,255, 40, ren_game);
         brick.erase(brick.begin()+i);
       }

   }
}



  downward=false;
  downnumber=0;

}


    for (int i = 0 ; i<tedad ; i++) {

        if (balla[i].moving) {
          for(int j=0;j<brick.size();j++)
          {
          balla[i].blGame.setDest(balla[i].xnew,balla[i].lasty,20,20);
          if(hit(brick[j].brick_Obj.dest,balla[i].blGame.dest)) {
              //cout<<"hit x"<<lastx<<"   "<<lasty<<"  "<<xnew<<"   "<<ynew<<endl;
              balla[j].hitx = true ;
              balla[i].cox *= (-1) ;
              brick[j].number_brick--;
            }

              balla[i].blGame.setDest(balla[i].lastx,balla[i].ynew,20,20);

              if(hit(brick[j].brick_Obj.dest,balla[i].blGame.dest)) {
                  //cout<<"hit y"<<lastx<<"   "<<lasty<<"  "<<xnew<<"   "<<ynew<<endl;
                  balla[i].hity=true ;
                  balla[i].coy *= (-1) ;
                  if(!balla[i].hitx)
                  brick[j].number_brick--;
                }
                if(brick[j].number_brick<=0)
                {
                    brick.erase(brick.begin()+j);
                    for(int j=0;j<brick.size();j++)
                    {
                      SDL_RenderCopyEx(ren_game,brick[j].brick_Obj.tex,&brick[j].brick_Obj.src,&brick[j].brick_Obj.dest,0,NULL,SDL_FLIP_NONE);
                  }
                  }

            }
              balla[i].blGame.setDest(balla[i].xnew,balla[i].ynew,20,20);
              if ((balla[i].hitx)&&(balla[i].hity)) {
                balla[i].cox *= 2 ;
                balla[i].coy *= 2 ;
                balla[i].aa = 2 ;
              }


        } else if (!balla[i].moving) {
        //  balla[i].leftx = balla[omg].xnew;
          balla[i].centerx = cex ;
        //  balla[i].topy = 455;
          balla[i].centery = 455+10;
          balla[i].ynew = 455 ;
          balla[i].xnew = cex-10;
          balla[i].blGame.setDest(balla[i].xnew,455,20,20);
          //std::cout << "safe" << xnew << " " << ynew << endl ;
          arrow.setDest(cex-30,cey-30,60,60);
          //int brick_new=rand()%6+1;
          //for(int j=blGame.size();j<blGame.size()+brick_new;j++)
          //{
          // blGame.push_back(Obj());
        //}
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


}
for(int j=0;j<brick.size();j++)
{
  SDL_RenderCopyEx(ren_game,brick[j].brick_Obj.tex,&brick[j].brick_Obj.src,&brick[j].brick_Obj.dest,0,NULL,SDL_FLIP_NONE);
}
  //cout << 362 << endl ;
    if (dwn == true) {
      if (mousex_game==cex) {
        amoud = true ;
      } else {
        amoud = false ;
        shib = (double)(mousey_game-cey)/(mousex_game-cex);
      }
      if (mousey_game>cey) {
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
            if (mousex_game<cex) {
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
    //cout << 395 << endl ;
    framecount++ ;
    int timerFPS = SDL_GetTicks() - lastframe ;
    if (timerFPS < (1000/90)) {
      SDL_Delay((1000/90)-timerFPS);
    }

    SDL_RenderPresent(ren_game);
    input_game();
    //cout << 404 << endl ;
  }
}
