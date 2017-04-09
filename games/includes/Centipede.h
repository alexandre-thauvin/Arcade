//
// Created by thauvi_a on 4/6/17.
//

#ifndef CPP_ARCADE_CENTIPEDE_H
#define CPP_ARCADE_CENTIPEDE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include "Map.hpp"
#include "Personnage.hpp"
#include "Missile.hpp"
#include "IGame.hpp"

namespace arcade {
    class Centipede : public arcade::IGame {
    public:
        Centipede(arcade::Vector2u const &dim);

        virtual                     ~Centipede() {};

        virtual std::string getGamesName(void) const;
        virtual void restart(void);
        virtual bool isPlayerAlive();
        virtual bool isPlayerWin(void) const;
        virtual size_t getScore(void) const;
        virtual arcade::Vector2u getDimension(void) const;
        virtual bool updateGame();
        virtual arcade::Map const *getMap(void) const;
        virtual bool move_player(void);
        virtual void goDown();
        virtual void goUp();
        virtual void goLeft();
        virtual void goRight();
        virtual void play();
        virtual std::vector<Vector2u> const &getPos() const;
        void setchampi();
        bool move_centi();
        void shoot();
    private:
        Map           *_map;
        Personnage    *_tower;
	std::list<Personnage*>    _centi;
        Missile       *_shoot;
        Vector2u      _dim;
        std::vector<Vector2u> _posPerso;
        std::vector<Vector2u> _posCenti;
        std::string           _name;
        bool                  _state;
        bool                  _alive;
        unsigned int          _score;
        unsigned int          food;
    };
}

#endif //CPP_ARCADE_CENTIPEDE_H
