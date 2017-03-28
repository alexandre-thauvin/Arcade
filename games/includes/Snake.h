//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "motherboard.h"

#define HEAD	(1)
#define FRUT	(-299)
// Le body sera représenté par une incrementation d'une variable => 2ème boule du snake =>2 etc...


class Snake: public motherboard {
 public:
  Snake();
  ~Snake(){};
  void 		move_player();
  void 		move_down();
  void 		move_up();
  void 		move_left();
  void 		move_right();
  void 		pop();
  bool 		check_death();
  bool 		eat_frut();
  void 		update_key(move);
  void 		s_fill_map();
  void 		gestion();
  void 		grow_up();
  void 		move_body();
  void 		print_map();
 private:
  int 		map[WIDTH][WIDTH];
  size_t       	size;
  bool 		frut;
  move 		g_move;
  int 		frut_x;
  int 		frut_y;
  int 		*tale;
};


#endif //ARCADE_SNAKE_H
