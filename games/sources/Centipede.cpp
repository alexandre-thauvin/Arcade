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
  _snake->goDown();
}

void arcade::Centipede::goUp() {
  _snake->goUp();
}

void arcade::Centipede::goLeft() {
  _snake->goLeft();
}

void arcade::Centipede::goRight() {
  _snake->goRight();
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

arcade::Map *arcade::Centipede::getMap(void) const {
  return _map;
}

std::vector<arcade::Vector2u> const&	arcade::Centipede::getPos() const {
  return _posPerso;
}