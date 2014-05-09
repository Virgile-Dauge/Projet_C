#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "main.h"
#include "modele.h"
#include "vecteur.h"
#include "boid.h"
#include "affichage.h"

void main(int argc, char ** argv){
	//variables pour SDL
	int xPix=800;
	int yPix=600;
	int quit =0;
	int lastSynchro=0; //entier mémorisant le temps écoulé depuis la derniere synchro
	int temps=0;
	int fps=30;
	int fullscreen = 0;
	//INITIALISATION DE LA SDL
	init(xPix,yPix);
	SDL_Event event;
	pre_dessin();


	//mise en place de la vue
	gluLookAt(200,200,200,1000,1000,1000,0,0,1);

	//création du modéle 
	modele_t *m = new_modele(10,2,2);
	while(!quit){
		//gestion des événements
		while(SDL_PollEvent(&event)){
			switch(event.type)
			{	
				//si l'utilisateur clique sur la croix
				case SDL_QUIT:
					//arret de l'application 
					quit=1;  
					break;
				//si l'événemenet correspond à un appui sur une touche
				case SDL_KEYUP:
					//si appui sur la touche echap
					if(event.key.keysym.sym == SDLK_ESCAPE){
						//arret de l'application
						quit=1;  
					}
					break;
					//si appui sur la touche b
					if(event.key.keysym.sym == SDLK_b){
						//ajout de boid
						//ajout_boid(m,new_boid(new_vecteur(rand()%(1500-1000) +1000,rand()%(1500-1000) +1000,rand()%(1500-1000) +1000),100));
						//rand()%(1500-1000) +1000;
						ajout_boid(m,new_boid(new_vecteur(1000,1000,1000),100));  
					}
					break;
					//si appui sur la touche p
					if(event.key.keysym.sym == SDLK_p){
						//ajout predateur 
					}
					break;
					//si appui sur la touche f
					if(event.key.keysym.sym == SDLK_f){
						/*test fullscreen
						if(fullscreen){
							fullscreen=0;
							SDL_SetVideoMode(xPix,yPix, 32, SDL_OPENGL | SDL_RESIZABLE);
						}else{
							fullscreen=1;
							SDL_SetVideoMode(xPix,yPix, 32, SDL_OPENGL | SDL_FULLSCREEN);
						}
						*/
					}

					break;	
			}
		}
		//récupération du temps écoulé depuis le lancement de l'application
		temps = SDL_GetTicks();
		if(temps - lastSynchro > 1000/fps){
			boid_t *b = new_boid(new_vecteur(1000,1000,1000),100);
			dessin_boid(b);
			maj_affichage();
			lastSynchro = SDL_GetTicks();
			//calcul_deplacement_boids(m);
			//dessin_modele(m);
		}/*else{
			//sinon on endors le processus (économie de calculs processeur)
			SDL_Delay(1000/fps*(temps - lastSynchro));
		}*/
	}
	SDL_Quit();
}