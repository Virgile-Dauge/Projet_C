#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
//compilation:
//gcc vecteurTest.c vecteur.c -o vecteurTest

//prototypes:
int new_vecteur_test();
int add_vecteur_test();
int add_multi_vecteurs_test();
int set_vecteur_test();

int main(int argc, char * argv){

	new_vecteur_test();
	equals_vecteur_test();
	add_vecteur_test();
	add_multi_vecteurs_test();
	set_vecteur_test();

}
int new_vecteur_test(){
	vecteur_t *v = new_vecteur(1,2,3);
	if(v->x ==1 && v->y ==2 && v->z ==3){
		printf("new_vecteur [OK]\n");
		return 1;
	}else{
		printf("new_vecteur [NOK]\n");
		return 0;
	}
}
int equals_vecteur_test(){

	vecteur_t *v0 = new_vecteur(1,2,3);
	vecteur_t *v1 = new_vecteur(4,58.5,3);
	vecteur_t *v2 = new_vecteur(4,58.5,3);
	if(!equals_vecteur(v0,v1) && equals_vecteur(v1,v2)){
		printf("equals_vecteur [OK]\n");
		return 1;
	}else{
		printf("equals_vecteur [NOK]\n");
		return 0;
	}
}
int add_vecteur_test(){
	//deux vecteur a additionner
	vecteur_t *v0 = new_vecteur(1,2,3);
	vecteur_t *v1 = new_vecteur(4,58.5,3);
	//vecteur attendu 
	vecteur_t *vecteurAttendu = new_vecteur(5,60.5,6);

	add_vecteur(v0,v1);

	if(equals_vecteur(v0,vecteurAttendu)){
		printf("add_vecteur [OK]\n");
		return 1;
	}else{
		printf("add_vecteur [NOK]\n");
		return 0;
	}
}
int add_multi_vecteurs_test(){
	//vecteur témoin
	vecteur_t *vecteurAttendu = new_vecteur(11,12,8);
	//calcul du vecteur
	vecteur_t *v = new_vecteur(1,2,3);
	vecteur_t *v0 = new_vecteur(0,2,1);
	vecteur_t *v1 = new_vecteur(1,2,1);
	vecteur_t *v2 = new_vecteur(2,2,1);
	vecteur_t *v3 = new_vecteur(3,2,1);
	vecteur_t *v4 = new_vecteur(4,2,1);
	vecteur_t *tab[5];
	tab[0]=v0;
	tab[1]=v1;
	tab[2]=v2;
	tab[3]=v3;
	tab[4]=v4;
	add_multi_vecteurs(v,tab,5);

	if(equals_vecteur(v,vecteurAttendu)){
		printf("add_multi_vecteur [OK]\n");
		return 1;
	}else{
		printf("add_multi_vecteur [NOK]\n");
		return 0;
	}
}
int set_vecteur_test(){
	//vecteur témoin
	vecteur_t *vecteurAttendu = new_vecteur(4.65,68.4,98);

	vecteur_t *v = new_vecteur(1,2,3);
	set_vecteur(v,4.65,68.4,98);
	
	if(equals_vecteur(v,vecteurAttendu)){
		printf("set_vecteur [OK]\n");
		return 1;
	}else{
		printf("set_vecteur [NOK]\n");
		return 0;
	}
}



