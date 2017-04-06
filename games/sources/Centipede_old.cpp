//
// Created by thauvi_a on 3/20/17.
//

#include <zconf.h>
#include "Centipede.h"

Centipede::Centipede(arcade::Vector2u dim) {
  this->mv = arcade::Input::SPACE;
  this->dim = dim;
  this->name = "Centipede";
  srand(time(NULL));
  this->spider.x = rand() % this->dim.x;
  this->spider.y = rand() % this->dim.y;
  this->tower.x = this->dim.x / 2;
  this->tower.y = this->dim.y - 2;
  this->score = 0;
  this->state = true;
  this->map = new int*[this->dim.y];
  for(unsigned int i = 0; i < this->dim.y; ++i)
    this->map[i] = new int[this->dim.x];
}

bool Centipede::move_ia() {

  int 	dir;
  int	check = 0;

  this->map[this->spider.y][this->spider.x] = 0;
  while (check == 0) {
    dir = rand() % 4;
    if (dir == 0) {
      if (this->spider.x != this->dim.x - 1)
	this->spider.x++;
      check = 1;
    }
    else if (dir == 1) {
      if (this->spider.x != 0)
	this->spider.x--;
      check = 1;
    }
    else if (dir == 2) {
      if (this->spider.y != 0)
	this->spider.y--;
      check = 1;
    }
    else if (dir == 3) {
      if (this->spider.y != this->dim.y - 1)
	this->spider.y++;
      check = 1;
    }
  }
  if (this->map[this->spider.y][this->spider.x] == TOWER) {
    this->map[this->spider.y][this->spider.x] = SPIDER;
    return (false);
  }
  return (true);
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
  else if (this->mv == arcade::Input::SPACE)
    this->shoot();
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
  if (this->tower.y != 0 && this->tower.y < (this->dim.y * 0.2)) {
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
  this->init();
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
  this->play();
}

bool Centipede::isPlayerWin(void) const {
  for (unsigned int i = 0 ; i < this->dim.y ; i++) {
    for (unsigned int j = 0; j < this->dim.x; j++) {
      if (this->map[i][j] == HEAD || this->map[i][j] == BODY)
	return false;
    }
  }
  return true;
}

void Centipede::shoot() {
  for (unsigned int i = this->tower.y - 1; i > 0; i--){
    if (this->map[i][this->tower.x] == CHAMP)
      this->map[i][this->tower.x] = 0;
    else if (this->map[i][this->tower.x] == SPIDER)
    {
      this->map[i][this->tower.x] = 0;
      this->score += 300;
      this->pop();
      break;
    }
    else if (this->map[i][this->tower.x] == HEAD)
    {
      this->replace_head(i);
      this->score += 500;
      break;
    }
    else if (this->map[i][this->tower.x] == BODY)
    {
      this->split();
      this->score += 400;
      break;
    }
  }
}

void Centipede::split() {

}

void Centipede::move_body() {

}

void Centipede::init() {
  unsigned int i;
  unsigned int z;
  for (i = 0; i < this->dim.x; i++)
    for (z = 0; z < this->dim.x; z++)
      this->map[i][z] = 0;
  this->pop();
  this->init_centi();
  this->init_champ();
}

bool Centipede::updateGame(float const tick) {
  (void)tick;
  return false;
}

arcade::Vector2u Centipede::getDimension(void) const {
  return (this->dim);
}

std::list<arcade::Vector2u> Centipede::getCentiPosition(void) {
  std::list<arcade::Vector2u>           obj;
  arcade::Vector2u		vect;

  for (unsigned int i = 0 ; i < this->dim.y ; i++)
  {
    for (unsigned int j = 0 ; j < this->dim.x; j++) {
      if (this->map[i][j] == HEAD || this->map[i][j] == BODY) {
	vect.x = j;
	vect.y = i;
	obj.push_back(vect);
      }
    }
  }
  return obj;
}

std::list<arcade::Vector2u> Centipede::getChampPosition(void) {
  arcade::Vector2u		vect;
  std::list<arcade::Vector2u>           obj;

  for (unsigned int i = 0 ; i < this->dim.y ; i++)
  {
    for (unsigned int j = 0 ; j < this->dim.x; j++) {
      if (this->map[i][j] == CHAMP) {
	vect.x = j;
	vect.y = i;
	obj.push_back(vect);
      }
    }
  }
  return obj;
}

std::list<arcade::Vector2u> Centipede::getObjectPosition(arcade::object obj) {
  std::list<arcade::Vector2u>           obji;
  if (obj == arcade::ARAKN) {
    for (unsigned int i = 0; i < this->dim.y; i++) {
      for (unsigned int j = 0; j < this->dim.x; j++) {
	if (this->map[i][j] == SPIDER) {
	  this->spider.x = j;
	  this->spider.y = i;
          obji.push_back(spider);
          return (obji);
	}
      }
    }
  }
  else if (obj == arcade::CHAMPI)
    return (this->getChampPosition());
  else if (obj == arcade::object::CENTI)
    return (this->getCentiPosition());
}

arcade::Vector2u &Centipede::getTowerPosition(void) {

  for (unsigned int i = 0 ; i < this->dim.y ; i++) {
    for (unsigned int j = 0; j < this->dim.x; j++) {
      if (this->map[i][j] == TOWER) {
	this->tower.x = j;
	this->tower.y = i;
      }
    }
  }
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

void Centipede::init_champ() {
  unsigned int 	x;
  unsigned int 	y;
  for (unsigned int i = 0 ; i < 10 ; i++) {
    while (0) {
      usleep(100);
      x = rand() % this->dim.x;
      y = rand() % this->dim.y;
      if (this->map[y][x] == 0)
	break;
      }
    this->map[y][x] = CHAMP;
    }
}


void Centipede::init_centi() {
  for (unsigned int i = 0; i < 3 ; i++)
    this->map[0][i] = BODY;
  this->map[0][3] = HEAD;
}

void Centipede::replace_head(unsigned int i) {
  this->map[i][this->tower.x] = 0;
  if (this->map[i][this->tower.x + 1] == BODY)
    this->map[i][this->tower.x + 1] = HEAD;
  else if (this->map[i][this->tower.x - 1] == BODY)
    this->map[i][this->tower.x] = HEAD;
  else if (this->map[i - 1][this->tower.x] == BODY)
    this->map[i - 1][this->tower.x] = HEAD;
  else if (this->map[i + 1][this->tower.x] == BODY)
    this->map[i + 1][this->tower.x] = HEAD;
}

std::list<arcade::Vector2u> &Centipede::getPlayerPosition(void) {
  std::list<arcade::Vector2u>	obi;
  arcade::Vector2u		ob = this->getTowerPosition();

  obi.push_back(ob);
  return obi;
}