#include <stdio.h>
#include <stdlib.h>
#include "boid.h"
#include "vecteur.h"
#include <math.h>

boid_t *new_boid(vecteur_t *vect,double distanceVue){
	boid_t *b = malloc(sizeof(boid_t));
	if(b){
		b->pos = malloc(sizeof(vecteur_t));
		if(b->pos){
			copy_vecteur(b->pos,vect);
		}else{
         	fprintf (stderr, "Memoire insuffisante\n");
         	exit (EXIT_FAILURE);
    	}
		b->vit = malloc(sizeof(vecteur_t));
		if(b->vit){
			b->vit = new_vecteur(0,0,0);
		}else{
         	fprintf (stderr, "Memoire insuffisante\n");
         	exit (EXIT_FAILURE);
    	}
		b->r = rand()%(255);
		b->g = rand()%(255);
		b->b = rand()%(255);
		if(distanceVue<0){
			distanceVue = -distanceVue;
		}
		b->distanceVue = distanceVue;
	}else{
        fprintf (stderr, "Memoire insuffisante\n");
        exit (EXIT_FAILURE);
    }
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
int equals_boid(boid_t *b1, boid_t *b2){
	if(equals_vecteur(b1->pos,b2->pos) && equals_vecteur(b1->vit,b2->vit) && b1->distanceVue == b2->distanceVue){
		return 1;
	}else{
		return 0;
	}
}
double distance_boid(boid_t *b, vecteur_t *v){
	return sqrt(pow(b->pos->x - v->x,2)+pow(b->pos->y - v->y,2)+pow(b->pos->z - v->z,2));
}
int boid_can_see(boid_t *b, vecteur_t *posObjet){
	double distance = distance_boid(b,posObjet);
	if(distance < b->distanceVue){
		return 1;
	}else{
		return 0;
	}
}
void print_boid(boid_t *b){
	printf("<&°%st><l\n",toString_vecteur(b->pos));	
}