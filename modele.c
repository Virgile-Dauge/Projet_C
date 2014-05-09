#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "vecteur.h"
#include "boid.h"

modele_t *new_modele(int maxBoid, int maxPre, int maxFood){
	//allocation mémoire du modele créé
	modele_t *modele = malloc(sizeof(modele_t));
	//si l'allocation a réussi
	if(modele){
		//on assigne des valeurs aux variables du modèle
		modele->maxBoid = maxBoid;
		modele->maxPre = maxPre;
		modele->maxFood = maxFood;
		modele->nbBoid = 0;
		modele->nbPre =0;
		modele->nbFood =0;		
		modele->nbBoidProx =0;
		modele->nbPreProx =0;
		modele->tabBoidProx = NULL;
		modele->tabPreProx = NULL;
		modele->foodProx = NULL;
		//allocation mémoire du tableau de pointeurs
		boid_t **tabBoid= malloc(maxBoid*sizeof(boid_t*));
		//si l'allocation a réussi
		if(tabBoid){
			//on dirige le pointeur du modele vers le tableau de pointeurs précédement créé
			modele->tabBoid = tabBoid;
		
		}else{
			//si l'allocation échoue : création du message d'erreur et arret 
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
    	//allocation mémoire du tableau de pointeurs
    	boid_t **tabPre= malloc(maxPre*sizeof(boid_t*));
		//si l'allocation a réussi
		if(tabPre){
			//on dirige le pointeur du modele vers le tableau de pointeurs précédement créé
			modele->tabPre = tabPre;
		}else{
			//si l'allocation échoue : création du message d'erreur et arret 
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
    	//allocation mémoire du tableau de pointeurs
    	vecteur_t **tabFood= malloc(maxFood*sizeof(vecteur_t*));
    	//si l'allocation a réussi
		if(tabFood){
			//on dirige le pointeur du modele vers le tableau de pointeurs précédement créé
			modele->tabFood = tabFood;
		}else{
			//si l'allocation échoue : création du message d'erreur et arret 
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
    	//allocation mémoire du tableau de pointeurs
    	boid_t **tabBoidProx= malloc(maxBoid*sizeof(boid_t*));
		//si l'allocation a réussi
		if(tabBoidProx){
			//on dirige le pointeur du modele vers le tableau de pointeurs précédement créé
			modele->tabBoidProx = tabBoidProx;
		
		}else{
			//si l'allocation échoue : création du message d'erreur et arret 
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
    	//allocation mémoire du tableau de pointeurs
    	boid_t **tabPreProx= malloc(maxPre*sizeof(boid_t*));
		//si l'allocation a réussi
		if(tabPreProx){
			//on dirige le pointeur du modele vers le tableau de pointeurs précédement créé
			modele->tabPreProx = tabPreProx;
		}else{
			//si l'allocation échoue : création du message d'erreur et arret 
        	fprintf (stderr, "Memoire insuffisante\n");
        	exit (EXIT_FAILURE);
    	}
    	return modele;
	}else{
		//si l'allocation échoue : création du message d'erreur et arret 
        fprintf (stderr, "Memoire insuffisante\n");
        exit (EXIT_FAILURE);
    }
}
int ajout_boid(modele_t *m, boid_t *b){
	//si on peut encore ajouter des boids
	if(m->nbBoid<m->maxBoid){
		//on ajoute un boid à la prochaine place disponible
		m->tabBoid[m->nbBoid] = b;
		m->nbBoid ++;
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int ajout_pre(modele_t *m, boid_t *p){
	//si on peut encore ajouter des predateurs
	if(m->nbPre<m->maxPre){
		//on ajoute un predateur à la prochaine place disponible
		m->tabPre[m->nbPre] = p;
		m->nbPre ++;
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int ajout_food(modele_t *m, vecteur_t *v){
	//si on peut encore ajouter de la nourriture
	if(m->nbFood<m->maxFood){
		//on ajoute un vecteur à la prochaine place disponible
		m->tabFood[m->nbFood] = v;
		m->nbFood ++;
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int retrait_boid(modele_t *m, int noBoid){
	//si le numéro du boid est cohérant
	if(noBoid>=0 && noBoid<m->maxBoid){
		int i;
		m->nbBoid--; //on décrémente le nombre de boids
		//puis on décale les autres boids dans le tableau pour combler le vide
		for(i=noBoid;i<m->nbBoid;i++){
			m->tabBoid[i] = m->tabBoid[i+1];
		}
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int retrait_pre(modele_t *m, int noPre){
	//si le numéro du prédateur est cohérant
	if(noPre>=0 && noPre<m->maxPre){
		int i;
		m->nbPre--; //on décrémente le nombre de boids
		//puis on décale les autres boids dans le tableau pour combler le vide
		for(i=noPre;i<m->nbPre;i++){
			m->tabPre[i] = m->tabPre[i+1];
		}
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int retrait_food(modele_t *m, int noFood){
	//si le numéro du prédateur est cohérant
	if(noFood>=0 && noFood<m->maxFood){
		int i;
		m->nbFood--; //on décrémente le nombre de boids
		//puis on décale les autres boids dans le tableau pour combler le vide
		for(i=noFood;i<m->nbFood;i++){
			m->tabFood[i] = m->tabFood[i+1];
		}
		//et on renvoie vrai
		return 1;
	}else{
		//sinon on renvoie faux
		return 0;
	}
}
int calcul_visibilite(modele_t *m, int noBoid){
	int i;
	m->nbBoidProx = 0;
	m->nbPreProx = 0;
	for(i=0;i<m->nbBoid;i++){
		if(i != noBoid){
			if(boid_can_see(m->tabBoid[noBoid],m->tabBoid[i]->pos)){
			m->tabBoidProx[m->nbBoidProx]= m->tabBoid[i];
			m->nbBoidProx++;
			}
		}
	}
	for(i=0;i<m->nbPre;i++){
		if(boid_can_see(m->tabBoid[noBoid],m->tabPre[i]->pos)){
			m->tabPreProx[m->nbPreProx]=m->tabPre[i];
			m->nbPreProx++;
		}
	}
	vecteur_t *depart = new_vecteur(10000,10000,10000);
	for(i=0;i<m->nbFood;i++){
		if(boid_can_see(m->tabBoid[noBoid],m->tabFood[i])){
			if(distance_boid(m->tabBoid[noBoid],depart)>distance_boid(m->tabBoid[noBoid],m->tabFood[i])){
				m->foodProx = m->tabFood[i];
			}
		}
	}
}
//les regles de calculs nécéssitent des calculs préparatoires (ici calcul_visibilite)
vecteur_t *regle_regroupement(modele_t *m,int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	for(i=0;i<m->nbBoidProx;i++){
		add_vecteur(result,m->tabBoidProx[i]->pos);
	}
	div_vecteur(result,m->nbBoidProx);
	div_vecteur(result,coefDeplacement);
	return result;
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