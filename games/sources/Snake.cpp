//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include <ctime>
#include "Snake.h"

void Snake::move_player() {

}

Snake::Snake() {
  this->mv = STOP;
  this->map = ma2d(this->map);
  this->frut = true;
  srand(time(NULL));
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->head_x = WIDTH / 2;
  this->head_y = WIDTH / 2;
  this->score = 0;
  this->state = true;
  this->size = 4;
}

void Snake::pop() {
  if (this->frut)
    return;
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->frut = true;
}

bool Snake::check_death() {
  if (this->mv == RIGHT)
    if (this->map[this->head_y][this->head_x + 1] == 's' || this->head_x == WIDTH - 1)
      this->state = false;
  else if (this->mv == LEFT)
    if (this->map[this->head_y][this->head_x - 1] == 's' || this->head_x == 0)
      this->state = false;
  else if (this->mv == TOP)
    if (this->map[this->head_y - 1][this->head_x] == 's' || this->head_y == 0)
      this->state = false;
  else if (this->mv == DOWN)
    if (this->map[this->head_y + 1][this->head_x] == 's' || this->head_y == WIDTH - 1)
      this->state = false;
}

void Snake::update_key(move mv) {
  this->mv = mv;
}

void Snake::s_fill_map() {
  int i;
  int z;
  for (i = 0; i < WIDTH - 1 ; i++)
    for(z = 0; z < WIDTH - 1 ; z++)
      this->map[i][z] = '*';
  this->map[this->head_y][this->head_x] = 'h';
  this->map[this->head_y][this->head_x - 1] = 's';
  this->map[this->head_y][this->head_x - 2] = 's';
  this->map[this->head_y][this->head_x - 3] = 's';
}

void 	start_s(){

}
