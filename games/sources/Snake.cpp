//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include <ctime>
#include "Snake.h"

void Snake::move_player() {
  if (this->mv == RIGHT)
    move_right();
  else if (this->mv == LEFT)
    move_left();
  else if (this->mv == UP)
    move_up();
  else if (this->mv == DOWN)
    move_down();
}

Snake::Snake() {
  this->mv = STOP;
  this->frut = true;
  srand(time(NULL));
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->head_x = WIDTH / 2;
  this->head_y = WIDTH / 2;
  this->score = 0;
  this->state = true;
  this->size = 2;
}

void Snake::pop() {
  if (this->frut)
    return;
  this->frut_x = rand() % WIDTH;
  this->frut_y = rand() % WIDTH;
  this->map[this->frut_y][this->frut_x] = FRUT;
  this->frut = true;
}

bool Snake::check_death() {
  if (this->mv == RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] > 1 || this->head_x == WIDTH - 1)
      this->state = true;
  }
    else if (this->mv == LEFT) {
    if (this->map[this->head_y][this->head_x - 1] > 1 || this->head_x == 0)
      this->state = true;
  }
  else if (this->mv == UP) {
    if (this->map[this->head_y - 1][this->head_x] > 1 || this->head_y == 0)
      this->state = true;
  }
  else if (this->mv == DOWN) {
    if (this->map[this->head_y + 1][this->head_x] > 1 || this->head_y == WIDTH - 1)
      this->state = true;
  }
  return (false);
}

void Snake::update_key(move mv) {
  this->mv = mv;
}

void Snake::s_fill_map() {
  int i;
  int z;
  for (i = 0; i < WIDTH - 1; i++)
    for (z = 0; z < WIDTH - 1; z++)
      this->map[i][z] = 0;
  this->map[this->head_y][this->head_x] = HEAD;
  for (i = 1; i < 4; i++) {
    this->map[this->head_y][this->head_x - i] = (int)this->size;
    this->size++;
  }
  this->tale = (int*)malloc(2 * sizeof(int));
  this->tale[0] = this->head_y;
  this->tale[1] = this->head_x - 3;
}
void 	Snake::gestion(){
  Snake		*Snake = new Snake();

  Snake->s_fill_map();
  Snake->update_key(RIGHT);
  if (!Snake->check_death());
}

bool Snake::eat_frut() {
  if (this->mv == RIGHT) {
    if (this->map[this->head_y][this->head_x + 1] == FRUT || this->head_x == WIDTH - 1)
      this->state = true;
  }
  else if (this->mv == LEFT) {
    if (this->map[this->head_y][this->head_x - 1] == FRUT || this->head_x == 0)
      this->state = true;
  }
  else if (this->mv == UP) {
    if (this->map[this->head_y - 1][this->head_x] == FRUT || this->head_y == 0)
      this->state = true;
  }
  else if (this->mv == DOWN) {
    if (this->map[this->head_y + 1][this->head_x] == FRUT || this->head_y == WIDTH - 1)
      this->state = true;
  }
  if (this->state) {
    this->score += 100;
    grow_up();
    return (true);
  }
  return false;
}

void Snake::move_down() {
  if (!check_death())
    return;
  else {
    this->head_y++;
    this->map[this->head_y][this->head_x] = 1;
    move_body();
  }
}

void Snake::move_up() {
  if (!check_death())
    return;
  else {
    this->head_y--;
    this->map[this->head_y][this->head_x] = 1;
    move_body();
  }
}

void Snake::move_left() {
  if (!check_death())
    return;
  else {
    this->head_x--;
    this->map[this->head_y][this->head_x] = 1;
    move_body();
  }
}

void Snake::move_right() {
  if (!check_death())
    return;
  else {
    this->head_x++;
    this->map[this->head_y][this->head_x] = 1;
    move_body();
  }
}

void Snake::grow_up() {
  this->size++;
  this->tale = find_tale((int)this->size, this->map);
  if (this->tale[1] != 0)
    this->map[this->tale[0]][this->tale[1] - 1] = (int)this->size;
  else
    this->size--;
}

void Snake::move_body() {
  int 	x = 0;
  int 	y = 0;
  this->map[this->tale[0]][this->tale[1]] = 0;
  for (int i = (int)this->size - 1 ; i > 0 ; i--){
    for (int z = 0 ; z < WIDTH ; z++)
    {
      for (int j = 0; j < WIDTH; j++) {
	if (this->map[z][j] == i)
	{
	  y = z;
	  x = j;
	}
      }
    }
    this->map[y][x] = i + 1;
  }
}
