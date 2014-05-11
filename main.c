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

int main(int argc, char ** argv){
	//variables pour SDL
	int xPix=800;
	int yPix=600;
	int quit =0;
	int lastSynchro=0; //entier mémorisant le temps écoulé depuis la derniere synchro
	int temps=0;
	int fps=60;
	int dim3 = 0;
	//int fullscreen = 0;
	//INITIALISATION DE LA SDL
	init(xPix,yPix);
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10);

	//création du modéle 
	modele_t *m = new_modele(1000,10,5,dim3);
	int i;
	for(i=0;i<500;i++){
		ajout_boid(m,new_boid(new_vecteur(rand()%(1200-800) +800,rand()%(1200-800)+800 ,rand()%(1200-800) +800),500));
	}
	for(i=0;i<10;i++){
		ajout_pre(m,new_boid(new_vecteur(rand()%(1500-600) +600,rand()%(1500-600) +600,rand()%(1500-600) +600),500));
	}
	for(i=0;i<5;i++){
		ajout_food(m,new_vecteur(rand()%(1500-600) +600,rand()%(1500-600) +600,rand()%(1500-600) +600));
	}

	//variables caméra
	int x =600;
	int y =600;
	int z =600;
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
					//si l'on appuie sur la touche échap, 
					if(event.key.keysym.sym == SDLK_ESCAPE){
						//on quitte la boucle "infinie"
						quit=1;
					}
					/*
					//si appui sur la touche b
					if(event.key.keysym.sym == SDLK_b){
						//ajout de boid
						//ajout_boid(m,new_boid(new_vecteur(rand()%(1200-800) +800,rand()%(1200-800) +800,rand()%(1200-800) +800),100));
						//rand()%(1500-1000) +1000;
						//ajout_boid(m,new_boid(new_vecteur(1000,1000,1000),100));  
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
					break;	
			}
		}
		//récupération du temps écoulé depuis le lancement de l'application
		temps = SDL_GetTicks();
		if(temps - lastSynchro > 1000/fps){
			lastSynchro = SDL_GetTicks();
			pre_dessin(x,y,z);
			calcul_deplacement_boids(m);
			dessin_modele(m);
			maj_affichage();
		}/*else{
			//calcul_deplacement_boids(m);
			temps = SDL_GetTicks();
			//sinon on endors le processus (économie de calculs processeur)
			SDL_Delay(1000/fps*(temps - lastSynchro));
		}*/
	}
	SDL_Quit();
	return 1;
}