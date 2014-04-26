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
		tabVect[2]=regle_2(tab[i])
		tabVect[3]=regle_3(tab[i])
		//
		//
		add_multi_vecteur(tab[i]->pos,tabVect,tailleTab);

	}
}
vecteur_t *somme_pos(boid_t *tab[],int tailleTab){
	vecteur_t *somme = new_vecteur(0,0,0);
	for (i=0;i<tailleTab;i++){
		add_vecteur(somme,tab[i]->pos);
	}
	return somme;
}
vecteur_t *somme_vit(boid_t *tab[],int tailleTab){
	vecteur_t *Vsomme = new_vecteur(0,0,0);
	for (i=0;i<tailleTab;i++){
		add_vecteur(Vsomme,tab[i]->vit);
	}
	return vsomme;  // SOMME DES VITESSES
}
vecteur_t *regle_1(boid * b,vecteur_t * somme, int nbPoisson){
	vecteur_t *pos = new_vecteur(0,0,0);
	copy_vecteur(pos,somme);
	div_vecteur(sub_vecteur(pos, vecteur_t), nbPoisson);
	return pos;
}
vecteur_t *regle_2(boid *b, vecteur_t *cMass, vecteur_t *distance, int nbPoisson){
	vecteur_t *cMass= new_vecteur(0,0,0);  // vecteur centre de mass
	vecteur_t *cMass=vecteur_t *cMass/nbPoisson;
	vecteur_t *distance= sub_vecteur(vecteur_t *somme_pos, vecteur_t) // distance entre les poissons
	if(vecteur_t *distance <1OO){
		sub(vecteur_t *cMass, vecteur_t *distance);
	}
		return vecteur_t *distance;
}

vecteur_t *regle_3(boid *b, vecteur_t *Vsomme, int nbPoisson){
	vecteur_t *vit = new_vecteur(0,0,0);
	copy_vecteur(vit, Vsomme);
	if(b != boid_t){
add_vecteur(Vsomme, Vboid)
	}
	div_vecteur(Vsomme, nbPoisson);
	div_vecteur(sub_vecteur(Vsomme,vecteur_t *vit), int 8);
	return vit
}