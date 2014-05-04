#ifndef MAIN_H
#define MAIN_H
#include "boid.h"
//prototypes
int init(int xPix, int yPix);
void dessiner(int a, int b, int c);
void dessiner_boid(boid_t *b);
int maj_affichage();
#endif