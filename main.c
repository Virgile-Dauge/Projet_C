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

int main(int argc, char * argv){
	//variables pour SDL
	int xPix=800;
	int yPix=600;
	int quit =0;
	int lastSynchro=0; //entier mémorisant le temps écoulé depuis la derniere synchro
	int temps=0;
	int fps=60;
	int fullscreen = 0;
	//INITIALISATION DE LA SDL
	init(xPix,yPix);
	SDL_Event event;
	//variables du modèle 
	int nbMaxBoids=10;
	int nbBoids=0;
	boid_t *tabBoids[10];
	int j;
	for(j=0;j<nbMaxBoids;j++){
		*tabBoids[j]= *new_boid(new_vecteur(rand()%(50),rand()%(50),rand()%(50)));
		nbBoids++;
	}
	gluLookAt(200,200,200,0,0,0,0,0,1);
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
		//tâches effectuées en permanance
		
		//récupération du temps écoulé depuis le lancement de l'application
		temps = SDL_GetTicks();
		if(temps - lastSynchro > 1000/fps){
			pre_dessin();
			int i;
			boid_t *b =NULL;
			for(i=0;i<nbBoids;i++){
				b = tabBoids[i];
				dessin_boid(b);
				calcul_deplacements(tabBoids,i ,nbBoids);
			}
			maj_affichage();
			lastSynchro = SDL_GetTicks();
		}else{
			//sinon on endors le processus (économie de calculs processeur)
			SDL_Delay(1000/fps*(temps - lastSynchro));
		}
		/*
		add_boid_pos(b,v);
		dessiner_boid(b);
		maj_affichage();
		*/
	}
	SDL_Quit();
}
/*
void dessiner_boid(boid_t *b){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(50,50,50,0,0,0,0,0,0);
    //glTranslated(10,10,10);
	//glTranslated(b->pos->x,b->pos->y,b->pos->z);
	glPointSize(10);
		glBegin(GL_POINTS);
		glColor3ub(0,0,50);
		glVertex3d(0,0,0);
		glEnd();
		glTranslated(0,5,0);
		glBegin(GL_POINTS);
		glColor3ub(0,0,100);
		glVertex3d(0,0,0);
		glEnd();
		glTranslated(5,0,0);
		glBegin(GL_POINTS);
		glColor3ub(0,0,150);
		glVertex3d(0,0,0);
		glEnd();
}
void dessiner(int a, int b, int c)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    //gluLookAt(20,20,20,0,0,0,0,0,1);

    glRotatef(a,0,0,1);
    glRotatef(b,1,0,0);
    glRotatef(c,0,1,0);

    glBegin(GL_QUADS);
    glColor3ub(255,0,0); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);
    glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);
    glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);
    glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);
    glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);
    glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);
    glEnd();

    glTranslated(5,0,0);

    glBegin(GL_QUADS);
    glColor3ub(255,0,0); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);
    glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);
    glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);
    glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);
    glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);
    glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);
    glEnd();

    glEnd();
    glFlush();
}
int init(int xPix, int yPix){
	SDL_Surface *ecran = NULL;
	//initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }
    ecran = SDL_SetVideoMode(xPix,yPix, 32, SDL_OPENGL | SDL_RESIZABLE);
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("boid v0.0",NULL);
    //mdéfinition du mode de projection 
    glMatrixMode( GL_PROJECTION );
    //réinitialisation de la matrice 
    glLoadIdentity();
    //projection en persepective
    gluPerspective(70,(double)xPix/yPix,1,1000);
    glEnable(GL_DEPTH_TEST);
}
int maj_affichage(){
	glFlush();
	SDL_GL_SwapBuffers();
}
*/


