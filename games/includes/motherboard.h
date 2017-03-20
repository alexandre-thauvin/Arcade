//
// Created by thauvi_a on 3/16/17.
//

#ifndef ARCADE_MOTHERBOARD_H
#define ARCADE_MOTHERBOARD_H

#include <vector>
#include <cstddef>
#include "tools.h"


#define WIDTH (60)

class 		motherboard{
 public:
  virtual void		pop() = 0;
  virtual void		move_player() = 0;
  enum 	move{
    STOP = 0,
    LEFT,
    RIGHT,
    TOP,
    DOWN
  };
 protected:
  move			mv;
  //move 			buff;
  int 			head_x;
  int 			head_y;
  int 			height;
  unsigned int		score;
  size_t                size;
  char 			**map;
  bool 			state;
};

#endif //ARCADE_MOTHERBOARD_H
