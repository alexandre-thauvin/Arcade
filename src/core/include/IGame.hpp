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
  class                         IGames {
      public:
        virtual                 ~IGames(void) {}

        virtual std::string     getGamesName(void) const = 0; // get_name
        //virtual DrawObject const  &getBackgroundTexture(void) const = 0; // Paul

        virtual void            restart(void) = 0; // relance play

       	virtual std::list<Vector2u> & getPlayerPosition(void) = 0; // Snake
        virtual bool            isPlayerAlive(void) = 0; // check_death
        virtual bool            isPlayerWin(void) const = 0; // check_win
        virtual size_t          getScore(void) const = 0; // get_score
        virtual Vector2u        getDimension(void) const = 0; // get WIDTH
    	virtual Vector2u	getObjectPosition(void) = 0; // spider for centipede / frut for Snake
        //virtual Vector2u        getScale(void) const = 0; // snake : 1 int pour 20 px  || centipede : 1 int pour 20px

        virtual bool            updateGame(float const tick) = 0; //static += tick 20

        //virtual Map const       &getMap(void) const = 0; // Paul

        //virtual void            loadTexture(void) = 0; // Paul
        //virtual Drawable const  *getTexture(Vector2u const& pos) const = 0; // Paul
        //virtual std::vector<DrawObject> const& getDrawableEvent(void) const = 0; // Paul

        virtual bool            move_player(void) = 0;
        virtual void            goUp(void) = 0;
        virtual void            goDown(void) = 0;
        virtual void            goLeft(void) = 0;
        virtual void            goRight(void) = 0;
        virtual void            play(void) = 0; // init
      };
}

#endif /* !_IGAMES_HPP_ */
