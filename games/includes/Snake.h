//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "IGame.hpp"
#include "tools.h"

#define HEAD	(1)
#define FRUT	(-299)
// Le body sera représenté par une incrementation d'une variable => 2ème boule du snake =>2 etc...


class Snake: public  arcade::IGames {
 public:
  Snake(arcade::Vector2u const);
  ~Snake(){};
  enum 	move{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  arcade::Vector2u        getDimension(void) const;
  void 		move_player();
  void 		goDown();
  void 		goUp();
  void 		goLeft();
  void 		goRight();
  void 		pop();
  bool 		eat_frut();
  void 		update_key(move);
  void 		play();
  void 		gestion();
  void 		grow_up();
  void 		move_body();
  void 		print_map();
  size_t        getScore(void) const;
  bool 		isPlayerAlive();
  std::string     getGamesName(void) const;
  void            restart(void);
  bool            isPlayerWin(void) const;
 private:
  std::string	name;
  int 		**map;
  size_t       	size;
  bool 		frut;
  int 		frut_x;
  int 		frut_y;
  int 		*tale;
  move			mv;
  int 			head_x;
  int 			head_y;
  unsigned int		score;
  bool 			state;
  arcade::Vector2u	dim;
};


#endif //ARCADE_SNAKE_H
