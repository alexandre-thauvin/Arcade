//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Map.hpp"
#include "IGame.hpp"

#define HEAD	(1)
#define FRUT	(-299)
// Le body sera représenté par une incrementation d'une variable => 2ème boule du snake =>2 etc...


class Snake : public  arcade::IGame {
 public:
  Snake(arcade::Vector2u const);
    virtual ~Snake(){};

    virtual std::string     		getGamesName(void) const;
    virtual void            		restart(void);
    virtual std::list<arcade::Vector2u> & 		getPlayerPosition(void);
    virtual bool 					isPlayerAlive();
    virtual bool            		isPlayerWin(void) const;
    virtual size_t        			getScore(void) const;
    virtual arcade::Vector2u        getDimension(void) const;
    virtual bool 					eat_frut();
    virtual bool            	    updateGame(float const tick);
    virtual void 					init();
    virtual bool 					move_player();
    virtual void 					goDown();
    virtual void 					goUp();
    virtual void 					goLeft();
    virtual void 					goRight();
    virtual void 					play();
    virtual arcade::Map const       &getMap(void) const;
    virtual std::vector<DrawObject> const& getDrawObject(void);


private:
    arcade::Map *_map;
  std::list<arcade::Vector2u>	snake;
  arcade::Vector2u		dim;
  arcade::Vector2u		frut_p;
  arcade::Input			mv;
  std::string			_name;
  size_t       			size;
  bool 				state;
  bool 				frut;

  int 				*tale;
  unsigned int 			head_x;
  unsigned int 			head_y;
  unsigned int			score;
};


#endif //ARCADE_SNAKE_H
