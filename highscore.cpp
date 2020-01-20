#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
string playername;
int highscore;
string playernames[10];
int highscores[10];
fstream savefile;
//Opening file
bool openfile(bool clean = false){
  if(clean){
      savefile.open("data/highscore.txt",ofstream::out | ofstream::trunc);
  }else{
      savefile.open("data/highscore.txt");
  }
  if(savefile.is_open()){
    return true;
  }else{
    return false;
  }
}
// Reading scores from file
bool returnscore(bool just_highscore = false){
  if(openfile()){
    if(just_highscore){
      savefile >> highscore >> playername;
    }else{
        for(int i = 0;i<10;i++){
          savefile >> highscores[i] >> playernames[i];
      }
    }
  }else{
    cout<<"ERROR OPENING FILE TO READ DATA";
    return false;
  }
  savefile.close();
  return true;
}
//initializing scores
void File_Init(){
  returnscore(true);
  int score_init = highscore;
  if(score_init == -1){
    openfile(true);
    savefile << 0 << endl;
    cout<<"Init Done";
    savefile.close();
  }
  return;
}
//Sort scores decending
void sortscores(){
  int temp_highscores[10];
  string temp_playernames[10];
  for(register int i = 0; i<10;i++){
    temp_highscores[i] = highscores[i];
    temp_playernames[i] = playernames[i];
  }
  sort(highscores,highscores+10,greater<int>());
  int sort_count=0;
    int i = 0;
    for(i;i<10;i++){
      if(highscores[i] == temp_highscores[i]){
        playernames[i] = "";
        playernames[i] = temp_playernames[i];
    }
    cout<<temp_playernames[i]<<" == "<<playernames[i]<<endl;
  }
}
void scoreboard(){
  if(openfile()){
    returnscore();
    for(int i = 0; i<10;i++){
      cout<< i<< ". "<<playernames[i]<<"  "<<highscores[i];
    }
  }else{
    cout<<"ERROR SHOWING SCOREBOARD";
    return;
  }
}
bool savescore(int highscore,string playername){
  returnscore();
  highscores[9] = highscore;
  cout<<playernames[9];
  playernames[9] = playername;
    cout<< " "<< playernames[9];
  sortscores();
  if(openfile(true)){e
    for(register int i = 0;i<10;i++){
      savefile << highscores[i]<<" "<<playernames[i]<<endl;
    }
  }else{
    cout<<"ERROR OPENIN FILE FOR SAVING DATA";
    savefile.close();
    return false;
  }
  savefile.close();
  return true;
}
int main(int argc, char const *argv[]) {
  returnscore();
  cin>>playername>>highscore;
  scoreboard();
   return 0;
}
