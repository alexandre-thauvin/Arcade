#ifndef _IGAME_HPP_
# define _IGAME_HPP_

# include <string>
# include <list>
# include <vector>
# include "Protocol.hpp"
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
        virtual std::string         getGamesName(void) const = 0;
        virtual void                restart(void) = 0;
        virtual bool                isPlayerAlive(void) = 0;
        virtual bool                isPlayerWin(void) const = 0;
        virtual size_t              getScore(void) const = 0;
        virtual Vector2u            getDimension(void) const = 0;
        virtual bool                updateGame() = 0;
        virtual Map const           *getMap(void) const = 0;
        virtual bool            move_player(void) = 0;
        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
        virtual void            shoot(void) = 0;
      };
}

#endif /* !_IGAMES_HPP_ */
