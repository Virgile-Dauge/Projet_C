#include <stdio.h>
#include <stdlib.h>
#include "modele.h"

int init_modele(){

}
int calcul_deplacements(int *a){     // mon commentaire
	printf("calcul de a\n");
	regle_1(a);
	return *a;
}
int regle_1(int *a){
	*a += *a;
}
void regle_2(int *a){
	
}
