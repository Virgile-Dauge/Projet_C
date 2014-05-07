#ifndef VECTEUR_H
#define VECTEUR_H

typedef struct vecteur{
	double x,y,z;
} vecteur_t;

vecteur_t *new_vecteur(double x, double y, double z);
void add_vecteur(vecteur_t *pos1, vecteur_t *pos2);
void add_multi_vecteurs(vecteur_t *pos1, vecteur_t *tab[], int tailleTab);
void sub_vecteur(vecteur_t *pos1, vecteur_t *pos2);
void div_vecteur(vecteur_t *pos1, int coef);
void set_vecteur(vecteur_t *pos, double x, double y, double z);
void copy_vecteur(vecteur_t *pos,vecteur_t *source);
int equals_vecteur(vecteur_t *pos0,vecteur_t *pos1);
void print_vecteur(vecteur_t *pos);
char *toString_vecteur(vecteur_t *pos);
#endif
