#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include <time.h>

int regle_1(int *a);
int init_modele(){
	
}
int calcul_deplacements(int *a){
	printf("calcul de a\n");
	regle_1(a);
	return *a;
}
int regle_1(int *a){
	//*a = *a +rand();
	*a += *a;
}
void regle_2(int *a){
	
}
