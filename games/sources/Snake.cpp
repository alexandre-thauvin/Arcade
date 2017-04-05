//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.hpp"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2 + 1, dim.y / 2 + 1));
  _map = new arcade::Map(dim);
  _snake = new arcade::Personnage();
  std::cout << "create object \n";
  _map->createObject();
  std::cout << "create done\n";
}

bool arcade::Snake::isPlayerAlive() {
  return _alive;
}

bool arcade::Snake::move_player(void) {
  return (true);
}

void arcade::Snake::play() {
  
}

void arcade::Snake::goDown() {
  _snake->goDown();
}

void arcade::Snake::goUp() {
  _snake->goUp();
}

void arcade::Snake::goLeft() {
  _snake->goLeft();
}

void arcade::Snake::goRight() {
  _snake->goRight();
}

size_t arcade::Snake::getScore(void) const {
  return _score;
}

std::string arcade::Snake::getGamesName(void) const {
  return _name;
}

void arcade::Snake::restart(void) {
}

bool arcade::Snake::isPlayerWin(void) const {
  return true;
}

arcade::Vector2u arcade::Snake::getDimension(void) const {
  return _dim;
}

arcade::Map *arcade::Snake::getMap(void) const {
  return _map;
}

std::vector<arcade::Vector2u> const&	arcade::Snake::getPos() const {
  return _posPerso;
}

bool arcade::Snake::updateGame() {
  std::vector<Vector2u>::iterator it;
  arcade::Direction	dir;
  arcade::Vector2u	newPos;
  Vector2u		tmp(0, 0);

  dir = _snake->getDir();
  _posPerso = _snake->getPos();
  _map->clear();
  it = _posPerso.begin();
  switch(dir) {
  case D_UP :
    newPos.x =  it->x;
    newPos.y = it->y - 1;
    break;
  case D_DOWN :
    newPos.x =it->x;
    newPos.y = it->y + 1;
    break;
  case D_RIGHT :
    newPos.x = it->x + 1;
    newPos.y = it->y;
    break;
  case D_LEFT :
    newPos.x = it->x - 1;
    newPos.y = it->y;
    break;
  }
  if (it != _posPerso.end())
    _posPerso.pop_back();
  _posPerso.insert(it, newPos);
  it = _posPerso.begin();
  if (_map->getPosBlock(Vector2u(it->x, it->y)) == arcade::Map::Block ||
      _map->getPosBlock(Vector2u(it->x, it->y)) == arcade::Map::Player)
    return false;
  else if (_map->getPosBlock(Vector2u(it->x, it->y)) == arcade::Map::Object)
    {
      _posPerso.insert(it, newPos);
      _map->createObject();
      _score += 10;
    }
  it = _posPerso.begin();
  _snake->setPos(_posPerso);
  for (; it != _posPerso.end(); it++) {
    _map->setPosBlock(*it, arcade::Map::Player);
  }
  return true;
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void)dim;
    return (new arcade::Snake(dim));
  }
}
