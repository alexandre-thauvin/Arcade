//
// Created by thauvi_a on 4/6/17.
//

#include <zconf.h>
#include "Centipede.h"

bool arcade::Centipede::isPlayerAlive() {
  return _alive;
}

bool arcade::Centipede::move_player(void) {
  return (true);
}

void arcade::Centipede::play() {

}

void arcade::Centipede::shoot() {
  _shoot = new arcade::Missile();
//  _shoot->setPos(_tower->getPos()[0]);
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

std::vector <arcade::Vector2u> const &arcade::Centipede::getPos() const {
  return _posPerso;
}

arcade::Centipede::Centipede(arcade::Vector2u const &dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2, dim.y - 4));
  _map   = new arcade::Map(dim);
  _tower = new arcade::Personnage();
  setchampi();

 _map->setPosBlock(arcade::Vector2u(1, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(2, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(3, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(4, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 4), arcade::Map::Enemy);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 4), arcade::Map::Player);
  _dim = dim;
}

bool arcade::Centipede::updateGame() {
  std::vector<Vector2u>::iterator it;
  arcade::Direction               dir;
  arcade::Vector2u                newPos;

  dir = _tower->getDir();
  it  = _posPerso.begin();
  switch (dir) {
    case D_UP :
      if (it->y > 15) {
        newPos.x = it->x;
        newPos.y = it->y - 1;
      }
      break;
    case D_DOWN :
      newPos.x = it->x;
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
    default:
      newPos = *it;
      break;
  }
  _tower->goNone();
  if (_map->getPosBlock(newPos) == arcade::Map::Enemy) {
    return false;
  }
  if (_map->getPosBlock(newPos) == arcade::Map::Empty) {
    _posPerso.pop_back();
    _posPerso.insert(it, newPos);
    _tower->setPos(_posPerso);
  }
//  if (_shoot)
//    _shoot->setPos(_shoot->get());
  std::cout << "before" << std::endl;
  if (!move_centi()) {
    return false;
  }
  _map->clear();
  for (it = _posPerso.begin(); it != _posPerso.end(); it++) {
    _map->setPosBlock(*it, arcade::Map::Player);
  }
  std::cout << "after" << std::endl;
  return true;
}

void arcade::Centipede::setchampi() {
  _map->setPosBlock(arcade::Vector2u(10, 2), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 1), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(3, 2), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(6, 5), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(10, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(4, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(9, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(8, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(3, 6), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(13, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(14, 7), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(12, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(8, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(5, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(15, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(11, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(3, 10), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(7, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(17, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(6, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(10, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(9, 12), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(2, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(12, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(5, 14), arcade::Map::Object);
  _map->setPosBlock(arcade::Vector2u(4, 14), arcade::Map::Object);
}

bool arcade::Centipede::move_centi() {
  arcade::Vector2u pos;

  unsigned int	x_tmp;
  bool 		check = true;
  bool 		check_entry;
  for (pos.y = 0 ; pos.y < _dim.y; pos.y++)
    {
      for (pos.x = 0 ; pos.x < _dim.x; pos.x++)
	{
	  check_entry = false;
	  if (_map->getPosBlock(pos) == arcade::Map::Centi) {
	      if (check) {
		_map->setPosBlock(pos, arcade::Map::Empty);
		check = false;
	      }
	      if (_map->getPosBlock(pos) == arcade::Map::Empty || _map->getPosBlock(pos) == arcade::Map::Centi){
		pos.x++;
		if (_map->getPosBlock(pos) == arcade::Map::Empty) {
		  _map->setPosBlock(pos, arcade::Map::Centi);
		}
		else if (_map->getPosBlock(pos) == arcade::Map::Object) {
		  std::cout << "avant pos = " << pos << std::endl;

		  pos.y++;
		  pos.x--;
		  x_tmp = pos.x;
		  if (_map->getPosBlock(pos) == arcade::Map::Centi) {
		    std::cout << "IT'S A CENTI" << std::endl;
		  }
		  else if (_map->getPosBlock(pos) == arcade::Map::Empty) {
		    std::cout << "IT'S EMPTYYYY" << std::endl;
		  }
		  while(_map->getPosBlock(pos) == arcade::Map::Centi) {
		    pos.x++;
		    std::cout << std::endl;
		    std::cout << "TOUR" << std::endl;
		    std::cout << std::endl;
		  }
		  std::cout << "apres pos = " << pos << std::endl;
		  //usleep(5000000);

		  _map->setPosBlock(pos, arcade::Map::Centi);
		  pos.x = x_tmp;
		  pos.x++;
		  pos.y--;
		}
		check_entry = true;
	      }
	    if (!check_entry) {
	      pos.x++;
	    }
	      if (_map->getPosBlock(pos) == arcade::Map::Player) {
		return false;
	      }
	      else if (pos.x + 1 == _dim.x) {
		pos.y++;
		x_tmp = pos.x;
		pos.x = 1;
		while (_map->getPosBlock(pos) == arcade::Map::Centi)
		  pos.x++;
		_map->setPosBlock(pos, arcade::Map::Centi);
		pos.x = x_tmp;
		pos.y--;
		//pos.x++;
//		return false;
	      }
	    	if (!check_entry) {
		  pos.x--;
		}
	    }
	}
    }
  return (true);
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void) dim;
    return (new arcade::Centipede(dim));
  }
}
  
