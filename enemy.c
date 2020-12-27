#include "global.h"




/* Ici la couleur de l'ennemi change en fonction de la vie qu'il lui reste */
void draw_enemy(entity* enemy_fleet){
  entity* cursor = enemy_fleet;
  while(cursor != NULL){
  if(cursor->life == 3){
    MLV_draw_rectangle(cursor->x, cursor->y, cursor->width, cursor->height,  MLV_COLOR_GREEN);
  }
  else if(cursor->life == 2){
    MLV_draw_rectangle(cursor->x, cursor->y, cursor->width, cursor->height,  MLV_COLOR_YELLOW);
  }
  else if(cursor->life == 1){
    MLV_draw_rectangle(cursor->x, cursor->y, cursor->width, cursor->height,  MLV_COLOR_RED);
  }
  
  cursor = cursor->next;
  
  }
}






/* Même fonctionnement que pour move_player a completer*/
void move_enemy(entity* enemy_fleet){
  entity* cursor = enemy_fleet;
  entity* cursor_reset = enemy_fleet;
  
  while(cursor != NULL){

    if(cursor->life != 0){
      cursor->x += (cursor->dtx * SPEED) / MLV_get_frame_rate();
    }

    if(cursor->life != 0){
      cursor->y += (cursor->dty * 12) / MLV_get_frame_rate();
    }

    
    /* si un vaisseau touche un des bords de la fenêtre change la direction de tous les autres vaisseau */
    if((cursor->x < 0) || (cursor->x > WIDTH - cursor->width)){

      while(cursor_reset != NULL){
	if(cursor_reset->life != 0){
	  cursor_reset->dtx *= -1;
	}
	cursor_reset = cursor_reset->next;
      }
    }

    if((cursor->y > WIDTH - cursor->width - 75)){
      MLV_free_window();
      exit(0);
    }
    
    cursor = cursor->next;  
  }
}






/* explication via vocal si besoin */
void shoot_enemy(entity* bullets, entity* fleet){
  entity* cursor_fleet = fleet;
  entity* cursor_bullets = bullets;

  while(cursor_fleet != NULL && cursor_bullets != NULL){
    if(cursor_bullets->dty == 0 && cursor_bullets->life == 0 && cursor_fleet->life > 0){
      if(rand() % 100 == 1){
	cursor_bullets->dty = 1;
	cursor_bullets->x = cursor_fleet->x + (cursor_fleet->width / 2);
	cursor_bullets->y = cursor_fleet->y + (cursor_fleet->height);
	cursor_bullets->life = 1;
      }
    }
      cursor_fleet = cursor_fleet->next;
      cursor_bullets = cursor_bullets->next;
  }
}

