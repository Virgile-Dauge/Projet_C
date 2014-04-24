#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "modele.h"
#include "vecteur.h"
#include <SDL2/SDL.h>


int main(int argc, char * argv){
	SDL_Window* pWindow = NULL;
	init(pWindow);
	SDL_Event event;
	int quit =0;
	int fullscreen =0;
	while(SDL_PollEvent(&event)){
		switch(event.type)
		{
			//case SDL_QUIT: quit=1; break;
			case SDL_KEYUP:
				if(event.key.keysym.sym == SDLK_f){
					if(fullscreen){
						fullscreen=0;
						SDL_SetWindowFullscreen(pWindow,0);
					}else{
						fullscreen=1;
						SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);
					}
				}
				break;	
		}
	}

}
int init(SDL_Window* fenetre){
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
	return -1;
	}
	fenetre = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
}


