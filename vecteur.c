#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
vecteur_t *new_vecteur(double x, double y, double z){
	vecteur_t *pos = malloc(sizeof(vecteur_t));
	if (pos){
		pos->x = x;
		pos->y = y; 
		pos->z = z;
		return pos;
	}else{
        fprintf (stderr, "Memoire insuffisante\n");
        exit (EXIT_FAILURE);
    }
}
void add_vecteur(vecteur_t *pos1, vecteur_t *pos2){
	pos1->x += pos2->x;
	pos1->y += pos2->y;
	pos1->z += pos2->z;
}
void sub_vecteur(vecteur_t *pos1, vecteur_t *pos2){
	pos1->x -= pos2->x;
	pos1->y -= pos2->y;
	pos1->z -= pos2->z;
}
void div_vecteur(vecteur_t *pos1, int coef){
	if(coef == 0){
		coef =1;
	}
	pos1->x=pos1->x/coef;
	pos1->y=pos1->y/coef;
	pos1->z=pos1->z/coef;
}
void add_multi_vecteurs(vecteur_t *pos1, vecteur_t *tab[], int tailleTab){
	int i;
	for(i=0;i<tailleTab;i++){
		if(tab[i]!=NULL){
			add_vecteur(pos1,tab[i]);
		}
	}
}
void set_vecteur(vecteur_t *pos, double x, double y, double z){
	pos->x = x;
	pos->y = y; 
	pos->z = z;
}
void copy_vecteur(vecteur_t *pos,vecteur_t *source){
	pos->x = source->x;
	pos->y = source->y; 
	pos->z = source->z;
}
int equals_vecteur(vecteur_t *pos0,vecteur_t *pos1){
	if(pos0->x == pos1->x && pos0->y == pos1->y && pos0->z == pos1->z){
		return 1;
	}else{
		return 0;
	}
}
void print_vecteur(vecteur_t *pos){
	printf("(%f,%f,%f)\n",pos->x , pos->y, pos->z);
}
char *toString_vecteur(vecteur_t *pos){
	char *chaine = NULL;
	sprintf(chaine,"(%f,%f,%f)\n",pos->x , pos->y, pos->z);
	return chaine;
}