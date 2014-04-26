#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vecteur.h"
//compilation:
//gcc vecteurTest.c vecteur.c -o vecteurTest

//prototypes:
int new_vecteur_test();
int add_vecteur_test();
int add_multi_vecteurs_test();
int set_vecteur_test();
int copy_vecteur_test();
int toString_vecteur_test();

int main(int argc, char * argv){

	new_vecteur_test();
	equals_vecteur_test();
	add_vecteur_test();
	add_multi_vecteurs_test();
	set_vecteur_test();
	copy_vecteur_test();
	toString_vecteur_test();
}
int new_vecteur_test(){
	vecteur_t *pos = new_vecteur(1,2,3);
	if(pos->x ==1 && pos->y ==2 && pos->z ==3){
		printf("new_vecteur [OK]\n");
		return 1;
	}else{
		printf("new_vecteur [NOK]\n");
		return 0;
	}
}
int equals_vecteur_test(){

	vecteur_t *pos0 = new_vecteur(1,2,3);
	vecteur_t *pos1 = new_vecteur(4,58.5,3);
	vecteur_t *pos2 = new_vecteur(4,58.5,3);

	if(!equals_vecteur(pos0,pos1) && equals_vecteur(pos1,pos2)){
		printf("equals_vecteur [OK]\n");
		return 1;
	}else{
		printf("equals_vecteur [NOK]\n");
		return 0;
	}
}
int add_vecteur_test(){
	//deux vecteur a additionner
	vecteur_t *pos0 = new_vecteur(1,2,3);
	vecteur_t *pos1 = new_vecteur(4,58.5,3);
	//vecteur attendu 
	vecteur_t *vecteurAttendu = new_vecteur(5,60.5,6);

	add_vecteur(pos0,pos1);

	if(equals_vecteur(pos0,vecteurAttendu)){
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
	vecteur_t *pos = new_vecteur(1,2,3);
	vecteur_t *pos0 = new_vecteur(0,2,1);
	vecteur_t *pos1 = new_vecteur(1,2,1);
	vecteur_t *pos2 = new_vecteur(2,2,1);
	vecteur_t *pos3 = new_vecteur(3,2,1);
	vecteur_t *pos4 = new_vecteur(4,2,1);
	vecteur_t *tab[5];
	tab[0]=pos0;
	tab[1]=pos1;
	tab[2]=pos2;
	tab[3]=pos3;
	tab[4]=pos4;
	add_multi_vecteurs(pos,tab,5);

	if(equals_vecteur(pos,vecteurAttendu)){
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

	vecteur_t *pos = new_vecteur(1,2,3);
	set_vecteur(pos,4.65,68.4,98);

	if(equals_vecteur(pos,vecteurAttendu)){
		printf("set_vecteur [OK]\n");
		return 1;
	}else{
		printf("set_vecteur [NOK]\n");
		return 0;
	}
}
int copy_vecteur_test(){
	//vecteur témoin
	vecteur_t *vecteurAttendu = new_vecteur(4.65,68.4,98);

	vecteur_t *pos = new_vecteur(1,2,3);
	vecteur_t *source = new_vecteur(4.65,68.4,98);

	copy_vecteur(pos,source);

	if(equals_vecteur(pos,vecteurAttendu)){
		printf("copy_vecteur [OK]\n");
		return 1;
	}else{
		printf("copy_vecteur [NOK]\n");
		printf("%s",toString_vecteur(pos));
		printf("%s",toString_vecteur(vecteurAttendu));
		return 0;
	}
}
int toString_vecteur_test(){
	//chaine Attendue
	char *chaineAttendue = "(1.000000,2.000000,3.000000)\n";
	char *chaineObtenue;
	vecteur_t *pos = new_vecteur(1,2,3);
	chaineObtenue =toString_vecteur(pos);
	
	if(strcmp(chaineAttendue,chaineObtenue)==0){
		printf("toString_vecteur [OK]\n");
		return 1;
	}else{
		printf("toString_vecteur [NOK]\n");
		printf("%s",chaineObtenue);
		printf("%s",chaineAttendue);
		return 0;
	}
}



