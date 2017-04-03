//
// Created by thauvi_a on 3/20/17.
//

#include "Centipede.h"

Centipede::Centipede(arcade::Vector2u dim) {
  this->mv = arcade::Input::SPACE;
  this->dim = dim;
  this->name = "Centipede";
  srand(time(NULL));
  this->spider.x = rand() % this->dim.x;
  this->spider.y = rand() % this->dim.y;
  //this->head_x = this->dim.x / 2;
  //this->head_y = this->dim.x / 2;
  this->score = 0;
  this->state = true;
  this->map = new int*[this->dim.y];
  for(unsigned int i = 0; i < this->dim.y; ++i)
    this->map[i] = new int[this->dim.x];
}

void Centipede::move_ia() {

}

bool Centipede::move_player() {
  if (!isPlayerAlive())
    return false;
  this->find_tower();
  if (this->mv == arcade::Input::RIGHT)
    goRight();
  else if (this->mv == arcade::Input::LEFT)
    goLeft();
  else if (this->mv == arcade::Input::UP)
    goUp();
  else if (this->mv == arcade::Input::DOWN)
    goDown();
  return true;
}

void Centipede::update_key(arcade::Input moove) {
  this->mv = moove;
}

void Centipede::pop() {
  this->spider.x = rand() % this->dim.x;
  this->spider.y = rand() % this->dim.y;
  this->map[this->spider.y][this->spider.x] = SPIDER;
}

void Centipede::goRight() {
  if (this->tower.x != this->dim.x - 1) {
    this->map[this->tower.y][this->tower.x] = 0;
    this->tower.x++;
    this->map[this->tower.y][this->tower.x] = TOWER;
  }
}

void Centipede::goLeft() {
  if (this->tower.x != 0) {
    this->map[this->tower.y][this->tower.x] = 0;
    this->tower.x--;
    this->map[this->tower.y][this->tower.x] = TOWER;
  }
}

void Centipede::goUp() {
  if (this->tower.y != 0) {
    this->map[this->tower.y][this->tower.x] = 0;
    this->tower.y--;
    this->map[this->tower.y][this->tower.x] = TOWER;
  }
}

void Centipede::goDown() {
  if (this->tower.y != this->dim.y - 1) {
    this->map[this->tower.y][this->tower.x] = 0;
    this->tower.y++;
    this->map[this->tower.y][this->tower.x] = TOWER;
  }
}

void Centipede::play() {

}

size_t Centipede::getScore(void) const {
  return this->score;
}

bool Centipede::isPlayerAlive() {
  if (this->mv == arcade::Input::RIGHT) {
    if (this->map[this->tower.y][this->tower.x + 1] == SPIDER || this->map[this->tower.y][this->tower.x + 1] == HEAD ||
	this->map[this->tower.y][this->tower.x + 1] ==  BODY)
      this->state = false;
  }
  else if (this->mv == arcade::Input::LEFT) {
    if (this->map[this->tower.y][this->tower.x - 1] == SPIDER || this->map[this->tower.y][this->tower.x + 1] == HEAD ||
	this->map[this->tower.y][this->tower.x + 1] ==  BODY)
      this->state = false;
  }
  else if (this->mv == arcade::Input::UP) {
    if (this->map[this->tower.y - 1][this->tower.x] == SPIDER || this->map[this->tower.y][this->tower.x + 1] == HEAD ||
	this->map[this->tower.y - 1][this->tower.x] ==  BODY)
      this->state = false;
  }
  else if (this->mv == arcade::Input::DOWN) {
    if (this->map[this->tower.y + 1][this->tower.x] == SPIDER || this->map[this->tower.y][this->tower.x + 1] == HEAD ||
	this->map[this->tower.y + 1][this->tower.x] ==  BODY)
      this->state = false;
  }
if (!this->state)
    return (false);
  return (true);
}

std::string Centipede::getGamesName(void) const {
  return this->name;
}

void Centipede::restart(void) {

}

bool Centipede::isPlayerWin(void) const {
  return false;
}

void Centipede::shoot() {

}

void Centipede::split() {

}

void Centipede::move_body_cent() {

}

void Centipede::init() {

}

bool Centipede::updateGame(float const tick) {
  (void)tick;
  return false;
}

arcade::Vector2u Centipede::getDimension(void) const {

  return (this->dim);
}

arcade::Vector2u Centipede::getCentiPosition(void) {
  return arcade::Vector2u();
}

arcade::Vector2u Centipede::getChampPosition(void) {
  return arcade::Vector2u();
}

arcade::Vector2u Centipede::getObjectPosition(void) {
  return arcade::Vector2u();
}

arcade::Vector2u &Centipede::getTowerPosition(void) {
  return (this->tower);
}

void Centipede::find_tower() {
  for (unsigned int i = 0; i < this->dim.y ; i++)
  {
    for(unsigned int j = 0; j < this->dim.x ; j++)
      if (this->map[i][j] == TOWER) {
	this->tower.y = i;
	this->tower.x = j;
	return ;
      }
  }
}
