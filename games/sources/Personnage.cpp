#include "Personnage.hpp"

arcade::Personnage::Personnage() {
  goRight();
}

arcade::Personnage& arcade::Personnage::operator=(Personnage const& pers) {
  if (&pers != this) {
    _dir = pers._dir;
    _pos = pers._pos;
  }
  return *this;
}

void	arcade::Personnage::goUp() {
  _dir = D_UP;
}

void	arcade::Personnage::goDown() {
  _dir = D_DOWN;
}

void	arcade::Personnage::goRight() {
  _dir = D_RIGHT;
}

void	arcade::Personnage::goLeft() {
  _dir = D_LEFT;
}

void	arcade::Personnage::setPos(std::vector<arcade::Vector2u> const& listPos) {
  _pos = listPos;
 //  std::vector<arcade::Vector2u>::iterator it = listPos.begin();
 // _pos.erase(_pos.begin(), _pos.end());
 // for (; it != listPos.end(); it++) {
 //   _pos.push_back(*it);
 // }
}

std::vector<arcade::Vector2u> const&	arcade::Personnage::getPos() const {
  return _pos;
}

Direction const&	arcade::Personnage::getDir() const {
  return _dir;
}
