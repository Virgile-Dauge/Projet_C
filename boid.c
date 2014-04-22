#include <stdio.h>
#include <stdlib.h>
#include "boid.h"
#include "vecteur.h"

boid_t *new_boid(vecteur_t *vect){
	boid_t *b = malloc(sizeof(boid_t));
	b->v = malloc(sizeof(vecteur_t));
	b->id = 0;
	copy_vecteur(b->v,vect);
	return b;
}
void set_boid_pos(boid_t *b, vecteur_t *v){
	copy_vecteur(b->v,v);
}
vecteur_t *get_boid_pos(boid_t *b){
	return b->v;
}
void add_boid_pos(boid_t *b, vecteur_t *v){
	add_vecteur(b->v,v);
}
void print_boid(boid_t *b){
	printf("<&°%st><l\n",toString_vecteur(b->v));	
}