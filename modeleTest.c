#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "boid.h"
#include "vecteur.h"

//gcc modeleTest.c modele.c boid.c vecteur.c -o modeleTest -Wall -Wextra -Wunreachable-code -Wwrite-strings
int new_modele_test();
int ajout_boid_test();
int main(int argc, char** argv){
	new_modele_test();
}
int new_modele_test(){
	modele_t *m = new_modele(100,10);
	if(m->maxBoid == 100 && m->maxPre == 10){
		printf("new_modele [OK]\n");
		return 1;
	}else{
		printf("new_modele [NOK]\n");
		return 0;
	}
}
int ajout_boid_test(){
	modele_t *m = new_modele(100,10);
	boid_t *b = new_boid(new_vecteur(0,0,0));
	ajout_boid(m,b);
	if(equals_boid(b,m->tabBoid[0])){
		printf("ajout_boid [OK]\n");
		return 1;
	}else{
		printf("ajout_boid [NOK]\n");
		return 0;
	}
}