#include "Centi.hpp"

arcade::Centi::Centi(std::vector<Vector2u> const& pos, Direction dir) : Personnage(){
  setPos(pos);
  centiDir = dir;
  lastDir = D_NONE;
}

void arcade::Centi::removeLastPos() {
  _pos.pop_back();
  setPos(_pos);
}

void	arcade::Centi::addFirstPos(Vector2u pos) {
  _pos.insert(_pos.begin(), pos);
  setPos(_pos);
}

void	arcade::Centi::removeMidPos(std::vector<Vector2u>::const_iterator const& it) {
  _pos.erase(it);
  setPos(_pos);
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
