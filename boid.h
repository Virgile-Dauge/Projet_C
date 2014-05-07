#ifndef BOID_H
#define BOID_H
#include "vecteur.h"

typedef struct boid{
	int r,g,b;
	double distanceVue;
	vecteur_t *pos;
	vecteur_t *vit;
} boid_t;

boid_t *new_boid(vecteur_t *pos,double distanceVue);
void set_boid_pos(boid_t *b, vecteur_t *pos);
vecteur_t *get_boid_pos(boid_t *b);
void add_boid_pos(boid_t *b, vecteur_t *pos);
int equals_boid(boid_t *b1, boid_t *b2);
double distance_boid(boid_t *b, vecteur_t *v);
int boid_can_see(boid_t *b, vecteur_t *posObjet);
void print_boid(boid_t *b);
#endif