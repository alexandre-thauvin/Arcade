#ifndef _IGAMES_HPP_
# define _IGAMES_HPP_

# include <string>
# include <list>
# include <vector>
# include "Error.hpp"
# include "Input.hpp"
# include "Utils.hpp"
# include "DrawObject.hpp"

namespace                       arcade {
  enum 		object{
    FRUIT,
    CHAMPI,
    CENTI,
    ARAKN
  };
  class                             IGames {
      public:
        virtual                     ~IGames(void) {}

        virtual std::string         getGamesName(void) const = 0; // get_name
        virtual void                restart(void) = 0; // relance play
       	virtual std::list<Vector2u> &getPlayerPosition(void) = 0; // Snake
        virtual bool                isPlayerAlive(void) = 0; // check_death
        virtual bool                isPlayerWin(void) const = 0; // check_win
        virtual size_t              getScore(void) const = 0; // get_score
        virtual Vector2u            getDimension(void) const = 0; // get WIDTH
        virtual bool                updateGame(float const tick) = 0; //static += tick 20
        virtual Map const           &getMap(void) const = 0; // Paul
        virtual std::vector<DrawObject> const& getDrawObject(void) const = 0; // Paul

        virtual bool            move_player(void) = 0;
        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
        virtual void            play(void) = 0;
      };
}

#endif /* !_IGAMES_HPP_ */
