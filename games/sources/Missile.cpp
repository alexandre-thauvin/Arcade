#include "Missile.hpp"

arcade::Missile::Missile(Vector2u const& pos) : _pos(pos), _alive(true){
}

arcade::Missile& arcade::Missile::operator=(Missile const& a) {
  if (&a != this) {
    _pos = a._pos;
  }
  return *this;
}

void	arcade::Missile::go() {
  _pos.y -= 1;
}

void	arcade::Missile::setPos(arcade::Vector2u const& listPos) {
  _pos = listPos;
}

arcade::Vector2u const&	arcade::Missile::getPos() const {
  return _pos;
}

void	arcade::Missile::setAlive(bool alive) {
  _alive = alive;
}

bool const&	arcade::Missile::getAlive() const {
  return _alive;
}
