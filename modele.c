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
	//pour tous les boids du modele
	for(i=0;i<m->nbBoid;i++){
		//si ce n'est pas le boid que l'on étudie
		if(i != noBoid){
			//si le boid que l'on étudie peut voir le boid à la position i du tableau de boids
			if(boid_can_see(m->tabBoid[noBoid],m->tabBoid[i]->pos)){
			//alors on stocke le boid visible dans le tableau des boids à proximité
			m->tabBoidProx[m->nbBoidProx]= m->tabBoid[i];
			//et on incrémente le nb de boids à proximité
			m->nbBoidProx++;
			}
		}
	}
	//pour tous les predateurs du modele
	for(i=0;i<m->nbPre;i++){
		//si le boid que l'on etudie peut voir le prédateur
		if(boid_can_see(m->tabBoid[noBoid],m->tabPre[i]->pos)){
			//alors on stocke le prédateur visible dans le tableau des prédateurs à proximité
			m->tabPreProx[m->nbPreProx]=m->tabPre[i];
			//et on incrémente le nb de prédateurs à proximité
			m->nbPreProx++;
		}
	}
	//création d'un vecteur de départ pour la comparaison de distance (considéré infini)
	vecteur_t *depart = new_vecteur(10000,10000,10000);
	//Pour tous les sources de nourriture du modèle
	for(i=0;i<m->nbFood;i++){
		//si le boid que l'on etudie peut voir la nourriture
		if(boid_can_see(m->tabBoid[noBoid],m->tabFood[i])){
			//Si la distance entre le boid et la nourriture et plus petite que le min précédent
			if(distance_boid(m->tabBoid[noBoid],depart)>distance_boid(m->tabBoid[noBoid],m->tabFood[i])){
				//on met a jour l'élément comparateur
				depart = m->tabFood[i];
				//on stocke la position de la nourriture la plus proche
				m->foodProx = m->tabFood[i];
			}
		}
	}
}
//les regles de calculs nécéssitent des calculs préparatoires (ici calcul_visibilite)
vecteur_t *regle_regroupement(modele_t *m,int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	//pour chaque boid à proximité (visible)
	for(i=0;i<m->nbBoidProx;i++){
		//on ajoute vecteur position du boid a la somme des vecteurs position 
		add_vecteur(result,m->tabBoidProx[i]->pos);
	}
	//on divisse la somme des vecteurs positions par le nombre de boids pris en compte
	div_vecteur(result,m->nbBoidProx);
	//on divise le vecteur position obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
vecteur_t *regle_evitement(modele_t *m,int noBoid, double distance){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	double distanceReele =0;
	//pour tous les boids à proximité de celui étudié
	for(i=0;i<m->nbBoidProx;i++){
		//on calcule la distance séparant le boid de celui étudié
		distanceReele = distance_boid(m->tabBoid[noBoid],m->tabBoidProx[i]->pos);
		//si cette distance est inferieur à la distance de seuil passée en parametre
		if(distanceReele < distance){
			//on ajoute au vecteur résultat la position du boid que l'on étudie
			add_vecteur(result,m->tabBoid[noBoid]->pos);
			//on soustrait au vecteur résultat la position du boid qui est trop pres
			sub_vecteur(result,m->tabBoidProx[i]->pos);
		}
	}
	return result;
}
vecteur_t *regle_harmonisation(modele_t *m,int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	//pour chaque boid à proximité (visible)
	for(i=0;i<m->nbBoidProx;i++){
		//on ajoute vecteur position du boid a la somme des vecteurs vitesse 
		add_vecteur(result,m->tabBoidProx[i]->vit);
	}
	//on divisse la somme des vecteurs vitesse par le nombre de boids pris en compte
	div_vecteur(result,m->nbBoidProx);
	//on divise le vecteur obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
//calcule et retourne le vecteur de déplacement d'un besoin primaire du boid
vecteur_t *regle_aTable(modele_t *m, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	copy_vecteur(result,m->foodProx);
	//on divise le vecteur obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
vecteur_t *regle_fuitePre(modele_t *m,int noBoid, int coefDeplacement,int distanceCrit){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	double distanceReele =0;
	for(i=0;i<m->nbPreProx;i++){
		//on calcule la distance séparant le boid de celui étudié
		distanceReele = distance_boid(m->tabBoid[noBoid],m->tabPreProx[i]->pos);
		//si cette distance est inferieur à la distance de seuil passée en parametre
		if(distanceReele < distanceCrit){
			//on ajoute au vecteur résultat la position du boid que l'on étudie
			add_vecteur(result,m->tabBoid[noBoid]->pos);
			//on soustrait au vecteur résultat la position du predateur qui est trop pres
			sub_vecteur(result,m->tabPreProx[i]->pos);
		}
	}
	//on divise le vecteur obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
int calcul_deplacement_boids(modele_t *m){
	int i;
	vecteur_t *result = new_vecteur(0,0,0);
	for(i=0;i<m->nbBoid;i++){
		calcul_visibilite(m,i);
		add_vecteur(result,regle_regroupement(m,10));
		add_vecteur(result,regle_evitement(m,i,5));
		add_vecteur(result,regle_harmonisation(m,10));
		add_vecteur(result,regle_aTable(m,10));
		add_vecteur(result,regle_fuitePre(m,i,5,50));
		m->tabBoid[i]->vit = result;
		add_vecteur(m->tabBoid[i]->pos,m->tabBoid[i]->vit);
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