//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.h"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _map = new arcade::Map(dim);
}

bool arcade::Snake::isPlayerAlive() {
  return false;
}

bool arcade::Snake::move_player(void) {
  return (true);
}

void arcade::Snake::play() {
}

void arcade::Snake::goDown() {
}

void arcade::Snake::goUp() {
}

void arcade::Snake::goLeft() {
}

void arcade::Snake::goRight() {
}

size_t arcade::Snake::getScore(void) const {
  return 0;
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
  return (_dim);
}

arcade::Map const *arcade::Snake::getMap(void) const {
  return _map;
}

bool arcade::Snake::updateGame(float const tick) {
  (void) tick;
  return (false);
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void)dim;
    return (new arcade::Snake(dim));
  }
}