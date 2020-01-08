#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "object.h"
using namespace std ;

class Menu {
public:
  Menu();
  ~Menu();
  void loop();
  void update() {}
  void input() {}
  void render();
  void draw(Object o);
private:
  SDL_Renderer* ren;
  SDL_Window* win;
  bool running;
  int count;
  int frameCount, timerFPS, lastFrame;
  Object test;
};
#endif //Menu_h
