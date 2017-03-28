//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_CENTIPEDE_H
#define ARCADE_CENTIPEDE_H


#include "motherboard.h"

class Centipede : public motherboard{
  Centipede();
  ~Centipede(){};
  void		move_ia();
  void 		move_player();

};


#endif //ARCADE_CENTIPEDE_H
