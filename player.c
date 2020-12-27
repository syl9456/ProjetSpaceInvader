#include "global.h"

void move_player(entity* player){
  /* Si dtx est positif le joueur va vers la droite, vers la gauche si négative et ne bouge pas si nul */
  if(MLV_get_keyboard_state(MLV_KEYBOARD_d) == MLV_PRESSED){
    player->dtx = 1;
  }
  else if(MLV_get_keyboard_state(MLV_KEYBOARD_q) == MLV_PRESSED){
    player->dtx = -1;
  }
  else{
    player->dtx = 0;
  }

  /* Le déplacement se fait ici, on divise par le frame rate pour avoir un déplacement homogène */
  player->x += (player->dtx * SPEED) / MLV_get_frame_rate();

  /* Pour que le joueur ne dépasse pas le cadre de la fenêtre quand il se déplace */ 
  if(player->x < 0){
    player->x = 0;
  }
  else if(player->x > WIDTH - player->width){
    player->x = WIDTH - player->width;
  }
}

void draw_player(const entity* player){
  if(player->life == 3){
    MLV_draw_rectangle(player->x, player->y, player->width, player->height, MLV_COLOR_GREEN);
  }
  else if(player->life == 2){
    MLV_draw_rectangle(player->x, player->y, player->width, player->height, MLV_COLOR_YELLOW);
  }
  else if(player->life == 1){
    MLV_draw_rectangle(player->x, player->y, player->width, player->height, MLV_COLOR_RED);
  }
}

void shoot_player(entity* bullets, const entity* player){
  /* le joueur ne peut tirer  que si la balle qu'il a tirée précédemment et atteint ça cible ou a touché un de bord de la fenêtre */
  if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED && bullets->life == 0){
  bullets->x = player->x + (player->width / 2) - (bullets->width / 2);
  bullets->y = player->y - bullets->height;
  bullets->life = 1;
  bullets->dty = -1;
  }
}
