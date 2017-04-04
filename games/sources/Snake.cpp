//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.h"

bool Snake::move_player() {
  return true;
}

Snake::Snake(arcade::Vector2u const dim){
  (void)dim;
  _map = new arcade::Map(dim);
}

bool Snake::isPlayerAlive(){
 return false;
}

void Snake::play() {
}

void Snake::goDown() {
}

void Snake::goUp() {
}

void Snake::goLeft() {
}

void Snake::goRight() {
}

size_t Snake::getScore(void) const {
  return 0;
}

std::string Snake::getGamesName(void) const {
  return _name;
}

void Snake::restart(void) {
}

bool Snake::isPlayerWin(void) const {
  return true;
}

arcade::Vector2u Snake::getDimension(void) const {
  return (this->dim);
}

void	Snake::init() {
}

std::list<arcade::Vector2u> &Snake::getPlayerPosition(void) {
  arcade::Vector2u		vect;
  return (this->snake);
}

bool Snake::updateGame(float const tick) {
  (void)tick;
  return (false);
}

extern "C" {
  arcade::IGames *createGame(arcade::Vector2u dim) {
    return (new Snake(dim));
  }
}