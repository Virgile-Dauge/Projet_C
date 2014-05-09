#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "boid.h"
#include "vecteur.h"

/*compilation:
gcc modeleTest.c modele.c boid.c vecteur.c -o modeleTest -lm -Wall -Wextra -Wunreachable-code -Wwrite-strings
*/
int new_modele_test();
int ajout_boid_test();
int ajout_pre_test();
int ajout_food_test();
int retrait_boid_test();
int retrait_pre_test();
int retrait_food_test();
int calcul_visibilite_test();
int regle_regroupement_test();
int regle_evitemment_test();
int regle_harmonisation_test();
int regle_aTable_test();
int regle_fuitePre_test();

int main(int argc, char** argv){
	new_modele_test();
	ajout_boid_test();
	ajout_pre_test();
	ajout_food_test();
	retrait_boid_test();
	retrait_pre_test();
	retrait_food_test();
	calcul_visibilite_test();
	regle_regroupement_test();
	regle_evitemment_test();
	regle_harmonisation_test();
	regle_aTable_test();
	regle_fuitePre_test();
	return 1;
}
int new_modele_test(){
	modele_t *m = new_modele(100,10,0);
	if(m->maxBoid == 100 && m->maxPre == 10){
		printf("new_modele [OK]\n");
		return 1;
	}else{
		printf("new_modele [NOK]\n");
		return 0;
	}
}
int ajout_boid_test(){
	int ok =1;
	//test d'ajout dans de bonnes conditions
	modele_t *m = new_modele(100,10,0);
	boid_t *b = new_boid(new_vecteur(0,0,0),10);
	ajout_boid(m,b);
	if(!equals_boid(b,m->tabBoid[0])){
		ok = 0;
	}
	//test de débordement
	modele_t *m0 = new_modele(0,0,0);
	if(ajout_boid(m0,b)){
		ok = 0;
	}

	//résultat des tests
	if(ok){
		printf("ajout_boid [OK]\n");
		return 1;
	}else{
		printf("ajout_boid [NOK]\n");
		return 0;
	}
}
int ajout_pre_test(){
	int ok=1;

	//test d'ajout dans de bonnes conditions
	modele_t *m = new_modele(100,10,0);
	boid_t *b = new_boid(new_vecteur(0,0,0),10);
	ajout_pre(m,b);
	if(!equals_boid(b,m->tabPre[0])){
		ok=0;
	}

	//test de débordement
	modele_t *m0 = new_modele(0,0,0);
	if(ajout_pre(m0,b)){
		ok = 0;
		printf("ajout_pre [débordement]\n");
	}

	//résultat des tests
	if(ok){
		printf("ajout_pre [OK]\n");
		return 1;
	}else{
		printf("ajout_pre [NOK]\n");
		return 0;
	}
}
int ajout_food_test(){
	int ok =1;
	//test d'ajout dans de bonnes conditions
	modele_t *m = new_modele(100,10,1);
	vecteur_t *v = new_vecteur(0,0,0);
	ajout_food(m,v);
	if(!equals_vecteur(v,m->tabFood[0])){
		ok = 0;
	}

	//test de débordement
	if(ajout_food(m,v)){
		ok = 0;
	}

	//résultat des tests
	if(ok){
		printf("ajout_food [OK]\n");
		return 1;
	}else{
		printf("ajout_food [NOK]\n");
		return 0;
	}
}
int retrait_boid_test(){
	int ok = 1;

	modele_t *metalon = new_modele(100,10,0);
	modele_t *m = new_modele(100,10,0);
	boid_t *b = new_boid(new_vecteur(0,0,0),10);
	boid_t *b0 = new_boid(new_vecteur(0,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(1,0,0),10);
	boid_t *b2 = new_boid(new_vecteur(0,2,0),15);
	boid_t *b3 = new_boid(new_vecteur(0,0,5),10);

	//test de débordement
	if(retrait_boid(m,200)){
		ok = 0;
		printf("retrait_boid [débordement]\n");
	}

	//remplissage du tableau de boids de l'étalon
	ajout_boid(metalon,b);
	ajout_boid(metalon,b);
	ajout_boid(metalon,b0);
	ajout_boid(metalon,b1);
	ajout_boid(metalon,b2);
	ajout_boid(metalon,b3);

	//remplissage du tableau de boids ou l'opération de retrait sera effectuée
	ajout_boid(m,b);
	ajout_boid(m,b);
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	retrait_boid(m,2);

	int i;
	for(i=0;i<metalon->nbBoid;i++){
		if(!equals_boid(m->tabBoid[i],metalon->tabBoid[i])){
			ok = 0;
		}
	}
	if(ok){
		printf("retrait_boid [OK]\n");
		return 1;
	}else{
		printf("retrait_boid [NOK]\n");
		return 0;
	}
}
int retrait_pre_test(){
	int ok = 1;

	modele_t *metalon = new_modele(100,10,0);
	modele_t *m = new_modele(100,10,0);
	boid_t *b = new_boid(new_vecteur(0,0,0),10);
	boid_t *b0 = new_boid(new_vecteur(0,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(1,0,0),10);
	boid_t *b2 = new_boid(new_vecteur(0,2,0),15);
	boid_t *b3 = new_boid(new_vecteur(0,0,5),10);

	//test de débordement
	if(retrait_pre(m,200)){
		ok = 0;
		printf("retrait_pre [débordement]\n");
	}

	//remplissage du tableau de boids de l'étalon
	ajout_pre(metalon,b);
	ajout_pre(metalon,b);
	ajout_pre(metalon,b0);
	ajout_pre(metalon,b1);
	ajout_pre(metalon,b2);
	ajout_pre(metalon,b3);

	//remplissage du tableau de boids ou l'opération de retrait sera effectuée
	ajout_pre(m,b);
	ajout_pre(m,b);
	ajout_pre(m,b);
	ajout_pre(m,b0);
	ajout_pre(m,b1);
	ajout_pre(m,b2);
	ajout_pre(m,b3);

	retrait_pre(m,2);

	int i;
	for(i=0;i<metalon->nbPre;i++){
		if(!equals_boid(m->tabPre[i],metalon->tabPre[i])){
			ok = 0;
		}
	}
	if(ok){
		printf("retrait_pre [OK]\n");
		return 1;
	}else{
		printf("retrait_pre [NOK]\n");
		return 0;
	}
}
int retrait_food_test(){
	int ok = 1;

	modele_t *metalon = new_modele(100,10,10);
	modele_t *m = new_modele(100,10,10);

	vecteur_t *v = new_vecteur(0,0,0);
	vecteur_t *v0 = new_vecteur(0,0,0);
	vecteur_t *v1 = new_vecteur(1,0,0);
	vecteur_t *v2 = new_vecteur(0,2,0);
	vecteur_t *v3 = new_vecteur(0,0,5);

	//test de débordement
	if(retrait_food(m,200)){
		ok = 0;
		printf("retrait_food [débordement]\n");
	}

	ajout_food(metalon,v);
	ajout_food(metalon,v);
	ajout_food(metalon,v0);
	ajout_food(metalon,v1);
	ajout_food(metalon,v2);
	ajout_food(metalon,v3);

	ajout_food(m,v);
	ajout_food(m,v);
	ajout_food(m,v);
	ajout_food(m,v0);
	ajout_food(m,v1);
	ajout_food(m,v2);
	ajout_food(m,v3);

	retrait_food(m,2);

	int i;

	for(i=0;i<metalon->nbFood;i++){
		if(!equals_vecteur(m->tabFood[i],metalon->tabFood[i])){
			ok = 0;
		}
	}
	if(ok){
		printf("retrait_food [OK]\n");
		return 1;
	}else{
		printf("retrait_food [NOK]\n");
		return 0;
	}
}
int calcul_visibilite_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);
	boid_t *b0 = new_boid(new_vecteur(15,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(1,0,56.5),10);
	boid_t *b2 = new_boid(new_vecteur(10,250,0),10);
	boid_t *b3 = new_boid(new_vecteur(150,0,100),10);

	//ajouts des boids au modéle
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	//création de prédateurs
	boid_t *p0 = new_boid(new_vecteur(15,620,0),100);
	boid_t *p1 = new_boid(new_vecteur(1,0,56.5),100);
	boid_t *p2 = new_boid(new_vecteur(1,10,56.5),100);
	boid_t *p3 = new_boid(new_vecteur(1,1000,56.5),100);

	//ajout des prédateurs
	ajout_pre(m,p0);
	ajout_pre(m,p1);
	ajout_pre(m,p2);
	ajout_pre(m,p3);

	//création de la nourriture
	vecteur_t *n0 = new_vecteur(10,25,15);
	vecteur_t *n1 = new_vecteur(250,25,15);
	vecteur_t *n2 = new_vecteur(2,25,15);

	//ajout de la nouriture
	ajout_food(m,n0);
	ajout_food(m,n1);
	ajout_food(m,n2);




	//tableau de prédateurs à proximité (b est censé voir p1 et p2)
	int nbPreProxAt = 2;

	//coordonnées de la nourriture visible la plus proche:
	vecteur_t *foodProx = n2;


	calcul_visibilite(m,0);

	//verif tableau de boids à proximité (b est censé voir b0 et b1)
	if(m->nbBoidProx == 2){
		if(!equals_boid(m->tabBoidProx[0],b0) || !equals_boid(m->tabBoidProx[1],b1)){
			ok = 0;
		}
	}else{
		ok = 0;
	}
	if(ok){
		printf("calcul intermediaire visibilité boid [OK]\n");
	}
	//verif tableau de prédateurs à proximité (b est censé voir p1 et p2)
	if(m->nbPreProx == 2){
		if(!equals_boid(m->tabPreProx[0],p1) || !equals_boid(m->tabPreProx[1],p2)){
			ok = 0;
		}
	}else{
		ok = 0;
	}
	if(ok){
		printf("calcul intermediaire visibilité pre [OK]\n");
	}
	if(!equals_vecteur(foodProx,m->foodProx)){
		ok = 0;
	}
	if(ok){
		printf("calcul_visibilite [OK]\n");
		return 1;
	}else{
		printf("calcul_visibilite [NOK]\n");
		return 0;
	}
}
int regle_regroupement_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);
	boid_t *b0 = new_boid(new_vecteur(30,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(0,0,30),10);
	boid_t *b2 = new_boid(new_vecteur(0,30,0),10);
	boid_t *b3 = new_boid(new_vecteur(150,0,100),10);

	//ajouts des boids au modéle
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	vecteur_t *etalon = new_vecteur(1,1,1);

	//traitement préalable 
	calcul_visibilite(m,0);
	if(!equals_vecteur(regle_regroupement(m,10),etalon)){
		ok = 0;
	}
	if(ok){
		printf("regle_regroupement [OK]\n");
		return 1;
	}else{
		printf("regle_regroupement [NOK]\n");
		return 0;
	}
}
int regle_evitemment_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(10,10,10),100);
	boid_t *b0 = new_boid(new_vecteur(12,10,10),10);
	boid_t *b1 = new_boid(new_vecteur(10,10,12),10);
	boid_t *b2 = new_boid(new_vecteur(10,12,10),10);
	boid_t *b3 = new_boid(new_vecteur(150,0,100),10);

	//ajouts des boids au modéle
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	//calculs prémiminaires
	calcul_visibilite(m,0);

	//regle evitement pour le boid 0 avec une distance minimale de 10
	if(!equals_vecteur(regle_evitement(m,0,10),new_vecteur(-2,-2,-2))){
		ok =0;
	}
	if(ok){
		printf("regle_evitement [OK]\n");
		return 1;
	}else{
		printf("regle_evitement [NOK]\n");
		return 0;
	}
}
int regle_harmonisation_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);
	boid_t *b0 = new_boid(new_vecteur(30,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(0,0,30),10);
	boid_t *b2 = new_boid(new_vecteur(0,30,0),10);
	boid_t *b3 = new_boid(new_vecteur(150,0,100),10);

	b->vit = new_vecteur(0,0,0);
	b0->vit = new_vecteur(30,0,0);
	b1->vit = new_vecteur(0,30,0);
	b2->vit = new_vecteur(0,0,-30);
	b3->vit = new_vecteur(2420,25,764);

	//ajouts des boids au modéle
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	vecteur_t *etalon = new_vecteur(1,1,-1);

	//traitement préalable 
	calcul_visibilite(m,0);
	if(!equals_vecteur(regle_harmonisation(m,10),etalon)){
		ok = 0;
	}
	if(ok){
		printf("regle_harmonisation [OK]\n");
		return 1;
	}else{
		printf("regle_harmonisation [NOK]\n");
		return 0;
	}
}
int regle_aTable_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);

	//ajouts des boids au modéle
	ajout_boid(m,b);

	//création de la nourriture
	vecteur_t *n0 = new_vecteur(0,0,50);
	vecteur_t *n1 = new_vecteur(250,25,15);
	vecteur_t *n2 = new_vecteur(52,25,15);

	//ajout de la nouriture
	ajout_food(m,n0);
	ajout_food(m,n1);
	ajout_food(m,n2);

	vecteur_t *etalon = new_vecteur(0,0,5);

	//traitement préalable 
	calcul_visibilite(m,0);
	if(!equals_vecteur(regle_aTable(m,10),etalon)){
		ok = 0;
	}
	if(ok){
		printf("regle_aTable [OK]\n");
		return 1;
	}else{
		printf("regle_aTable [NOK]\n");
		print_vecteur(regle_aTable(m,10));
		return 0;
	}
}
int regle_fuitePre_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);

	//ajouts des boids au modéle
	ajout_boid(m,b);

	//création de prédateurs
	boid_t *p0 = new_boid(new_vecteur(15,620,0),100);
	boid_t *p1 = new_boid(new_vecteur(0,0,25),1000);
	boid_t *p2 = new_boid(new_vecteur(1,10,56.5),100);
	boid_t *p3 = new_boid(new_vecteur(1,1000,56.5),100);

	//ajout des prédateurs
	ajout_pre(m,p0);
	ajout_pre(m,p1);
	ajout_pre(m,p2);
	ajout_pre(m,p3);

	vecteur_t *etalon = new_vecteur(0,0,-5);

	//traitement préalable 
	calcul_visibilite(m,0);
	if(!equals_vecteur(regle_fuitePre(m,0,5,50),etalon)){
		ok = 0;
	}
	if(ok){
		printf("regle_fuitePre [OK]\n");
		return 1;
	}else{
		printf("regle_fuitePre [NOK]\n");
		print_vecteur(regle_fuitePre(m,0,5,50));
		return 0;
	}

}
int calcul_deplacement_boids_test(){
	int ok = 1;

	//Mise en place de l'environnement:

	//création du modèle
	modele_t *m = new_modele(10,10,10);

	//création de boids
	boid_t *b = new_boid(new_vecteur(0,0,0),100);
	boid_t *b0 = new_boid(new_vecteur(15,0,0),10);
	boid_t *b1 = new_boid(new_vecteur(1,0,56.5),10);
	boid_t *b2 = new_boid(new_vecteur(10,250,0),10);
	boid_t *b3 = new_boid(new_vecteur(150,0,100),10);

	//ajouts des boids au modéle
	ajout_boid(m,b);
	ajout_boid(m,b0);
	ajout_boid(m,b1);
	ajout_boid(m,b2);
	ajout_boid(m,b3);

	//création de prédateurs
	boid_t *p0 = new_boid(new_vecteur(15,620,0),100);
	boid_t *p1 = new_boid(new_vecteur(1,0,56.5),100);
	boid_t *p2 = new_boid(new_vecteur(1,10,56.5),100);
	boid_t *p3 = new_boid(new_vecteur(1,1000,56.5),100);

	//ajout des prédateurs
	ajout_pre(m,p0);
	ajout_pre(m,p1);
	ajout_pre(m,p2);
	ajout_pre(m,p3);

	//création de la nourriture
	vecteur_t *n0 = new_vecteur(10,25,15);
	vecteur_t *n1 = new_vecteur(250,25,15);
	vecteur_t *n2 = new_vecteur(2,25,15);

	//ajout de la nouriture
	ajout_food(m,n0);
	ajout_food(m,n1);
	ajout_food(m,n2);


	calcul_deplacement_boids(m);
	

	//verif tableau de boids à proximité (b est censé voir b0 et b1)
	

	if(ok){
		printf("calcul_visibilite [OK]\n");
		return 1;
	}else{
		printf("calcul_visibilite [NOK]\n");
		return 0;
	}
}