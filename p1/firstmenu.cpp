#include "menu.h"
#include "object.h"

void Object::setDest(int x,int y, int w, int h){
	dest.x=x;
	dest.y=y;
	dest.h=h;
	dest.w=w;
}
void Object::setSource(int x, int y, int h, int w){
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;
}
void Object::setImage(string filename, SDL_Renderer* ren){
	SDL_Surface* surf = IMG_Load(filename.c_str());
	tex = SDL_CreateTextureFromSurface(ren,surf);
}
void Menu::draw(Object o){
	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopyEx(ren,o.getTex(),&src,&dest,0,NULL,SDL_FLIP_NONE);
}
Menu::Menu() {
	SDL_Init(0);
	SDL_CreateWindowAndRenderer(540,360,0,&win,&ren);
	SDL_SetWindowTitle(win, "Ballz");
	running = true;
	count = 0;
	test.setDest(100,100,100,120);
	test.setSource(0,0,75,75);
	test.setImage("image.png",ren);
	loop();
}
Menu::~Menu(){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
void Menu::loop() {
	while(running) {
		lastFrame=SDL_GetTicks();
		static int lastTime;
		if(lastFrame >= (lastTime+1000)){
			lastTime = lastFrame;
			frameCount = 0;
			count++;
		}
		render();
		input();
		update();
		if(count>3) running=false;
	}
}
void Menu::render(){
	SDL_SetRenderDrawColor(ren,255,0,0,255);
	SDL_Rect rect;
	rect.x=rect.y=0;
	rect.w=360;
	rect.h=240;
	SDL_RenderFillRect(ren,&rect);
	draw(test);
	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if(timerFPS<(1000/60)){
		SDL_Delay((1000/60)-timerFPS);
	}
	SDL_RenderPresent(ren);
}

int main(){
	Menu g;
}
