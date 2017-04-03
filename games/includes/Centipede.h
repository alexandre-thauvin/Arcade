//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_CENTIPEDE_H
#define ARCADE_CENTIPEDE_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../../src/core/include/IGame.hpp"

#define BODY	(-2)
#define HEAD	(-1)
#define CHAMP	(4)
#define TOWER	(100)
#define SPIDER	(-10)

class Centipede : public arcade::IGames{
 public:
  Centipede(arcade::Vector2u);
  ~Centipede(){};
  arcade::Vector2u & 			getTowerPosition(void);
  std::list<arcade::Vector2u>			getCentiPosition(void);
  std::list<arcade::Vector2u>			getChampPosition(void);
  arcade::Vector2u			getObjectPosition(void);
  arcade::Vector2u        		getDimension(void) const;
  std::string     			getGamesName(void) const;
  size_t        			getScore(void) const;
  bool 					isPlayerAlive();
  bool            			isPlayerWin(void) const;
  bool            			updateGame(float const tick);
  void 					init();
  bool 					move_player();
  bool 					move_ia();
  void 					init_champ();
  void 					init_centi();
  void 					move_body_cent();
  void 					goDown();
  void 					goUp();
  void 					goLeft();
  void 					goRight();
  void 					pop();
  void 					update_key(arcade::Input);
  void 					play();
  void 					split();
  void            			restart(void);
  void 					shoot();
  void 					find_tower();
 private:
  std::list<arcade::Vector2u>		Centi;
  std::list<arcade::Vector2u>		Champ;
  arcade::Vector2u			tower;
  arcade::Vector2u			dim;
  arcade::Vector2u			spider;
  arcade::Input				mv;
  std::string				name;
  unsigned int				score;
  unsigned int				nb_centi;
  int 					**map;
  bool 					state;
};


#endif //ARCADE_CENTIPEDE_H
