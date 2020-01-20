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
int returnscore(){
  string saved_highscore;
  if(openfile()){
    getline(savefile,saved_highscore);
  }else{
    cout<<"ERROR OPENING FILE TO READ DATA";
    return -1;
  }
  savefile.close();
  return stoi(saved_highscore);
}
//Saving score to file
bool savescore(int highscore){
  if(openfile(true)){
    savefile << highscore <<endl;
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
