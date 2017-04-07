#ifndef _IGAME_HPP_
# define _IGAME_HPP_

# include <string>
# include <list>
# include <vector>
# include "Error.hpp"
# include "Input.hpp"
# include "Utils.hpp"
# include "DrawObject.hpp"
# include "Map.hpp"

namespace                       arcade {
  class                             IGame {
      public:
        virtual                     ~IGame(void) {}

    virtual std::vector<arcade::Vector2u> const&	getPos() const = 0;
        virtual std::string         getGamesName(void) const = 0; // get_name
        virtual void                restart(void) = 0; // relance play
        virtual bool                isPlayerAlive(void) = 0; // check_death
        virtual bool                isPlayerWin(void) const = 0; // check_win
        virtual size_t              getScore(void) const = 0; // get_score
        virtual Vector2u            getDimension(void) const = 0; // get WIDTH
        virtual bool                updateGame() = 0; //static += tick 20
        virtual Map const           *getMap(void) const = 0; // Paul
        virtual bool            move_player(void) = 0;
        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
      };
}

#endif /* !_IGAMES_HPP_ */
