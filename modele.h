#ifndef MODELE_H
#define MODELE_H
#include "boid.h"

int init_modele();
int calcul_deplacements(boid_t *tab[],int noBoid, int tailleTab);
vecteur_t *somme_pos(boid_t *tab[],int tailleTab);
vecteur_t *regle_1(boid_t *b,vecteur_t *somme, int nbPoisson);
vecteur_t *regle_2(boid_t *b, vecteur_t *cMass, vecteur_t *distance, int nbPoisson);
vecteur_t *regle_3(boid_t *b, vecteur_t *Vsomme, int nbPoisson);
#endif

