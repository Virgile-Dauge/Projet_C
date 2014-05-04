#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "modele.h"
#include "vecteur.h"
#include "boid.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

int main(int argc, char * argv){
	//INITIALISATION DE LA SDL
	init(800,600);
	SDL_Event event;
	int quit =0;
	//dessiner(0,0,0);
	boid_t *b = new_boid(new_vecteur(0,0,0));
	dessiner_boid(b);
	while(!quit){
		//gestion des événements
		while(SDL_PollEvent(&event)){
			switch(event.type)
			{	
				//si l'utilisateur clique sur la croix
				case SDL_QUIT: 
					quit=1;  
					break;
				//si l'événemenet correspond à un appui sur une touche
				case SDL_KEYUP:
					//si appui sur la touche f
					if(event.key.keysym.sym == SDLK_f){
						maj_affichage();
						/*
						if(fullscreen){
							fullscreen=0;
							printf("mode fenetré");
							SDL_SetWindowFullscreen(fenetre,0);
						}else{
							fullscreen=1;
							printf("mode plein écran");
							SDL_SetWindowFullscreen(fenetre,SDL_WINDOW_FULLSCREEN);
						}
						*/
					}
					break;	
			}

		}
	}
	SDL_Quit();
}
void dessiner_boid(boid_t *b){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(50,50,50,0,0,0,0,0,1);
	glTranslated(b->pos->x,b->pos->y,b->pos->z);
	glBegin(GL_POLYGON);
	glColor3ub(0,0,255);
	glVertex3d(5,0,0);
	glVertex3d(1,2,0);
	glVertex3d(1,-2,0);
	glVertex3d(0,0,3);
	//glVertex3d(0,0,-2);
	glVertex3d(-8,0,0);

	glColor3ub(0,255,0); //face verte
    glVertex3d(5,0,0);
    glVertex3d(1,2,0);
    glVertex3d(1,-2,0);
    glVertex3d(1,1,1);
    glVertex3d(-8,0,0);
    
	glEnd();
    glFlush();
}
void dessiner(int a, int b, int c)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(3,4,1,0,0,0,0,0,1);

    glRotated(a,0,0,1);
    glRotated(b,1,0,0);
    glRotated(c,0,1,0);

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
	SDL_GL_SwapBuffers();
}


