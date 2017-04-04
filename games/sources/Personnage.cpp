#include "Personnage.hpp"

arcade::Personnage::Personnage() {
  goLeft();
}

void	arcade::Personnage::goUp() {
  _dir = UP;
}

void	arcade::Personnage::goDown() {
  _dir = DOWN;
}

void	arcade::Personnage::goRight() {
  _dir = RIGHT;
}

void	arcade::Personnage::goLeft() {
  _dir = LEFT;
}

void	arcade::Personnage::setPos(std::vector<Vector2u> const& listPos) {
  _pos.erase(_pos.begin(), _pos.end());
  for (vector<Vector2u>::iterator it = listPos.begin(); it != listPos.end(); it++) {
    _pos.push_back(*it);
  }
}

std::vector<Vector2u> const&	arcade::Personnage::getPos() const {
  return (_pos);
}
