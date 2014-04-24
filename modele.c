#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "vecteur.h"
#include "boid.h"

int init_modele(){

}
int calcul_deplacements(boid_t *tab[], int tailleTab){
	vecteur_t * somme = somme_pos(tab[]);
	vecteur_t *tabVect[];
	int i;
	for(i=0;i<tailleTab;i++){
		tabVect[1]=regle_1(tab[i])
		//
		//
		add_multi_vecteur(tab[i]->v,tabVect,tailleTab);

	}
}
vecteur_t *somme_pos(boid_t *tab[],int tailleTab){
	vecteur_t *somme = new_vecteur(0,0,0);
	for (i=0;i<tailleTab;i++){
		add_vecteur(somme,tab[i]->v);
	}
	return somme;
}
vecteur_t *regle_1(boid * b,vecteur_t * somme, int nbPoisson){
	vecteur_t *v = new_vecteur(0,0,0);
	copy_vecteur(v,somme);
	div_vecteur(sub_vecteur(v, vecteur_t), nbPoisson);
	return v;
}


vecteur_t *regle_2(boid *b, vecteur *v){
	
}
