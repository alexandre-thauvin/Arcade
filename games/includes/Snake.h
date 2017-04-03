//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "IGame.hpp"

#define HEAD	(1)
#define FRUT	(-299)
// Le body sera représenté par une incrementation d'une variable => 2ème boule du snake =>2 etc...


class Snake : public  IGames {
 public:
  Snake(arcade::Vector2u const);
    virtual ~Snake(){};

    virtual std::string     			    getGamesName(void) const;
    virtual void            			    restart(void);
    virtual std::list<arcade::Vector2u> & 	getPlayerPosition(void);
    virtual bool 					        isPlayerAlive();
    virtual bool            			    isPlayerWin(void) const;
    virtual size_t        			        getScore(void) const;
    virtual arcade::Vector2u        		getDimension(void) const;
    virtual arcade::Vector2u			    getObjectPosition(void);
    virtual int 					        *find_tale(int, int **);
    virtual bool 					        eat_frut();
    virtual bool            			    updateGame(float const tick);
    virtual void 					      init();
    virtual bool 					move_player();
    virtual void 					goDown();
    virtual void 					goUp();
    virtual void 					goLeft();
    virtual void 					goRight();
    virtual void 					pop();
    virtual void 					update_key(arcade::Input);
    virtual void 					play();
    virtual void 					grow_up();
    virtual void 					move_body();
    virtual void                    shoot(void);
    //void 					print_map();
 private:
  std::list<arcade::Vector2u>	snake;
  arcade::Vector2u		dim;
  arcade::Vector2u		frut_p;
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
