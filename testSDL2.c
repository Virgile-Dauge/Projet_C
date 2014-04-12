#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	/* INITIALISATION DE LA SDL */
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
		fprintf(stdout, "ECHEC initialisation SDL: %s \n",SDL_GetError());
		return -1;
	}
	/*Creation de la fenetre */
	SDL_Window* fenetre = NULL;
	fenetre = SDL_CreateWindow("testSDDL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_OPENGL);
	if(fenetre==NULL){
		fprintf(stderr, "ECHEC initialisation SDL: %s \n",SDL_GetError());
	}
	/*
	int modeNumber,error;
	// On récupère le nombre de modes d'affichage pour l'écran 0
	modeNumber = SDL_GetNumDisplayModes(0);
	if ( modeNumber < 0 )
	{
	fprintf(stdout,"Échec lors de la récupération du nombre de modes (%s)\n",SDL_GetError());
	return -2;
	}
	fprintf(stdout,"Vous avez %d mode(s) d'affichage\n",modeNumber);
	// Affichage des différents modes
	for ( i = 0 ; i < modeNumber ; i++ )
	{
		error = SDL_GetDisplayMode(0,i,&displayMode);
		if ( error < 0 )
		{
			fprintf(stdout,"Échec lors de la récupération du mode d'affichage (%s)\n",SDL_GetError());
			return -3;
		}
	}
	fprintf(stdout,"Mode %d : %dx%dx%d \n",modeNumber,displayMode.w,displayMode.h,displayMode.refresh_rate);
	return 0;

	*/
	SDL_ShowWindow();
	SDL_Event event;
	while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
	{
		switch(event.type)
		{
		case SDL_QUIT: // Clic sur la croix
		quit=1;
		break;
		case SDL_KEYUP: // Relâchement d'une touche
		if ( event.key.keysym.sym == SDLK_f ) // Touche f
		{
			// Alterne du mode plein écran au mode fenêtré
			if ( fullscreen == 0 )
			{
			fullscreen = 1;
			SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);
			}
			else if ( fullscreen == 1 )
			{
			fullscreen = 0;
			SDL_SetWindowFullscreen(pWindow,0);
			}
		}
	break;
	}

}