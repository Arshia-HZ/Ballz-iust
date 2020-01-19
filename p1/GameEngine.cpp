#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
#include "headers/Game.h"
#include "headers/Object.h"
SDL_Window* win;
SDL_Texture* tex;
int status = 0;
bool windowloop = true;
#include "firstmenu.cpp"
#include "settingsmenu.cpp"
#include "ingamemenu.cpp"
#include "lastmenu.cpp"

int main(int argc, char const *argv[]) {
        while(windowloop) {
Loop:           switch(status) {
                case 0: firstmenu();  break;
                case 1: settingsmenu(); break;
                }
        }
//SDL_CreateWindowAndRenderer(350,600,0,&win,&ren_fm);
        return 0;
}
