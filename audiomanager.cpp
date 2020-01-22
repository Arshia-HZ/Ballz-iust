Mix_Chunk *clearscore_sound = NULL;
Mix_Chunk *brick_hit = NULL;
Mix_Chunk *gameover = NULL;
Mix_Chunk *addball = NULL;

void stopaudio(){
/*  Mix_FreeMusic( music );
	music = NULL;
  Mix_Quit(); */
  Mix_HaltMusic();
}
void Music_Init(){
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  clearscore_sound = Mix_LoadWAV( "data/clearscore.mp3" );
  brick_hit = Mix_LoadWAV( "data/brick_hit.wav" );
  gameover = Mix_LoadWAV( "data/gameover.mp3" );
  addball = Mix_LoadWAV( "data/addball.wav" );
  music = Mix_LoadMUS( "data/beat.wav" );
	if( music == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}
}
void startaudio(){
  Mix_PlayMusic( music, -1 );
}
bool checkaudio(){
  //No music is playing = 0
  if( Mix_PlayingMusic() == 0 )
  {
    return false;
  }else{
    return true;
  }
}
