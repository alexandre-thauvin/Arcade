//
// Created by thauvi_a on 4/6/17.
//

#include "Centipede.h"

bool arcade::Centipede::isPlayerAlive() {
  return _alive;
}

bool arcade::Centipede::move_player(void) {
  return (true);
}

void arcade::Centipede::play() {

}

void arcade::Centipede::goDown() {
  _tower->goDown();
}

void arcade::Centipede::goUp() {
  _tower->goUp();
}

void arcade::Centipede::goLeft() {
  _tower->goLeft();
}

void arcade::Centipede::goRight() {
  _tower->goRight();
}

size_t arcade::Centipede::getScore(void) const {
  return _score;
}

std::string arcade::Centipede::getGamesName(void) const {
  return _name;
}

void arcade::Centipede::restart(void) {
}

bool arcade::Centipede::isPlayerWin(void) const {
  return true;
}

arcade::Vector2u arcade::Centipede::getDimension(void) const {
  return _dim;
}

arcade::Map const *arcade::Centipede::getMap(void) const {
  return _map;
}

std::vector<arcade::Vector2u> const&	arcade::Centipede::getPos() const {
  return _posPerso;
}

arcade::Centipede::Centipede(arcade::Vector2u const &dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2, dim.y - 2));
  _map = new arcade::Map(dim);
  _tower = new arcade::Personnage();
  _map->setPosBlock(arcade::Vector2u(1, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(2, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(3, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(4, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(5, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 4), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 2), arcade::Map::Player);
  _map->createObject(Vector2u(0, 0));
  _dim = dim;
}

extern "C" {
arcade::IGame *createGame(arcade::Vector2u const &dim) {
  (void)dim;
  return (new arcade::Centipede(dim));
}
}

bool arcade::Centipede::updateGame() {
  std::vector<Vector2u>::iterator it;
  arcade::Direction dir;
  arcade::Vector2u newPos;
  int r = 0;
  Vector2u tmp(0, 0);

  dir = _tower->getDir();
  it = _posPerso.begin();
  switch (dir) {
    case D_UP :
      newPos.x = it->x;
      newPos.y = it->y - 1;
      if (_map->getPosBlock(*it) == arcade::Map::Object)
	newPos.y = it->y + 1;
	break;
    case D_DOWN :
      newPos.x = it->x;
      newPos.y = it->y + 1;
      if (_map->getPosBlock(*it) == arcade::Map::Object)
	newPos.y = it->y - 1;
      break;
    case D_RIGHT :
      newPos.x = it->x + 1;
      newPos.y = it->y;
      if (_map->getPosBlock(*it) == arcade::Map::Object)
	newPos.y = it->x - 1;
      break;
    case D_LEFT :
      newPos.x = it->x - 1;
      newPos.y = it->y;
      if (_map->getPosBlock(*it) == arcade::Map::Object)
	newPos.y = it->x + 1;
      break;
  }
  _posPerso.pop_back();
  if (_map->getPosBlock(newPos) == arcade::Map::Enemy)
    return false;
  _map->clear();
  _posPerso.insert(it, newPos);
  it = _posPerso.begin();
  if (_map->getPosBlock(*it) == arcade::Map::Block)
    return false;
}

void arcade::Centipede::setchampi() {
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Enemy);
}
