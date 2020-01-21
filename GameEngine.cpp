#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#include "headers/Object.h"
SDL_Window* win ;
SDL_Texture* tex ;
int status = 0;
Mix_Music *music;
SDL_Event e ;
string *playername;
int *highscore;
bool windowloop = true;
#include "audiomanager.cpp"
#include "about.cpp"
#include "firstmenu.cpp"
#include "settingsmenu.cpp"
#include "game.cpp"
#include "highscore.cpp"
#include "ingamemenu.cpp"
#include "lastmenu.cpp"

int main(int argc, char const *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  //File_Init();
  Music_Init();
  win = SDL_CreateWindow("Ballz", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,350,600,0);
  startaudio();
  while(windowloop){
  switch(status){
    case 0: firstmenu();  break;
    case 1: settingsmenu(); break;
    case 2: game(); break;
  /*  case 3: lastmenu(); break;
    case 4: ingamemenu(); break; */
    default: SDL_Quit();
  }
}
  return 0;
}
