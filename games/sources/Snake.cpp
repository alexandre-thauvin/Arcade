//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.hpp"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _map = new arcade::Map(dim);
  _snake = new arcade::Personnage();
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

arcade::Map *arcade::Snake::getMap(void) const {
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