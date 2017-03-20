//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.h"

void Snake::move_player() {

}

Snake::Snake() {
  this->mv = STOP;
  this->height = 3;
  this->map = ma2d(this->map);
}
