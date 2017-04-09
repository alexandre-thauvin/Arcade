//
// Created by thauvi_a on 4/6/17.
//

#include <ctime>
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
  if (_shoot != NULL && _shoot->getAlive())
    return ;
  else
    _shoot = new arcade::Missile(_posPerso[0]);
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
  std::vector<Vector2u>	pos;

  _score = 0;
  _shoot = NULL;
  std::srand(std::time(0));
  _posPerso.push_back(arcade::Vector2u(dim.x / 2, dim.y - 4));
  _map   = new arcade::Map(dim);
  _tower = new arcade::Personnage();
  pos.push_back(arcade::Vector2u(1, 1));
  pos.push_back(arcade::Vector2u(2, 1));
  pos.push_back(arcade::Vector2u(3, 1));
  pos.push_back(arcade::Vector2u(4, 1));
  pos.push_back(arcade::Vector2u(5, 1));
  pos.push_back(arcade::Vector2u(6, 1));
  pos.push_back(arcade::Vector2u(7, 1));
  _centi.push_back(new arcade::Centi(pos));
  _centi.front()->goRight();
  setchampi();
  _map->setPosBlock(arcade::Vector2u(1, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(2, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(3, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(4, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(5, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(6, 1), arcade::Map::Centi);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y - 4),
                    arcade::Map::Player);
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
  _map->clear();
  for (it = _posPerso.begin(); it != _posPerso.end(); it++) {
    _map->setPosBlock(*it, arcade::Map::Player);
  }
  if (!move_centi())
    return false;
  if (_shoot && _shoot->getAlive())
    {
      _shoot->go();
      if (_map->getPosBlock(_shoot->getPos()) == arcade::Map::Empty)
  	{
	  _map->setPosBlock(Vector2u(_shoot->getPos().x, _shoot->getPos().y + 1), Map::Empty);
	  _map->setPosBlock(_shoot->getPos(), Map::Shoot);
	}
      else
  	{
	  switch (_map->getPosBlock(_shoot->getPos())) {
	  case Map::Object :
	    _map->setPosBlock(_shoot->getPos(), Map::Empty);
	    _map->setPosBlock(Vector2u(_shoot->getPos().x, _shoot->getPos().y + 1), Map::Empty);
	    _shoot->setAlive(false);
	    break;
	  case Map::Block :
	    _map->setPosBlock(Vector2u(_shoot->getPos().x, _shoot->getPos().y + 1), Map::Empty);
	    _shoot->setAlive(false);
	    break;
	  case Map::Centi :
	    //createNewCenti(_shoot->getPos());
	    _map->setPosBlock(_shoot->getPos(), Map::Object);
	  default :
	    break;
	  }
  	}
    }
  return true;
}

// void arcade::Centipede::createNewCenti(arcade::Vector2u const& pos) {
//   int	i = -1;
  
//   for (std::list<Centi *>::iterator it = _centi.begin(); it != _centi.end(); it++) {
//     for (std::vector<Vector2u>::const_iterator itv = (*it)->getPos().begin(); itv != (*it)->getPos().end(); itv++) {
//       if (pos.x == (*itv).x && pos.y == (*itv).y)
// 	i = 0;
//       if (i >= 0)
//       	{
//       	  i++;
//       	  (*it)->removeLastPos();
//       	}
//     }
//   }
//   std::cout << i << "\n";
// }

void arcade::Centipede::setchampi() {
  for (unsigned int y = 1; y < 19; ++y) {
    for (unsigned int x = 1; x < 19; ++x) {
      if ((std::rand() % 20) == 0)
        _map->setPosBlock(arcade::Vector2u(x, y), arcade::Map::Object);
    }
  }
}

bool arcade::Centipede::move_centi() {
  Vector2u	newPos;

  for (std::list<Centi *>::iterator it = _centi.begin(); it != _centi.end(); it++) {
    Vector2u	pos((*it)->getPos()[0].x, (*it)->getPos()[0].y);
      switch ((*it)->getCentiDir()) {
      case D_RIGHT :
	newPos.x = pos.x + 1;
	newPos.y = pos.y;
	(*it)->setLastDir(D_RIGHT);
	break;
      case D_LEFT :
	newPos.x = pos.x - 1;
	newPos.y = pos.y;
	(*it)->setLastDir(D_LEFT);
      break;
      case D_DOWN :
	newPos.x = pos.x;
	newPos.y = pos.y + 1;
	break;
      default :
	break;
      }
      if (newPos.y == 19 || _map->getPosBlock(newPos) == Map::Player)
	return false;
      if ((*it)->getCentiDir() == D_DOWN && (*it)->getLastDir() == D_RIGHT)
	(*it)->setCentiDir(D_LEFT);
      if ((*it)->getCentiDir() == D_DOWN && (*it)->getLastDir() == D_LEFT)
	(*it)->setCentiDir(D_RIGHT);
      (*it)->removeLastPos();
      (*it)->addFirstPos(newPos);
      if (((*it)->getCentiDir() == D_RIGHT &&
	   (_map->getPosBlock(Vector2u((*it)->getPos()[0].x + 1, (*it)->getPos()[0].y)) == Map::Block ||
	    _map->getPosBlock(Vector2u((*it)->getPos()[0].x + 1, (*it)->getPos()[0].y)) == Map::Object))
	  ||
	  ((*it)->getCentiDir() == D_LEFT &&
	   (_map->getPosBlock(Vector2u((*it)->getPos()[0].x - 1, (*it)->getPos()[0].y)) == Map::Block ||
	    _map->getPosBlock(Vector2u((*it)->getPos()[0].x - 1, (*it)->getPos()[0].y)) == Map::Object)))
      	(*it)->setCentiDir(D_DOWN);
      for (std::vector<Vector2u>::const_iterator itv = (*it)->getPos().begin(); itv != (*it)->getPos().end(); itv++) {
	_map->setPosBlock((*itv), Map::Centi);
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
  
