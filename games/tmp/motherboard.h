//
// Created by thauvi_a on 3/16/17.
//

#ifndef ARCADE_MOTHERBOARD_H
#define ARCADE_MOTHERBOARD_H

#include <vector>
#include <cstddef>
#include "tools.h"


#define WIDTH (10)

class 		motherboard{
 public:
  motherboard(){};

  virtual void		pop() = 0;
  virtual void		move_player() = 0;
  virtual void 		update_key(move) = 0; //fonction a appelé en passant un enum en fonction de la key recup
 //protected:
};

#endif //ARCADE_MOTHERBOARD_H
