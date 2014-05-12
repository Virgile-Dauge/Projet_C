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

//gcc main.c affichage.c modele.c boid.c vecteur.c -o main -lSDL -lGL -lGLU -lm -Wall -Wextra -Wunreachable-code -Wwrite-strings

int main(int argc, char ** argv){
	//variables pour SDL
	int xPix=800;
	int yPix=600;
	int quit =0;
	int lastSynchro=0; //entier mémorisant le temps écoulé depuis la derniere synchro
	int temps=0;
	int fps=60;
	int dim3 = 1;

	//variables pour le modele
	int nbBoid = 500;
	int nbPre = 20;
	int nbFood = 10;

	//INITIALISATION DE LA SDL
	init(xPix,yPix);
	SDL_Event event;
	//activation de la répétition de l'appui sur les touches 
	SDL_EnableKeyRepeat(10,10);

	//création du modéle 
	modele_t *m = new_modele(1000,10,5,dim3);
	int i;
	for(i=0;i<nbBoid;i++){
		ajout_boid(m,new_boid(new_vecteur(rand()%(1200-800) +800,rand()%(1200-800)+800 ,rand()%(1200-800) +800),200));
	}
	for(i=0;i<nbPre;i++){
		ajout_pre(m,new_boid(new_vecteur(rand()%(1500-600) +600,rand()%(1500-600) +600,rand()%(1500-600) +600),700));
	}
	for(i=0;i<nbFood;i++){
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
					break;	
			}
		}
		//récupération du temps écoulé depuis le lancement de l'application
		temps = SDL_GetTicks();
		if(temps - lastSynchro > 1000/fps){
			lastSynchro = SDL_GetTicks();
			pre_dessin(x,y,z);
			calcul_deplacement_boids(m);
			calcul_deplacement_preds(m);
			dessin_modele(m);
			maj_affichage();
		}
	}
	SDL_Quit();
	return 1;
}