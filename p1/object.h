#ifndef OBJECT_H
#define OBJECT_H
class Object(){
private:
  SDL_Rect dest;
  SDL_Rect src;
  SDL_Texture* text;
public:
  SDL_Rect getDest() const {return dest;}
  SDL_Rect getSource() const {return src;}
  void setDest(int x,int y,int w,int h);
  void setSource(int x,int y,int w,int h);
  void setImage(string filename,SDL_Renderer* ren);
}

#endif //OBJECT_H
