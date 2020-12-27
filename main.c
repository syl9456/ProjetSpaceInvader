#include "functions.h"

int main( int argc, char *argv[] ){

  srand(time(NULL));
  entity* fleet = NULL;
  entity* bullets = NULL;
  int nbr_ship = 15;
  int nbr_bullet = 8;

  fleet = populate_fleet(nbr_ship);
  bullets = populate_bullets(nbr_bullet);

  int count = 0;
  entity* ptr = fleet;
  while(ptr != NULL){
    count ++;
    ptr=ptr->next;
  }
  printf("count %i\n",count);
  
  /* (window name, icone name, width, height) */
  MLV_create_window( "Space invader", "Space invader", WIDTH, HEIGHT);

  
  while(fleet->life > 0){

    MLV_clear_window(MLV_COLOR_BLACK);
    draw_player(fleet);
    move_player(fleet);
    shoot_player(bullets,fleet);
    draw_enemy(fleet->next);
    move_enemy(fleet->next);
    draw_bullet(bullets);
    shoot_enemy(bullets->next, fleet->next);
    move_bullet(bullets);
    detect_collision_global(bullets, fleet);
    MLV_update_window();
    MLV_delay_according_to_frame_rate();
    
  }
  
  delete_entity(fleet);
  delete_entity(bullets);
  


  /* ferme la fenetre MLV */
  MLV_free_window();
  exit(0);

}
