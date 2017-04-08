#ifndef MISSILE_HPP_
# define MISSILE_HPP_

#include "Utils.hpp"
#include "Map.hpp"
#include <vector>

namespace arcade {
    class Missile {
        Vector2u              _pos;
    public:
        Missile();
        ~Missile() {};

        Missile &operator=(Missile const &);
        void go();
        void setPos(Vector2u const &);
        Vector2u const &getPos() const;
    };
}

#endif /* !PERSONNAGE_HPP_ */
