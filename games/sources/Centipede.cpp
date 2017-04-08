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
  _tower->goDown();
}

void arcade::Centipede::goUp() {
  _tower->goUp();
}

void arcade::Centipede::goLeft() {
  _tower->goLeft();
}

void arcade::Centipede::goRight() {
  _tower->goRight();
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

arcade::Map const *arcade::Centipede::getMap(void) const {
  return _map;
}

std::vector<arcade::Vector2u> const&	arcade::Centipede::getPos() const {
  return _posPerso;
}

arcade::Centipede::Centipede(arcade::Vector2u const &dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2, dim.y - 2));
  _map = new arcade::Map(dim);
  _tower = new arcade::Personnage();
  setchampi();
  _map->setPosBlock(arcade::Vector2u(1, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(2, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(3, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(4, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(5, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 4), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 2), arcade::Map::Player);
  _map->createObject(Vector2u(0, 0));
  _dim = dim;
}

bool arcade::Centipede::updateGame() {
  std::vector<Vector2u>::iterator it;
  arcade::Direction dir;
  arcade::Vector2u newPos;
  Vector2u tmp(0, 0);

  dir = _tower->getDir();
  it = _posPerso.begin();
  switch (dir) {
    case D_UP :
      newPos.x = it->x;
      newPos.y = it->y - 1;
      if (_map->getPosBlock(*it) == arcade::Map::Object) {
	newPos.y = it->y + 1;
      }
      break;
    case D_DOWN :
      newPos.x = it->x;
      newPos.y = it->y + 1;
      if (_map->getPosBlock(*it) == arcade::Map::Object) {
	newPos.y = it->y - 1;
      }
      break;
    case D_RIGHT :
      newPos.x = it->x + 1;
      newPos.y = it->y;
      if (_map->getPosBlock(*it) == arcade::Map::Object) {
	newPos.y = it->x - 1;
      }
      break;
    case D_LEFT :
      newPos.x = it->x - 1;
      newPos.y = it->y;
      if (_map->getPosBlock(*it) == arcade::Map::Object) {
	newPos.y = it->x + 1;
      }
      break;
  }
  _posPerso.pop_back();
  if (_map->getPosBlock(newPos) == arcade::Map::Enemy) {
    return false;
  }
  _map->clear();
  _posPerso.insert(it, newPos);
  it = _posPerso.begin();
  if (_map->getPosBlock(*it) == arcade::Map::Block) {
    return false;
  }
  _tower->setPos(_posPerso);
  for (it = _posPerso.begin(); it != _posPerso.end(); it++) {
    _map->setPosBlock(*it, arcade::Map::Player);
  }
  if (!move_centi())
    return (false);
  return true;
}

void arcade::Centipede::setchampi() {
  _map->setPosBlock(arcade::Vector2u(10, 1), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(18, 1), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 1), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(10, 3), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(1, 3), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(19, 5), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(1, 5), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(5, 5), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(6, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(18, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(4, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(9, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(8, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(3, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(13, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(14, 8), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(12, 8), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(8, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(5, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(11, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(19, 11), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(1, 11), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(3, 11), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(7, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(17, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(6, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(10, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(9, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(18, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(12, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(5, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(4, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(14, 15), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(12, 15), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(6, 15), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(18, 15), arcade::Map::Object);
}

bool arcade::Centipede::move_centi() {
  arcade::Vector2u pos;
  for (pos.y = 0 ; pos.y < _dim.y; pos.y++)
  {
    for (pos.x = 0; pos.x < _dim.x ; pos.x++)
    {
      if (_map->getPosBlock(pos) == arcade::Map::Centi)
      {
	if (pos.x != _dim.x) {
	  pos.x++;
	}
	_map->setPosBlock(pos, arcade::Map::Empty);
	if (_map->getPosBlock(pos) == arcade::Map::Object) {
	  pos.x--;
	  if (pos.y != _dim.y) {
	    pos.y++;
	    if (_map->getPosBlock(pos) == arcade::Map::Player) {
	      return false;
	    }
	    _map->setPosBlock(pos, arcade::Map::Centi);
	    pos.y--;
	  }
	  else
	  {
	    pos.y--;
	    if (_map->getPosBlock(pos) == arcade::Map::Player) {
	      return false;
	    }
	    _map->setPosBlock(pos, arcade::Map::Centi);
	    pos.y++;
	  }
	}
	else if (_map->getPosBlock(pos) == arcade::Map::Player){
	  return (false);
	}
	_map->setPosBlock(pos, arcade::Map::Centi);
	pos.x--;
      }
    }
  }
  return (true);
}

void arcade::Centipede::shoot() {

}

extern "C" {
arcade::IGame *createGame(arcade::Vector2u const &dim) {
  (void)dim;
  return (new arcade::Centipede(dim));
}
}