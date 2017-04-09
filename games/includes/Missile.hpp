#ifndef MISSILE_HPP_
# define MISSILE_HPP_

#include "Utils.hpp"
#include "Map.hpp"
#include <vector>

namespace arcade {
    class Missile {
        Vector2u              _pos;
      bool		      _alive;
    public:
        Missile(Vector2u const&);
      ~Missile() {_alive = false;};

        Missile &operator=(Missile const &);
        void setAlive(bool);
        bool const& getAlive() const;
	void go();
        void setPos(Vector2u const &);
        Vector2u const &getPos() const;
    };
}

#endif /* !PERSONNAGE_HPP_ */
