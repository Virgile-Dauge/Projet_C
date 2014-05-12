#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "boid.h"
#include "vecteur.h"
#include "modele.h"
#include <math.h>

int init(int xPix, int yPix){
	SDL_Surface *ecran = NULL;
	//initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
        return -1;
    }
    //création de la fenetre
    ecran = SDL_SetVideoMode(xPix,yPix, 32, SDL_OPENGL);
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
    gluPerspective(100,(double)xPix/yPix,1,100000);
    glEnable(GL_DEPTH_TEST);
    return 1;
}
void calcul_cam(double phi, double theta,int rayon, vecteur_t *centre){
	double x,y,z;
	x= centre->x + rayon*sin(phi)*cos(theta);
	y= centre->y + rayon*sin(phi)*sin(theta);
	z= centre->z + rayon*cos(theta);
	gluLookAt(x,y,z,centre->x,centre->y,centre->z,1,0,0);
}
void pre_dessin(double phi,double theta,int rayon,vecteur_t *centre, int dim3){
	//liberation des buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClear( GL_COLOR_BUFFER_BIT );
    //passage à la matrice de modele
    glMatrixMode( GL_MODELVIEW );
    //chargement de la matrice identité dans la matrice de modèle
    glLoadIdentity();
    if(dim3){
    	calcul_cam(phi,theta,rayon,centre);
    }else{
    	gluLookAt(1000,1000,600,1000,1000,0,1,0,0);
    }
    
}
void dessin_point(double x, double y, double z,int taille, int r, int g, int b,int dim3){
	//si la taille est inférieure ou égale à 0
	if (taille<=0) {
		// on redéfinit la taille à 1
		taille = 1;
	}
	//verification des couleurs
	if (r<0 || r>255) {
		r=0;
	}
	if (g<0 || g>255) {
		g=0;
	}
	if (b<0 || b>255) {
		b=0;
	}
	//definition de la taille des points
	glPointSize(taille);
	glBegin(GL_POINTS);
	//definition de la couleur du point
	glColor3ub(r,g,b);
	if(dim3){
		//dessin point 3D
		glVertex3d(x,y,z);
	}else{
		//dessin point 2D
		glVertex2d(x,y);
	}	
	glEnd();
}
void dessin_point_from_vect(vecteur_t *v,int taille, int r, int g, int b, int dim3){
	dessin_point(v->x,v->y,v->z,taille,r,g,b,dim3);
}
void dessin_boid(boid_t *b ,int dim3){
	dessin_point_from_vect(b->pos,2,b->r,b->g,b->b,dim3);
}
void dessin_pre(boid_t *b ,int dim3){
	dessin_point_from_vect(b->pos,5,255,0,0,dim3);
}
void dessin_food(vecteur_t *v, int dim3){
	dessin_point_from_vect(v,10,0,0,255,dim3);
}
void dessin_modele(modele_t *m){
	int i;
	//pour chaque boid
	for(i=0;i<m->nbBoid;i++){
		//on le dessine 
		dessin_boid(m->tabBoid[i],m->dimention3);
	}
	//pour chaque Prédateur
	for(i=0;i<m->nbPre;i++){
		//on le dessine
		dessin_pre(m->tabPre[i],m->dimention3);
	}
	//pour chaque nourriture
	for(i=0;i<m->nbFood;i++){
		//on la dessine
		dessin_food(m->tabFood[i],m->dimention3);
	}
}
void maj_affichage(){
	glFlush();
	// changement des buffer (swap du double buffering)
	SDL_GL_SwapBuffers();
}
