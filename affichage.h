#ifndef AFF_H
#define AFF_H
#include "boid.h"
#include "vecteur.h"


int init(int xPix, int yPix);
void pre_dessin();
void dessin_point(double x, double y, double z,int taille, int r, int g, int b);
void dessin_point_from_vect(vecteur_t *v,int taille, int r, int g, int b);
void dessin_boid(boid_t *b);
void maj_affichage();
#endif