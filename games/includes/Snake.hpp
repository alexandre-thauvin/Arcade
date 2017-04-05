//
// Created by thauvi_a on 3/20/17.
//

#ifndef ARCADE_SNAKE_H
#define ARCADE_SNAKE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../../src/core/include/Map.hpp"
#include "Personnage.hpp"
#include "IGame.hpp"

namespace                           arcade {
    class                           Snake : public arcade::IGame {
    public:
                                    Snake(arcade::Vector2u const& dim);
        virtual                     ~Snake() {};

        virtual                     std::string getGamesName(void) const;
        virtual void                restart(void);
        virtual bool                isPlayerAlive();
        virtual bool                isPlayerWin(void) const;
        virtual size_t              getScore(void) const;
        virtual arcade::Vector2u    getDimension(void) const;
        virtual bool                updateGame(float const tick);
        virtual arcade::Map         *getMap(void) const;
        virtual bool                move_player(void);
        virtual void                goDown();
        virtual void                goUp();
        virtual void                goLeft();
        virtual void                goRight();
        virtual void                play();
        virtual std::vector<Vector2u> const&  getPos() const;

    private:
        arcade::Map                 *_map;
        arcade::Personnage          *_snake;
        arcade::Vector2u            _dim;
        std::vector<Vector2u>	    _posPerso;
        std::string                 _name;
        bool                        _state;
        bool                        _alive;
        unsigned int                _score;
        unsigned int		    food;
    };
}

#endif //ARCADE_SNAKE_H
