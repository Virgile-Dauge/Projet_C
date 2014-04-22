#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
vecteur_t *new_vecteur(double x, double y, double z){
	vecteur_t *v = malloc(sizeof(vecteur_t));
	v->x = x;
	v->y = y; 
	v->z = z;
	return v;
}
void add_vecteur(vecteur_t *v1, vecteur_t *v2){
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}
void add_multi_vecteurs(vecteur_t *v1, vecteur_t *tab[], int tailleTab){
	int i;
	for(i=0;i<tailleTab;i++){
		if(tab[i]!=NULL){
			add_vecteur(v1,tab[i]);
		}
	}
}
void set_vecteur(vecteur_t *v, double x, double y, double z){
	v->x = x;
	v->y = y; 
	v->z = z;
}
void copy_vecteur(vecteur_t *v,vecteur_t *source){
	v->x = source->x;
	v->y = source->y; 
	v->z = source->z;
}
int equals_vecteur(vecteur_t *v0,vecteur_t *v1){
	if(v0->x == v1->x && v0->y == v1->y && v0->z == v1->z){
		return 1;
	}else{
		return 0;
	}
}
void print_vecteur(vecteur_t *v){
	printf("(%f,%f,%f\n)",v->x , v->y, v->z);
}
char *toString_vecteur(vecteur_t *v){
	char *chaine;
	sprintf(chaine,"(%f,%f,%f)\n",v->x , v->y, v->z);
	return chaine;
}