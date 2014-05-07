#include <stdio.h>
#include <stdlib.h>
#include "boid.h"
#include "vecteur.h"

boid_t *new_boid(vecteur_t *vect,double distanceVue){
	boid_t *b = malloc(sizeof(boid_t));
	b->pos = malloc(sizeof(vecteur_t));
	b->vit = malloc(sizeof(vecteur_t));
	b->r = rand()%(255);
	b->g = rand()%(255);
	b->b = rand()%(255);
	b->distanceVue = distanceVue;
	b->vit = new_vecteur(0,0,0);
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
int equals_boid(boid_t *b1, boid_t *b2){
	if((equals_vecteur(b1->pos,b2->pos) && equals_vecteur(b1->vit,b2->vit) && b1->r == b2->r && b1->g == b2->g && b1->b == b2->b && b1->distanceVue == b2->distanceVue){
		return 1;
	}else{
		return 0;
	}
}
int visible(boid_t *b, vecteur_t *posObjet){
	double x,y,z;
	x = b->pos->x - posObjet->x;
	if(x<0){
		x = -x;
	}
	y = b->pos->y - posObjet->y;
	if(y<0){
		y= -y;
	}
	z = b->pos->z - posObjet->z;
	if(z<0){
		z= -z;
	}
	if(x<b->distanceVue && y<b->distanceVue && z<b->distanceVue){
		return 1;
	}else{
		return 0;
	}
}
void print_boid(boid_t *b){
	printf("<&°%st><l\n",toString_vecteur(b->pos));	
}