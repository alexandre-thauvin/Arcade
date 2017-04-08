#include "Missile.hpp"

arcade::Missile::Missile() {}

arcade::Missile& arcade::Missile::operator=(Missile const& a) {
  if (&a != this) {
    _pos = a._pos;
  }
  return *this;
}

void	arcade::Missile::setPos(arcade::Vector2u const& listPos) {
  _pos = listPos;
}

arcade::Vector2u const&	arcade::Missile::getPos() const {
  return _pos;
}