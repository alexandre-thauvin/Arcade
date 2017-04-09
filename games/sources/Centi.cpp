#include "Centi.hpp"

arcade::Centi::Centi(std::vector<Vector2u> const& pos) : Personnage(){
  setPos(pos);
  centiDir = D_RIGHT;
  lastDir = D_NONE;
}

void arcade::Centi::removeLastPos() {
  _pos.pop_back();
}

void	arcade::Centi::addFirstPos(Vector2u pos) {
  _pos.insert(_pos.begin(), pos);
}

arcade::Direction const& arcade::Centi::getLastDir() const {
  return lastDir;
}

void	arcade::Centi::setLastDir(Direction const& dir) {
  lastDir = dir;
}

arcade::Direction const& arcade::Centi::getCentiDir() const {
  return centiDir;
}

void	arcade::Centi::setCentiDir(Direction const& dir) {
  centiDir = dir;
}
