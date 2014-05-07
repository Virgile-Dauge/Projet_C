#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "boid.h"
#include "vecteur.h"

int init(int xPix, int yPix){
	SDL_Surface *ecran = NULL;
	//initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
        return -1;
    }
    ecran = SDL_SetVideoMode(xPix,yPix, 32, SDL_OPENGL | SDL_RESIZABLE);
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
        return -1;
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
void pre_dessin(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}
void dessin_point(double x, double y, double z,int taille, int r, int g, int b){
	if (taille<=0) {
		taille = 1;
	}
	if (r<0 || r>255) {
		r=0;
	}
	if (g<0 || g>255) {
		g=0;
	}
	if (b<0 || b>255) {
		b=0;
	}
	glPointSize(taille);
	//glTranslated(x,y,z);
	glBegin(GL_POINTS);
	glColor3ub(r,g,b);
	glVertex3d(x,y,z);
	glEnd();
}
void dessin_point_from_vect(vecteur_t *v,int taille, int r, int g, int b){
	if (taille<=0) {
		taille = 1;
	}
	if (r<0 || r>255) {
		r=0;
	}
	if (g<0 || g>255) {
		g=0;
	}
	if (b<0 || b>255) {
		b=0;
	}
	glPointSize(taille);
	//glTranslated(v->x,v->y,v->z);
	glBegin(GL_POINTS);
	glColor3ub(r,g,b);
	//glVertex3d(0,0,0);
	glVertex3d(v->x,v->y,v->z);
	glEnd();
}
void dessin_boid(boid_t *b){
	dessin_point_from_vect(b->pos,10,b->r,b->g,b->b);
}
void maj_affichage(){
	glFlush();
	SDL_GL_SwapBuffers();
}
