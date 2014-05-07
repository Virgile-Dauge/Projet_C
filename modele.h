#ifndef MODELE_H
#define MODELE_H
#include "boid.h"
typedef struct modele{
	int nbBoid, maxBoid, nbPre, maxPre;
	boid_t *tabBoid;
} modele_t;
modele_t *new_modele(int maxBoid, int maxPre);
int ajout_boid(modele_t *m, boid_t *b);

int calcul_deplacement(int noBoid);
vecteur_t *somme_pos(boid_t *tab[],int tailleTab);
vecteur_t *regle_1(boid_t *b,vecteur_t *somme, int nbPoisson);
vecteur_t *regle_2(boid_t *b, vecteur_t *cMass, vecteur_t *distance, int nbPoisson);
vecteur_t *regle_3(boid_t *b, vecteur_t *Vsomme, int nbPoisson);

#endif

