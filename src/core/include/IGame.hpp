//
// IGame.hpp for  in /home/aneopsy/cpp_arcade/src/core/include/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Tue Mar 28 16:38:52 2017 Paul THEIS
// Last update Tue Mar 28 16:38:53 2017 Paul THEIS
//

#ifndef _IGAMES_HPP_
# define _IGAMES_HPP_

# include <string>
# include <list>
# include <vector>

# include "Input.hpp"

namespace                       arcade {
  class                         IGames {
      public:
        virtual                 ~IGames(void) {}

        virtual std::string     getGamesName(void) const = 0; // get_name
        virtual DrawObject const  &getBackgroundTexture(void) const = 0; // see you

        virtual void            restart(void) = 0; // relance_s_fill_map

        virtual std::list<Vector2u> const& getPlayerPosition(void) const = 0; // head_x//head_y
        virtual bool            isPlayerAlive(void) const = 0; // check_death
        virtual bool            isPlayerWin(void) const = 0; // check_win
        virtual size_t          getScore(void) const = 0; // get_score
        virtual Vector2u        getDimension(void) const = 0; // get WIDTH
        virtual Vector2u        getScale(void) const = 0; // see you

        virtual void            updateGame(float const tick) = 0; //static += tick

        virtual Map const       &getMap(void) const = 0; // structure protocol

        virtual void            loadTexture(void) = 0; // a voir
        virtual Drawable const  *getTexture(Vector2u const& pos) const = 0; // avoir
        virtual std::vector<DrawObject> const& getDrawableEvent(void) const = 0; // a voir

        virtual void            go(void) = 0;
        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
        virtual void            goForward(void) = 0;
        virtual void            shoot(void) = 0; // only centipede
        virtual void            play(void) = 0; // init
      };
}

#endif /* !_IGAMES_HPP_ */
