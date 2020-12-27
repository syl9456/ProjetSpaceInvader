#include "global.h"

/* Ces fonctions ont pour but de gérer la représentation et la gestion des données de notre jeu, Nous utilisons ici le modèle de liste chainées CF google pour plus d'informations.*/

/*Crée une nouvelle entité, et fixe ces paramètres, n'est pas utilisée telle quelle mais dans add_entity_end*/

entity* create(float width, float height, float x, float y, float dtx, float dty, int life, entity* next){
  
  entity* new_entity = (entity*)malloc(sizeof(entity));
  
  if(new_entity == NULL){
    fprintf(stderr,"Erreur lors de la creation d'une entite !\n");
    exit(0);
  }
  
  new_entity->x = x;
  new_entity->y = y;
  new_entity->dtx = dtx;
  new_entity->dty = dty;
  new_entity->width = width;
  new_entity->height = height;
  new_entity->life = life;
  new_entity->next = next;
  return new_entity;
}



/* appelle create pour créer une nouvelle node et l'ajoute à la fin de notre liste, l'ajout est fait a la fin car même si plus lent qu'au début la lecture du code concernant le placement des entités en matière de coordonner en est facilité, cela permet aussi une representation ou le joueur reste en premier dans la liste. */

entity* add_entity_end(entity* head_ptr, float width, float height, float x, float y, float dtx, float dty, int life, entity* next){
  
  entity* new_entity = create(width, height, x, y, dtx, dty, life, next);
  
  entity* cursor = head_ptr;
  if(head_ptr == NULL){
    head_ptr = new_entity;
    return head_ptr;
  }
  while(cursor->next != NULL){
    cursor = cursor->next;
  }
  cursor->next = new_entity;
  return head_ptr;
}


/* libère la mémoire utiliser par notre liste chainée */
void delete_entity(entity* head_ptr){
  entity* ptr = head_ptr->next;
  while(ptr != NULL){
    free(head_ptr);
    head_ptr = ptr;
    ptr = ptr->next;
  }
  free(head_ptr);
}




/*le gros de la représentation est fait ici, crée une liste chaine des vaisseaux, le premier vaisseau de la liste sera le joueur et le reste les ennemies, nous allons faire de même pour les balles, une seule liste avec la première balle étant celle du joueur et les autres celles des ennemis.
Cela nous permet de gagner du temps en utilisant notre fonction de détection de collision entre la première balle de la liste (celle du joueur) et tous les vaisseaux de la liste(ennemis) sauf le premier et finalement toutes les balles de la liste(balles des ennemis) sauf la première avec le premier vaisseau de la liste (joueur)*/


entity* populate_fleet(int nbr_ship){
  entity* head_ptr = NULL;

  head_ptr = add_entity_end(head_ptr, WIDTH_PLAYER, HEIGHT_PLAYER, WIDTH / 2 - WIDTH_PLAYER / 2, HEIGHT - HEIGHT_PLAYER * 2, 0, 0, 3, NULL);

  nbr_ship --;
  
  /*pour placer les enemis (a revoir)*/
  int placement = WIDTH_ENEMY;
  int etage = 0;
  while(nbr_ship != 0){
		       
    if (nbr_ship%7 == 0) {
      placement = WIDTH_ENEMY;
      etage += 75;
    }
      
    head_ptr = add_entity_end(head_ptr, WIDTH_ENEMY, HEIGHT_ENEMY, placement, etage, 1, 1, 3, NULL);
    nbr_ship --;
    placement += 100;
  }

  return head_ptr;
}



/* Au maximum autant de balles que d'ennemis a l'ecran */
entity* populate_bullets(int nbr_bullet){
  entity* head_ptr = NULL;
  while(nbr_bullet != 0){
    head_ptr = add_entity_end(head_ptr, WIDTH_BULLET, HEIGHT_BULLET, 0, 0, 0, 0, 0, NULL);
    nbr_bullet --;
  }

  return head_ptr;
}
