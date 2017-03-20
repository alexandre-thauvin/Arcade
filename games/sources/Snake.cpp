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
  this->frut_x = rand() % WIDTH + 1;
  this->frut_y = rand() % WIDTH + 1;
  this->head_x = -1;
  this->head_y = -1;
  this->score = 0;
  this->state = false;
  this->size = 3;
}

void Snake::pop() {
  if (this->frut)
    return;
  this->frut_x = rand() % WIDTH + 1;
  this->frut_y = rand() % WIDTH + 1;
  this->frut = true;
}

void Snake::check_death() {

}
