//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include <ctime>
#include "Snake.h"

void Snake::move_player() {
  if (this->mv == RIGHT)
    move_right();
  else if (this->mv == LEFT)
    move_left();
  else if (this->mv == UP)
    move_up();
  else if (this->mv == DOWN)
    move_down();
}

Snake::Snake() {
  this->mv = STOP;
  //this->map = ma2d(this->map);
  this->frut = true;
  srand(time(NULL));
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->head_x = WIDTH / 2;
  this->head_y = WIDTH / 2;
  this->score = 0;
  this->state = true;
  this->size = 2;
}

void Snake::pop() {
  if (this->frut)
    return;
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->map[this->frut_y][this->frut_x] = FRUT;
  this->frut = true;
}

bool Snake::check_death() {
  if (this->mv == RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] > 1 || this->head_x == WIDTH - 1)
      this->state = false;
  }
    else if (this->mv == LEFT) {
    if (this->map[this->head_y][this->head_x - 1] > 1 || this->head_x == 0)
      this->state = false;
  }
  else if (this->mv == UP) {
    if (this->map[this->head_y - 1][this->head_x] > 1 || this->head_y == 0)
      this->state = false;
  }
  else if (this->mv == DOWN) {
    if (this->map[this->head_y + 1][this->head_x] > 1 || this->head_y == WIDTH - 1)
      this->state = false;
  }
}

void Snake::update_key(move mv) {
  this->mv = mv;
}

void Snake::s_fill_map() {
  int i;
  int z;
  for (i = 0; i < WIDTH - 1; i++)
    for (z = 0; z < WIDTH - 1; z++)
      this->map[i][z] = '*';
  this->map[this->head_y][this->head_x] = HEAD;
  for (i = 1; i < 4; i++) {
    this->map[this->head_y][this->head_x - i] = (int)this->size;
    this->size++;
  }
}
void 	Snake::gestion(){
  Snake		*Snake = new Snake();

  Snake->s_fill_map();
  Snake->update_key(RIGHT);
  if (!Snake->check_death());
}

bool Snake::eat_frut() {
  if (this->mv == RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] == FRUT || this->head_x == WIDTH - 1)
      this->state = true;
  }
  else if (this->mv == LEFT) {
    if (this->map[this->head_y][this->head_x - 1] == FRUT || this->head_x == 0)
      this->state = true;
  }
  else if (this->mv == UP) {
    if (this->map[this->head_y - 1][this->head_x] == FRUT || this->head_y == 0)
      this->state = true;
  }
  else if (this->mv == DOWN) {
    if (this->map[this->head_y + 1][this->head_x] == FRUT || this->head_y == WIDTH - 1)
      this->state = true;
  }
  if (this->state) {
    this->score += 100;
    return (true);
  }
  return false;
}

void Snake::move_down() {

}

void Snake::move_up() {

}

void Snake::move_left() {

}

void Snake::move_right() {

}
