//
// Created by thauvi_a on 3/16/17.
//

#ifndef ARCADE_MOTHERBOARD_H
#define ARCADE_MOTHERBOARD_H

#include <vector>

class 		motherboard{
 public:
  int 	getHeight();
  move	getMove();
  void	start();
  enum 	move{
    STOP = 0,
    LEFT,
    RIGHT,
    TOP,
    DOWN
  };
 private:
  move			mv;
  int 			height;
  int 			f_x;
  int 			f_y;
  std::vector<int>	body;
  int 			**map;
  bool 			status;
  bool 			frut;&
};

#endif //ARCADE_MOTHERBOARD_H
