//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.hpp"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2 + 1, dim.y / 2 + 1));
  _map = new arcade::Map(dim);
  _snake = new arcade::Personnage();
  _map->createObject();
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

bool arcade::Snake::updateGame(float const tick) {
  std::vector<Vector2u>::iterator it;
  arcade::Map::CaseMap	**my_map;
  arcade::Direction	dir;
  arcade::Vector2u	newPos;

  // if (tick % 20)
  //   return true;
  (void)tick;
  dir = _snake->getDir();
  my_map = _map->getMap();
  _posPerso = _snake->getPos();
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
 if (my_map[it->y][it->x] == arcade::Map::Block ||
     my_map[it->y][it->x] == arcade::Map::Player)
   return false;
 else if (my_map[it->y][it->x] == arcade::Map::Object)
   {
     my_map[it->y][it->x] = arcade::Map::Empty;
     _map->createObject();
     _score += 10;
   }
  _snake->setPos(_posPerso);
  return true;
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void)dim;
    return (new arcade::Snake(dim));
  }
}
