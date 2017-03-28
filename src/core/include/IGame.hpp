è#ifndef _IGAMES_HPP_
# define _IGAMES_HPP_

# include <string>
# include <list>
# include <vector>

# include "Input.hpp"

namespace                       arcade {
  class                         IGames {
      public:
        virtual                 ~IGames(void) {}

        virtual std::string     getGamesName(void) const = 0;
        virtual DrawObject const  &getBackgroundTexture(void) const = 0;

        virtual bool            input(InputT const input) = 0;
        virtual void            restart(void) = 0;

        virtual std::list<Vector2u> const& getPlayerPosition(void) const = 0;
        virtual bool            isPlayerAlive(void) const = 0;
        virtual bool            isPlayerWin(void) const = 0;
        virtual void            setPlayerName(std::string const& name) = 0;
        virtual std::string     getPlayerName(void) const = 0;
        virtual size_t          getScore(void) const = 0;
        virtual Vector2u        getDimension(void) const = 0;
        virtual Vector2u        getScale(void) const = 0;

        virtual void            updateGame(float const delta) = 0;

        virtual Map const       &getMap(void) const = 0;

        virtual void            loadTexture(void) = 0;
        virtual Drawable const  *getTexture(Vector2u const& pos) const = 0;
        virtual std::vector<DrawObject> const& getDrawableEvent(void) const = 0;

        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
        virtual void            goForward(void) = 0;
        virtual void            shoot(void) = 0;
        virtual void            play(void) = 0;
      };
}

#endif /* !_IGAMES_HPP_ */
