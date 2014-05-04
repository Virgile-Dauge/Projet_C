#include <stdio.h>
#include <stdlib.h>
#include "boid.h"
#include "vecteur.h"

boid_t *new_boid(vecteur_t *vect){
	boid_t *b = malloc(sizeof(boid_t));
	b->pos = malloc(sizeof(vecteur_t));
	b->id = 0;
	copy_vecteur(b->pos,vect);
	return b;
}
void set_boid_pos(boid_t *b, vecteur_t *pos){
	copy_vecteur(b->pos,pos);
}
vecteur_t *get_boid_pos(boid_t *b){
	return b->pos;
}
void add_boid_pos(boid_t *b, vecteur_t *pos){
	add_vecteur(b->pos,pos);
}
void print_boid(boid_t *b){
	printf("<&°%st><l\n",toString_vecteur(b->pos));	
}