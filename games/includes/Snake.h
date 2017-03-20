//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include "motherboard.h"


class Snake: public motherboard {
 public:
  Snake();
  ~Snake(){};
  void 		move_player();
  void 		pop();
  void 		check_death();
 private:
  size_t                size;
  bool 		frut;
  int 		frut_x;
  int 		frut_y;
};


#endif //ARCADE_SNAKE_H
