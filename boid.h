#ifndef BOID_H
#define BOID_H
#include "vecteur.h"

typedef struct boid{
	int id;
	vecteur_t *pos;
	vecteur_t *vit;
} boid_t;

boid_t *new_boid(vecteur_t *pos);
void set_boid_pos(boid_t *b, vecteur_t *pos);
vecteur_t *get_boid_pos(boid_t *b);
void add_boid_pos(boid_t *b, vecteur_t *pos);
void print_boid(boid_t *b);
#endif