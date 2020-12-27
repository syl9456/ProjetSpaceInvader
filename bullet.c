#include "global.h"

/* une balle va avoir 1 ou 0 point de vie, si elle entre en collision avec le joueur ou un enemmi son total de vie passe à 0 et elle n'est plus dessinée ! */
void draw_bullet(entity* bullets){
  entity* cursor = bullets;
  while(cursor != NULL){
    if(cursor->life == 1){
      MLV_draw_rectangle(cursor->x, cursor->y, cursor->width, cursor->height, MLV_COLOR_WHITE);
    }
    cursor = cursor->next;
  }
}

/* utiliser pour détecter une collision entre deux rectangles, ici la balle et une entité, CF collision aabb sur google pour plus d'informations. */
int detect_collision(entity* bullet, entity* ship){
  /* lance la fonction que si le vaisseau est en jeu*/
  if(ship->life > 0){
    if((bullet->x + bullet->width) < ship->x || bullet->x > (ship->x + ship->width)){
      return 0;
    }
    if(bullet->y > (ship->y + ship->height) || (bullet->y + bullet->height) < ship->y){
      return 0;
    }
    return 1;
  }
  return 0;
}

int detect_collision_global(entity* bullets, entity* fleet){
  /* teste la premiere balle (celle du joueur) sur tout les enemmis a partir du deuxieme*/
  entity* cursor_bullets = bullets;
  entity* cursor_fleet = fleet->next;
  while(cursor_fleet != NULL){
    if(detect_collision(cursor_bullets, cursor_fleet)){
      cursor_fleet->life --;
      cursor_bullets->x = -100;
      cursor_bullets->y = -100;
      cursor_bullets->life = 0;
      cursor_bullets->dty = 0;
    }
    cursor_fleet = cursor_fleet->next;
  }
  /* teste toutes les autres balles sur le premier vaisseau (celui du joueur) */
  cursor_bullets = cursor_bullets->next;
  cursor_fleet = fleet;
  while(cursor_bullets != NULL){
    if(detect_collision(cursor_bullets, cursor_fleet)){
      cursor_fleet->life --;
      cursor_bullets->x = -100;
      cursor_bullets->y = -100;
      cursor_bullets->life = 0;
      cursor_bullets->dty = 0;
    }
    cursor_bullets = cursor_bullets->next;
  }
}

/* Même fonctionnement que pour move_player */
void move_bullet(entity* bullets){
  entity* cursor = bullets;
  while(cursor != NULL){
    if(cursor->life != 0){
      cursor->y += (cursor->dty * SPEED_BULLET) / MLV_get_frame_rate();
      if(cursor->y < 0 || cursor->y > HEIGHT){
	cursor->life = 0;
	cursor->dty = 0;
      }
    }
    cursor = cursor->next;
  }
}


