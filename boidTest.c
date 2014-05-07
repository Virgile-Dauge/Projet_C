#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "boid.h"

//gcc boidTest.c boid.c vecteur.c -o boidTest -Wall -Wextra -Wunreachable-code -Wwrite-strings -lm
int new_boid_test();
int equals_boid_test();
int set_boid_pos_test();
int get_boid_pos_test();
int add_boid_pos_test();
int distance_boid_test();
int boid_can_see_test();

int main(int argc, char ** argv){
	new_boid_test();
	equals_boid_test();
	set_boid_pos_test();
	get_boid_pos_test();
	add_boid_pos_test();
	distance_boid_test();
	boid_can_see_test();
}
int new_boid_test(){
	vecteur_t *v = new_vecteur(1,2,3);
	vecteur_t *vitAttendu = new_vecteur(0,0,0);
	boid_t *b = new_boid(new_vecteur(1,2,3),10);
	if(equals_vecteur(b->pos,v) && equals_vecteur(b->vit,vitAttendu) && b->distanceVue == 10){
		printf("new_boid [OK]\n");
		return 1;
	}else{
		printf("new_boid [NOK]\n");
		return 0;
	}
}
int equals_boid_test(){
	boid_t *b0 = new_boid(new_vecteur(1,2,3),10);
	boid_t *b1 = new_boid(new_vecteur(1,2,3),10);
	boid_t *b2 = new_boid(new_vecteur(1,2,2),10);
	if(equals_boid(b0,b1) && !equals_boid(b0,b2)){
		printf("equals_boid [OK]\n");
		return 1;
	}else{
		printf("equals_boid [NOK]\n");
		return 0;
	}
}
int set_boid_pos_test(){
	boid_t *b = new_boid(new_vecteur(1,2,3),10);
	vecteur_t *posAttendu = new_vecteur(-5,5,24.5);
	set_boid_pos(b,posAttendu);
	if(equals_vecteur(b->pos,posAttendu)){
		printf("set_boid_pos [OK]\n");
		return 1;
	}else{
		printf("set_boid_pos [NOK]\n");
		return 0;
	}
}
int get_boid_pos_test(){
	boid_t *b = new_boid(new_vecteur(1,2,3),10);
	vecteur_t *posAttendu = new_vecteur(1,2,3);
	if(equals_vecteur(get_boid_pos(b),posAttendu)){
		printf("get_boid_pos [OK]\n");
		return 1;
	}else{
		printf("get_boid_pos [NOK]\n");
		return 0;
	}
}
int add_boid_pos_test(){
	boid_t *b = new_boid(new_vecteur(1,2,3),10);
	vecteur_t *v= new_vecteur(1,-5,3);
	vecteur_t *posAttendu = new_vecteur(2,-3,6);
	add_boid_pos(b,v);
	if(equals_vecteur(get_boid_pos(b),posAttendu)){
		printf("add_boid_pos [OK]\n");
		return 1;
	}else{
		printf("add_boid_pos [NOK]\n");
		return 0;
	}

}
int distance_boid_test(){
	boid_t *b = new_boid(new_vecteur(-10,0,0),10);
	vecteur_t *v0= new_vecteur(10,0,0);
	vecteur_t *v1= new_vecteur(10,452.5,-58);
	vecteur_t *v2= new_vecteur(0,0,0);
	if(distance_boid(b,v0)==20 && distance_boid(b,v2) == 10 && distance_boid(b,v1)>456.6 && distance_boid(b,v1)< 456.7){
		printf("distance_boid [OK]\n");
		return 1;
	}else{
		printf("distance_boid [NOK]\n");
		printf("[Attendu]distance_boid(b,v0)= 20\n");
		printf("[Obtenu]distance_boid(b,v0)=%f\n",distance_boid(b,v0));
		printf("[Attendu]distance_boid(b,v1)= 456.6.....\n");
		printf("[Obtenu]distance_boid(b,v1)=%f\n",distance_boid(b,v1));
		printf("[Attendu]distance_boid(b,v2)= 0\n");
		printf("[Obtenu]distance_boid(b,v2)=%f\n",distance_boid(b,v2));
		return 0;
	}
}
int boid_can_see_test(){
	boid_t *b0 = new_boid(new_vecteur(100,100,100),10);
	boid_t *b1 = new_boid(new_vecteur(1,2,3),1000);
	boid_t *b2 = new_boid(new_vecteur(1,2,2),10);
	if(!boid_can_see(b0,b1->pos) && boid_can_see(b1,b0->pos) && boid_can_see(b1,b2->pos) && boid_can_see(b2,b1->pos)){
		printf("boid_can_see [OK]\n");
		return 1;
	}else{
		printf("boid_can_see [NOK]\n");
		return 0;
	}

}