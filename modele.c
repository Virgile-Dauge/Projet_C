#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "vecteur.h"
#include "boid.h"

modele_t *new_modele(int maxBoid, int maxPre, int maxFood,int dimention3){
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
		modele->foodProx = new_vecteur(1000,1000,1000);
		modele->dimention3 = dimention3;
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
			if(boid_can_see(m->tabBoid[noBoid],m->tabBoid[i]->pos,m->dimention3)){
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
		if(boid_can_see(m->tabBoid[noBoid],m->tabPre[i]->pos,m->dimention3)){
			//alors on stocke le prédateur visible dans le tableau des prédateurs à proximité
			m->tabPreProx[m->nbPreProx]=m->tabPre[i];
			//et on incrémente le nb de prédateurs à proximité
			m->nbPreProx++;
		}
	}
	//création d'un vecteur de départ pour la comparaison de distance (considéré infini)
	vecteur_t *depart = new_vecteur(100000,100000,100000);
	//Pour tous les sources de nourriture du modèle
	for(i=0;i<m->nbFood;i++){
		//si le boid que l'on etudie peut voir la nourriture
		if(boid_can_see(m->tabBoid[noBoid],m->tabFood[i],m->dimention3)){
			//Si la distance entre le boid et la nourriture et plus petite que le min précédent
			if(m->dimention3){
				if(distance_boid(m->tabBoid[noBoid],depart)>distance_boid(m->tabBoid[noBoid],m->tabFood[i])){
					//on met a jour l'élément comparateur
					depart = m->tabFood[i];
					//on stocke la position de la nourriture la plus proche
					m->foodProx = m->tabFood[i];
				}
			}else{
				if(distance_boid_2d(m->tabBoid[noBoid],depart)>distance_boid_2d(m->tabBoid[noBoid],m->tabFood[i])){
					//on met a jour l'élément comparateur
					depart = m->tabFood[i];
					//on stocke la position de la nourriture la plus proche
					m->foodProx = m->tabFood[i];
				}
			}
		}
	}
	return 1;
}
vecteur_t *regle_random(modele_t *m,int noBoid, int coefDeplacement){
	vecteur_t *result = new_vecteur(rand()%(100),rand()%(100),rand()%(100));
	sub_vecteur(result,m->tabBoid[noBoid]->pos);
	//on divise le vecteur position obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
//les regles de calculs nécéssitent des calculs préparatoires (ici calcul_visibilite)
vecteur_t *regle_regroupement(modele_t *m,int noBoid, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	//pour chaque boid à proximité (visible)
	for(i=0;i<m->nbBoidProx;i++){
		//on ajoute vecteur position du boid a la somme des vecteurs position 
		add_vecteur(result,m->tabBoidProx[i]->pos);
	}
	//on divisse la somme des vecteurs positions par le nombre de boids pris en compte
	div_vecteur(result,m->nbBoidProx);
	sub_vecteur(result,m->tabBoid[noBoid]->pos);
	//on divise le vecteur position obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
vecteur_t *regle_evitement(modele_t *m,int noBoid, double distance, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	double distanceReele =0;
	//pour tous les boids à proximité de celui étudié
	for(i=0;i<m->nbBoidProx;i++){
		if(m->dimention3){
			//on calcule la distance séparant le boid de celui étudié
			distanceReele = distance_boid(m->tabBoid[noBoid],m->tabBoidProx[i]->pos);
		}else{
			//on calcule la distance séparant le boid de celui étudié
			distanceReele = distance_boid_2d(m->tabBoid[noBoid],m->tabBoidProx[i]->pos);
		}
		//si cette distance est inferieur à la distance de seuil passée en parametre
		if(distanceReele < distance){
			//on ajoute au vecteur résultat la position du boid que l'on étudie
			add_vecteur(result,m->tabBoid[noBoid]->pos);
			//on soustrait au vecteur résultat la position du boid qui est trop pres
			sub_vecteur(result,m->tabBoidProx[i]->pos);
			div_vecteur(result,coefDeplacement);
		}
	}
	return result;
}
vecteur_t *regle_harmonisation(modele_t *m,int noBoid, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	//pour chaque boid à proximité (visible)
	for(i=0;i<m->nbBoidProx;i++){
		//on ajoute vecteur position du boid a la somme des vecteurs vitesse 
		add_vecteur(result,m->tabBoidProx[i]->vit);
	}
	//on divisse la somme des vecteurs vitesse par le nombre de boids pris en compte
	div_vecteur(result,m->nbBoidProx);
	sub_vecteur(result,m->tabBoid[noBoid]->pos);
	//on divise le vecteur obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
//calcule et retourne le vecteur de déplacement d'un besoin primaire du boid
vecteur_t *regle_aTable(modele_t *m,int noBoid, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	copy_vecteur(result,m->foodProx);
	sub_vecteur(result,m->tabBoid[noBoid]->pos);
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
		if(m->dimention3){
			//on calcule la distance séparant le boid de celui étudié
			distanceReele = distance_boid(m->tabBoid[noBoid],m->tabPreProx[i]->pos);
		}else{
			//on calcule la distance séparant le boid de celui étudié
			distanceReele = distance_boid_2d(m->tabBoid[noBoid],m->tabPreProx[i]->pos);
		}
		
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
vecteur_t *regle_centre(modele_t *m, int noBoid, int coefDeplacement){
	vecteur_t *result = new_vecteur(1000,1000,1000);
	
	sub_vecteur(result,m->tabBoid[noBoid]->pos);
	//on divise le vecteur position obtenu pour simuler la lenteur du déplacement du boid
	div_vecteur(result,coefDeplacement);
	//on retourne le vecteur de déplacement obtenu
	return result;
}
void limite_vit(vecteur_t *v,double limite){
	v->x = limite_valeur(v->x,limite);
	v->y = limite_valeur(v->y,limite);
	v->z = limite_valeur(v->z,limite);

}
double limite_valeur(double x,double limite){
	if(x >0){
		if(x>limite){
			x = limite;
		}
	}else{
		if(x<-limite){
			x = -limite;
		}
	}
	return x;
}
int application_deplacement(boid_t *b, vecteur_t *v,int coefConservation , int coefReaction){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	int cpt=0;
	for(i=0;i<coefConservation;i++){
		add_vecteur(result,b->vit);
		cpt++;
	}
	for(i=0;i<coefReaction;i++){
		add_vecteur(result,v);
		cpt++;
	}
	div_vecteur(result,cpt);
	copy_vecteur(b->vit,result);
	add_vecteur(b->pos,b->vit);
	return 1;
}
int calcul_deplacement_boids(modele_t *m){
	int i;
	vecteur_t *result = new_vecteur(0,0,0);
	for(i=0;i<m->nbBoid;i++){
		calcul_visibilite(m,i);
		
		add_vecteur(result,regle_random(m,i,100000));
		
		add_vecteur(result,regle_regroupement(m,i,250));

		add_vecteur(result,regle_evitement(m,i,2,1000));

		//donne des résultats.... inatendus
		//add_vecteur(result,regle_harmonisation(m,i,10000));
		
		add_vecteur(result,regle_aTable(m,i,1100));
		
		add_vecteur(result,regle_fuitePre(m,i,100,500));

		add_vecteur(result,regle_centre(m,i,8000));
		
		limite_vit(result,5);

		application_deplacement(m->tabBoid[i],result,10,4);
	}
	return 1;
}
int recherche_proies(modele_t *m,int noPre){
	int i;
	m->nbBoidProx = 0;
	//pour tous les boids du modele
	for(i=0;i<m->nbBoid;i++){
		//si le boid que l'on étudie peut voir le boid à la position i du tableau de boids
		if(boid_can_see(m->tabPre[noPre],m->tabBoid[i]->pos,m->dimention3)){
			//alors on stocke le boid visible dans le tableau des boids à proximité
			m->tabBoidProx[m->nbBoidProx]= m->tabBoid[i];
			//et on incrémente le nb de boids à proximité
			m->nbBoidProx++;
		}
	}
	return 1;
}
vecteur_t *chasse(modele_t *m,int noPre, int coefDeplacement){
	vecteur_t *result = new_vecteur(0,0,0);
	int i;
	double distanceReele =0;
	double distanceMin = 100000;
 	//pour tous les boids à proximité de celui étudié
	for(i=0;i<m->nbBoidProx;i++){
		if(m->dimention3){
			//on calcule la distance séparant le boid du predateur
			distanceReele = distance_boid(m->tabPre[noPre],m->tabBoidProx[i]->pos);
		}else{
			//on calcule la distance séparant le boid du predateur
			distanceReele = distance_boid_2d(m->tabPre[noPre],m->tabBoidProx[i]->pos);
		}
		//si cette distance est inferieur à la distance de seuil passée en parametre
		if(distanceReele < distanceMin){
			distanceMin = distanceReele;
			//on recopie la position du boid le plus proche dans result
			copy_vecteur(result,m->tabBoidProx[i]->pos);
		}
	}
	//on soustrait au vecteur résultat la position du predateur
	sub_vecteur(result,m->tabPre[noPre]->pos);
	//on simule le déplacement
	div_vecteur(result,coefDeplacement);
	return result;
}
int calcul_deplacement_preds(modele_t*m){
	int i;
	vecteur_t *result = new_vecteur(0,0,0);
	for(i=0;i<m->nbPre;i++){
		recherche_proies(m,i);

		add_vecteur(result,chasse(m,i,100));
		
		limite_vit(result,10);
		
		application_deplacement(m->tabPre[i],result,10,3);
	}
	return 1;
}
