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
	tex = SDL_createTextureFromSurface(ren,surf);
}
void Menu::draw(Object o){
	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopyEx(ren,o.getTex(),&src,&dest,0,NULL,SDL_FLIP_NONE);
}
Menu::Menu() {
	SDL_init(0);
	SDL_CreateWindowandRenderer(360,240,&win,&ren);
	SDL_SetWindowTitle(win, "Ballz");
	running = true;
	count = 0;
	test.setDest(50,50,75,75);
	test.setSource(0,0,75,75);
	test.setImage("image.png",ren);
	loop();
}
Menu::~Menu(){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
void Game::loop() {
	while(running) {
		lastFrame=SDL_GetTicks();
		static int lastTime;
		if(lastFrame => (lastTime+1000)){
			lastTime = lastFrame;
			frameCount = 0;
			count++;
		}
		render();
	}
}
