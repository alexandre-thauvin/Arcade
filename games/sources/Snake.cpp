//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.hpp"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _map = new arcade::Map(dim);
  _snake = new arcade::Personnage();
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

bool arcade::Snake::updateGame(float const tick) {
  std::vector<Vector2u>::iterator it;
  arcade::Map::CaseMap	**my_map;
  arcade::Direction	dir;
  arcade::Vector2u	newPos;

  (void)tick;
  dir = _snake->getDir();
  my_map = _map->getMap();
  _posPerso = _snake->getPos();
  switch(dir) {
  case D_UP :
    newPos.x = _posPerso[0].x;
    newPos.y = _posPerso[0].y - 1;
    break;
  case D_DOWN :
    newPos.x = _posPerso[0].x;
    newPos.y = _posPerso[0].y + 1;
    break;
  case D_RIGHT :
    newPos.x = _posPerso[0].x + 1;
    newPos.y = _posPerso[0].y;
    break;
  case D_LEFT :
    newPos.x = _posPerso[0].x - 1;
    newPos.y = _posPerso[0].y;
    break;
  }
  it = _posPerso.begin();
  _posPerso.insert(it, newPos);
  it = _posPerso.begin();
  if (my_map[_posPerso[0].y][_posPerso[0].x] == arcade::Map::Block ||
      my_map[_posPerso[0].y][_posPerso[0].x] == arcade::Map::Player)
    return false;
  if (my_map[_posPerso[0].y][_posPerso[0].x] == arcade::Map::Object)
    {
      my_map[_posPerso[0].y][_posPerso[0].x] = arcade::Map::Empty;
      _map->createObject();
      _score += 10;
    }
  return true;
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void)dim;
    return (new arcade::Snake(dim));
  }
}
