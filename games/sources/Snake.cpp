//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.h"

bool Snake::move_player() {
  if (!isPlayerAlive())
  {
    return false;
  }
  this->eat_frut();
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

Snake::Snake(arcade::Vector2u const dim){
  this->mv = arcade::Input::SPACE;
  this->dim = dim;
  this->name = "Snake";
  this->frut = true;
  srand(time(NULL));
  this->frut_x = rand() % this->dim.x;
  this->frut_y = rand() % this->dim.y;
  this->head_x = this->dim.x / 2;
  this->head_y = this->dim.x / 2;
  this->score = 0;
  this->state = true;
  this->size = 2;
  this->map = new int*[this->dim.y];
  for(unsigned int i = 0; i < this->dim.y; ++i)
    this->map[i] = new int[this->dim.x];
}

void Snake::pop() {
  this->frut_x = rand() % this->dim.x;
  this->frut_y = rand() % this->dim.y;
  this->map[this->frut_y][this->frut_x] = FRUT;
  this->frut = true;
}

bool Snake::isPlayerAlive(){
  if (this->mv == arcade::Input::RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] > 1 || this->head_x == this->dim.x - 1)
      this->state = false;
  }
  else if (this->mv == arcade::Input::LEFT) {
    if (this->map[this->head_y][this->head_x - 1] > 1 || this->head_x == 0)
      this->state = false;
  }
  else if (this->mv == arcade::Input::UP) {
    if (this->map[this->head_y - 1][this->head_x] > 1 || this->head_y == 0)
      this->state = false;
  }
  else if (this->mv == arcade::Input::DOWN) {
    if (this->map[this->head_y + 1][this->head_x] > 1 || this->head_y == this->dim.x - 1)
      this->state = false;
  }
  if (!this->state)
    return (false);
  return (true);
}

void Snake::update_key(arcade::Input mv) {
  this->mv = mv;
}

void Snake::play() {
  this->init();
}

bool Snake::eat_frut() {
  if (this->mv == arcade::Input::RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] == FRUT)
      this->frut = false;
  }
  else if (this->mv == arcade::Input::LEFT) {
    if (this->map[this->head_y][this->head_x - 1] == FRUT)
      this->frut = false;
  }
  else if (this->mv == arcade::Input::UP) {
    if (this->map[this->head_y - 1][this->head_x] == FRUT)
      this->frut = false;
  }
  else if (this->mv == arcade::Input::DOWN) {
    if (this->map[this->head_y + 1][this->head_x] == FRUT)
      this->frut = false;
  }
  if (!this->frut) {
    this->score += 100;
    this->pop();
    grow_up();
    return (true);
  }
  return false;
}

void Snake::goDown() {
    this->head_y++;
    move_body();
    this->map[this->head_y][this->head_x] = 1;
}

void Snake::goUp() {
    this->head_y--;
    move_body();
    this->map[this->head_y][this->head_x] = 1;
}

void Snake::goLeft() {
    this->head_x--;
    move_body();
    this->map[this->head_y][this->head_x] = 1;
}

void Snake::goRight() {
    this->head_x++;
    move_body();
    this->map[this->head_y][this->head_x] = 1;
}

void Snake::grow_up() {
  this->tale = find_tale((int)this->size, this->map);
  this->size++;
  if (this->tale[1] != 0)
    this->map[this->tale[0]][this->tale[1] - 1] = (int)this->size;
  else
    this->size--;
}

void Snake::move_body() {
  this->tale = find_tale((int)this->size, this->map);
  for ( int i = (int)this->size; i > 1 ; i--){
    for (unsigned int z = 0 ; z < this->dim.y ; z++)
    {
      for (unsigned int j = 0; j < this->dim.x; j++) {
	if (this->map[z][j] == i - 1)
	  this->map[z][j] = i;
      }
    }
  }
  this->map[this->tale[0]][this->tale[1]] = 0;
}


size_t Snake::getScore(void) const {
  return this->score;
}

std::string Snake::getGamesName(void) const {
  return this->name;
}

void Snake::restart(void) {
  play();
}

bool Snake::isPlayerWin(void) const {
  for (unsigned int i = 0; i < this->dim.y ; i++)
  {
    for(unsigned int j = 0 ; j < this->dim.x ; j++) {
      if (this->map[i][j] == 0)
	return false;
    }
  }
  return true;
}

arcade::Vector2u Snake::getDimension(void) const {

  return (this->dim);
}

int 	*Snake::find_tale(int value, int **tab)
{
  unsigned int 	i = 0;
  unsigned int 	j = 0;

  int *tabi = new int[2];
  for (i = 0 ; i < this->dim.y; i++) {
    for (j = 0; j < this->dim.x; j++)
    {
      if (tab[i][j] == value) {
	tabi[0] = i;
	tabi[1] = j;
	return (tabi);
      }
    }
  }
  return (tabi);
}

void	Snake::init() {
  unsigned int i;
  unsigned int z;
  for (i = 0; i < this->dim.x; i++)
    for (z = 0; z < this->dim.x; z++)
      this->map[i][z] = 0;
  this->map[this->head_y][this->head_x] = HEAD;
  for (i = 1; i < 4; i++) {
    this->map[this->head_y][this->head_x - i] = (int)this->size;
    this->size++;
  }
  this->size--;
  this->tale = new int[2];
  this->tale[0] = this->head_y;
  this->tale[1] = this->head_x - 3;
  this->pop();
}

std::list<arcade::Vector2u> &Snake::getPlayerPosition(void) {
  arcade::Vector2u		vect;

  for (unsigned int i = 0 ; i < this->dim.y ; i++)
  {
    for (unsigned int j = 0 ; j < this->dim.x; j++) {
      if (this->map[i][j] == 1) {
	vect.x = j;
	vect.y = i;
	this->snake.push_back(vect);
      }
    }

  }
  for (unsigned int i = 0 ; i < this->dim.y ; i++)
  {
    for (unsigned int j = 0 ; j < this->dim.x; j++) {
      if (this->map[i][j] > 1) {
	vect.x = j;
	vect.y = i;
	this->snake.push_back(vect);
      }
    }

  }
  return (this->snake);
}

bool Snake::updateGame(float const tick) {
  static float	sum = 0.0;

  sum += tick;
  if (sum == 20)
    return (true);
  return (false);
}

arcade::Vector2u Snake::getObjectPosition(void) {
  this->frut_p.x = (unsigned int)this->frut_x;
  this->frut_p.y = (unsigned int)this->frut_y;
  return this->frut_p;
}

extern "C" {
  arcade::IGames *createGame(arcade::Vector2u dim) {
    return (new Snake(dim));
  }
}