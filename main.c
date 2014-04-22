#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "modele.h"
#include "vecteur.h"
#include <SDL2/SDL.h>


int main(int argc, char * argv){
	init();
}
int init(){
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_ALL) != 0 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
	return -1;
	}
	SDL_Window* pWindow = = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
}


