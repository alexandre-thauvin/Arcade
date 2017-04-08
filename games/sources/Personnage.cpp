#include "Personnage.hpp"

arcade::Personnage::Personnage() {
  goNone();
}

arcade::Personnage& arcade::Personnage::operator=(Personnage const& pers) {
  if (&pers != this) {
    _dir = pers._dir;
    _pos = pers._pos;
  }
  return *this;
}

void	arcade::Personnage::goUp() {
  if (_dir != D_DOWN)
    _dir = D_UP;
}

void	arcade::Personnage::goNone() {
    _dir = D_NONE;
}

void	arcade::Personnage::goDown() {
  if (_dir != D_UP)
    _dir = D_DOWN;
}

void	arcade::Personnage::goRight() {
  if (_dir != D_LEFT)
    _dir = D_RIGHT;
}

void	arcade::Personnage::goLeft() {
  if (_dir != D_RIGHT)
  _dir = D_LEFT;
}

void	arcade::Personnage::setPos(std::vector<arcade::Vector2u> const& listPos) {
  _pos = listPos;
}

std::vector<arcade::Vector2u> const&	arcade::Personnage::getPos() const {
  return _pos;
}

arcade::Direction const&	arcade::Personnage::getDir() const {
  return _dir;
}
