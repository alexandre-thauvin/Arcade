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
  bool 		check_death();
  void 		update_key(move);
  void 		s_fill_map();
 private:
  size_t       	size;
  bool 		frut;
  int 		frut_x;
  int 		frut_y;
};


#endif //ARCADE_SNAKE_H
