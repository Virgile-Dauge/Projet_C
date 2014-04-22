#ifndef BOID_H
#define BOID_H
#include "vecteur.h"

typedef struct boid{
	int id;
	vecteur_t *v;
} boid_t;

boid_t *new_boid(vecteur_t *v);
void set_boid_pos(boid_t *b, vecteur_t *v);
vecteur_t *get_boid_pos(boid_t *b);
void add_boid_pos(boid_t *b, vecteur_t *v);
void print_boid(boid_t *b);
#endif