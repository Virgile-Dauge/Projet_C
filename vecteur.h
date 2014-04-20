#ifndef VECTEUR_H
#define VECTEUR_H

typedef struct vecteur{
	double x,y,z;
} vecteur_t;

vecteur_t *new_vecteur(double x, double y, double z);
void add_vecteur(vecteur_t *v1, vecteur_t *v2);
void add_multi_vecteurs(vecteur_t *v1, vecteur_t *tab[], int tailleTab);
void set_vecteur(vecteur_t *v, double x, double y, double z);
int equals_vecteur(vecteur_t *v0,vecteur_t *v1);
void print_vecteur(vecteur_t *v);
char *toString_vecteur(vecteur_t *v);
#endif