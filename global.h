/* Evite la double inclusion pour plus d'info : https://fr.wikipedia.org/wiki/Include_guard */
#ifndef GLOBAL_H_
#define GLOBAL_H_

/*fonctions qui doivent être accessible dans tout le programme*/
#include<stdio.h>
#include<stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>

/*Ce sont les variables globales qui vont être utilisées dans le programme*/
#define WIDTH 750
#define HEIGHT 750
#define SPEED 100
#define SPEED_BULLET 600
#define WIDTH_PLAYER 30
#define HEIGHT_PLAYER 20
#define WIDTH_ENEMY 40
#define HEIGHT_ENEMY 40
#define WIDTH_BULLET 5
#define HEIGHT_BULLET 10

/*L'idée ici est que le vaisseau du joueur, ceux de l'ennemi et les balles peuvent être représentés de la même façon, seuls leurs comportements changent ce qui est défini dans les fonctions.*/
typedef struct entity{
  float x, y, width, height, dtx, dty;
  int life;
  struct entity* next;
}entity;

#endif
