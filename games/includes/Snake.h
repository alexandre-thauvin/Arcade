//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../../src/core/include/IGame.hpp"

#define HEAD	(1)
#define FRUT	(-299)
// Le body sera représenté par une incrementation d'une variable => 2ème boule du snake =>2 etc...


class Snake: public  arcade::IGames {
 public:
  Snake(arcade::Vector2u const);
  ~Snake(){};

  std::list<arcade::Vector2u> const& 	getPlayerPosition(void);
  arcade::Vector2u        		getDimension(void) const;
  std::string     			getGamesName(void) const;
  size_t        			getScore(void) const;
  int					**ma2d();
  int 					*find_tale(int, int **);
  bool 					eat_frut();
  bool 					isPlayerAlive();
  bool            			isPlayerWin(void) const;
  bool            			updateGame(float const tick);
  void 					init();
  void 					move_player();
  void 					goDown();
  void 					goUp();
  void 					goLeft();
  void 					goRight();
  void 					pop();
  void 					update_key(arcade::Input);
  void 					play();
  void 					grow_up();
  void 					move_body();
  void            			restart(void);
  void 					print_map();
 private:
  std::list<arcade::Vector2u>	snake;
  arcade::Vector2u		dim;
  arcade::Input			mv;
  std::string			name;
  size_t       			size;
  bool 				state;
  bool 				frut;
  int 				**map;
  int 				frut_x;
  int 				frut_y;
  int 				*tale;
  unsigned int 			head_x;
  unsigned int 			head_y;
  unsigned int			score;
};


#endif //ARCADE_SNAKE_H
