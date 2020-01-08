#include <SDL2/SDL.h>
#include <stdio.h>
//Window information
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 800;
int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get surface
			screenSurface = SDL_GetWindowSurface( window );
			//Fill the surface
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			//Update the surface
			SDL_UpdateWindowSurface( window );
			//Wait some times to close window
			SDL_Delay( 2000 );
		}
	//Destroy window
	SDL_DestroyWindow( window );
	//Quit SDL subsystems
	SDL_Quit();
	return 0;
}
