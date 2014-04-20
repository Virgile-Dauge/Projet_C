#include <stdio.h>
#include <stdlib.h>
#include "boid.h"
#include "vecteur.h"

boid_t *new_boid(vecteur_t *v){
	boid_t *b = malloc(sizeof(v));
	return b;
}
void set_boid_pos(boid_t *b, vecteur_t *v){
	b->v = v;
}
vecteur_t *get_boid_pos(boid_t *b){
	return b->v;
}
void add_boid(boid_t *b, vecteur_t *v){
	b->v += v;
}
void print_boid(boid_t *b){
	printf("<&°%st><l\n",toString_vecteur(b->v));	
}