#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "vecteur.h"
#include "boid.h"
modele_t *new_modele(int maxBoid, int maxPre){
	modele_t *modele = malloc(sizeof(modele_t));
	if(modele){
		modele->maxBoid = maxBoid;
		modele->maxPre = maxPre;
		boid_t *tabBoid = malloc(maxBoid*sizeof(boid_t));
		if(tabBoid){ 
			modele->tabBoid = tabBoid;
			return modele;
		}else{
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
	}else{
        fprintf (stderr, "Memoire insuffisante\n");
        exit (EXIT_FAILURE);
    }
}
int ajout_boid(modele_t *m, boid_t *b){
	//si on peut encore ajouter des boids
	if(m->nbBoid<m->maxBoid){
		//on ajoute un boid à la prochaine place disponible
		m->tabBoid[m->nbBoid+1] = *b;
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
	
}
/*
int calcul_deplacement(int noBoid){
	vecteur_t * somme = somme_pos(tab,tailleTab);
	vecteur_t *tabVect[4];
	tabVect[1]=regle_1(tab[noBoid],somme,tailleTab);
	/*
	tabVect[2]=regle_2(tab[noBoid],);
	tabVect[3]=regle_3(tab[noBoid]);
	
	add_multi_vecteurs(tab[noBoid]->pos,tabVect,tailleTab);
}
vecteur_t *somme_pos(boid_t *tab[],int tailleTab){
	vecteur_t *somme = new_vecteur(0,0,0);
	int i;
	for (i=0;i<tailleTab;i++){
		add_vecteur(somme,tab[i]->pos);
	}
	return somme;
}
vecteur_t *somme_vit(boid_t *tab[],int tailleTab){
	vecteur_t *vsomme = new_vecteur(0,0,0);
	int i;
	for (i=0;i<tailleTab;i++){
		add_vecteur(vsomme,tab[i]->vit);
	}
	return vsomme;  // SOMME DES VITESSES
}
vecteur_t *regle_1(boid_t *b,vecteur_t *somme, int nbPoisson){
	vecteur_t *pos = new_vecteur(0,0,0);
	copy_vecteur(pos,somme);
	sub_vecteur(pos, b->pos);
	div_vecteur(pos, nbPoisson);
	return pos;
}
/*
vecteur_t *regle_2(boid_t *b, vecteur_t *cMass, vecteur_t *distance, int nbPoisson){
	vecteur_t *cMass= new_vecteur(0,0,0);  // vecteur centre de mass
	cMass= cMass/nbPoisson;
	vecteur_t *distance= sub_vecteur(vecteur_t *somme_pos, vecteur_t) // distance entre les poissons
	if(vecteur_t *distance <1OO){
		sub(vecteur_t *cMass, vecteur_t *distance);
	}
		return vecteur_t *distance;
}
vecteur_t *regle_3(boid_t *b, vecteur_t *Vsomme, int nbPoisson){
	vecteur_t *vit = new_vecteur(0,0,0);
	copy_vecteur(vit, Vsomme);
	if(b != boid_t){
		add_vecteur(Vsomme, Vboid);
	}
	div_vecteur(Vsomme, nbPoisson);
	div_vecteur(sub_vecteur(Vsomme,vecteur_t *vit), int 8);
	return vit
}
*/