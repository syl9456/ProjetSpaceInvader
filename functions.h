#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "global.h"

void draw_player(const entity* player);

void draw_enemy(entity* enemy_fleet);

void draw_bullet(entity* bullets);

void move_player(entity* player);

void move_enemy(entity* enemy_fleet);

void shoot_player(entity* bullets, const entity* player);

int detect_collision(entity* bullet, entity* ship);

void move_bullet(entity* bullets);

entity* create(float width, float height, float x, float y, float dtx, float dty, int life, entity* next);

entity* add_entity_end(entity* head_ptr, float width, float height, float x, float y, float dtx, float dty, int life, entity* next);

entity* create(float width, float height, float x, float y, float dtx, float dty, int life, entity* next);

void delete_entity(entity* head_ptr);

entity* populate_fleet(int nbr_ship);

entity* populate_bullets(int nbr_bullet);

void shoot_enemy(entity* bullets, entity* fleet);

int detect_collision_global(entity* bullets, entity* fleet);

#endif
