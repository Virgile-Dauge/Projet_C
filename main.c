#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include "interface.h"


int main(int argc, char * argv){
	int a=1;
	printf("%d\n", a);
	calcul_deplacements(&a);
	printf("%d\n", a);
}


