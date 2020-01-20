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
// Reading score from file
string returnscore(){
  if(openfile()){

    for(int i = 0;i<10;i++){
      GoToLine(savefile,i);
      getline(savefile,saved_score);
    }
  }else{
    cout<<"ERROR OPENING FILE TO READ DATA";
    return -1;
  }
  savefile.close();
  //return stoi(saved_highscore);
  return saved_highscore;
}
//seperate highscore and playername

//Saving score to file
bool scoresave(int score = highscore,string name = playername){
  if(openfile(true)){
    savefile << playername << " " << to_string(highscore) <<endl;
  }else{
    cout<<"ERROR OPENIN FILE FOR SAVING DATA";
    savefile.close();
    return false;
  }
  savefile.close();
  return true;
}
void File_Init(){
  int score_init = returnscore();
  if(score_init == -1){
    openfile(true);
    savefile << 0 << endl;
    cout<<"Init Done";
    savefile.close();
  }
  return;
}
void scoreboard(){
  if(openfile()){

  }else{
    cout<<"ERROR SHOWING SCOREBOARD";
    return;
  }
}
