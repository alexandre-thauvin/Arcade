#ifndef PERSONNAGE_HPP_
# define PERSONNAGE_HPP_

#include "Utils.hpp"
#include "Map.hpp"
#include <vector>

namespace arcade {
    enum Direction {
        D_UP,
        D_DOWN,
        D_LEFT,
        D_RIGHT,
        D_NONE
    };

    class Personnage {
    protected:
        Direction             _dir;
        std::vector<Vector2u> _pos;
    public:
        Personnage();

        ~Personnage() {};
        Personnage &operator=(Personnage const &);
        Direction const &getDir() const;
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        void goNone();
        void setPos(std::vector<Vector2u> const &);
        std::vector<Vector2u> const &getPos() const;
    };
}

#endif /* !PERSONNAGE_HPP_ */
