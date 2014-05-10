#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "boid.h"
#include "vecteur.h"
#include "modele.h"

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
    //projection en persepective fovy = 70°  le ratio est calculé automatiquement 
    gluPerspective(70,(double)xPix/yPix,1,100000);
    glEnable(GL_DEPTH_TEST);
}
/*
void vue(){
	glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
	//mise en place de la vue
	gluLookAt(200,200,200,1000,1000,1000,0,0,1);
}
*/
void pre_dessin(int x,int y, int z){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(x,y,z,1000,1000,1000,0,0,1);
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
	glBegin(GL_POINTS);
	glColor3ub(r,g,b);
	glVertex3d(x,y,z);
	glEnd();
}
void dessin_point_from_vect(vecteur_t *v,int taille, int r, int g, int b){
	dessin_point(v->x,v->y,v->z,taille,r,g,b);
}
void dessin_boid(boid_t *b){
	dessin_point_from_vect(b->pos,5,b->r,b->g,b->b);
}
void dessin_modele(modele_t *m){
	int i;
	for(i=0;i<m->nbBoid;i++){
		dessin_boid(m->tabBoid[i]);
	}
}
void maj_affichage(){
	glFlush();
	SDL_GL_SwapBuffers();
}
