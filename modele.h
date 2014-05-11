	#ifndef MODELE_H
#define MODELE_H
#include "vecteur.h"
#include "boid.h"
typedef struct modele{
	int nbBoid, maxBoid, nbPre, maxPre, nbBoidProx, nbPreProx, nbFood, maxFood,dimention3;
	boid_t **tabBoid;
	boid_t **tabPre;
	vecteur_t **tabFood;
	boid_t **tabBoidProx;
	boid_t **tabPreProx;
	vecteur_t *foodProx;
} modele_t;
modele_t *new_modele(int maxBoid, int maxPre, int maxFood, int dimention3);
int ajout_boid(modele_t *m, boid_t *b);
int ajout_pre(modele_t *m, boid_t *b);
int ajout_food(modele_t *m, vecteur_t *v);
int retrait_boid(modele_t *m, int noBoid);
int retrait_pre(modele_t *m, int noBoid);
int retrait_food(modele_t *m, int noBoid);
int calcul_visibilite(modele_t *m, int noBoid);
vecteur_t *regle_random(int coefDeplacement);
vecteur_t * regle_regroupement(modele_t *m,int coefDeplacement);
vecteur_t *regle_evitement(modele_t *m,int noBoid, double distance);
vecteur_t *regle_harmonisation(modele_t *m,int coefDeplacement);
vecteur_t *regle_aTable(modele_t *m, int coefDeplacement);
vecteur_t *regle_fuitePre(modele_t *m, int noBoid, int coefDeplacement,int distanceCrit);
vecteur_t *regle_centre(int coefDeplacement);
int calcul_deplacement_boids(modele_t *m);


#endif

