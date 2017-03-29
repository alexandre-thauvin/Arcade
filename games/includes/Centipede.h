//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_CENTIPEDE_H
#define ARCADE_CENTIPEDE_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "IGame.hpp"

#define HEAD	(1)


class Centipede : public arcade::IGames{
 public:
  Centipede();
  ~Centipede(){};
  enum 	move{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  void 		move_player();
  void 		goDown();
  void 		goUp();
  void 		goLeft();
  void 		goRight();
  void 		pop();
  void 		update_key(move);
  void 		play();
  void 		gestion();
  void 		print_map();
  size_t        getScore(void) const;
  bool 		isPlayerAlive();
  std::string     getGamesName(void) const;
  void            restart(void);
  bool            isPlayerWin(void) const;
  void		move_ia();

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
};


#endif //ARCADE_CENTIPEDE_H
