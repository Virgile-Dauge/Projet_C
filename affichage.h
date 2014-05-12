#ifndef AFF_H
#define AFF_H
#include "boid.h"
#include "vecteur.h"
//prototypes
int init(int xPix, int yPix);
void pre_dessin();
void dessin_point(double x, double y, double z,int taille, int r, int g, int b, int dim3);
void dessin_point_from_vect(vecteur_t *v,int taille, int r, int g, int b, int dim3);
void dessin_boid(boid_t *b, int dim3);
void dessin_pre(boid_t *b, int dim3);
void dessin_food(vecteur_t *v, int dim3);
void dessin_modele(modele_t *m);
void maj_affichage();
#endif