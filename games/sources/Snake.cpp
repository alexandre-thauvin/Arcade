//
// Created by thauvi_a on 3/20/17.
//

#include "Snake.hpp"

arcade::Snake::Snake(arcade::Vector2u const &dim) : _dim(dim) {
  _posPerso.push_back(arcade::Vector2u(dim.x / 2, dim.y / 2));
  _posPerso.push_back(arcade::Vector2u(dim.x / 2 - 1, dim.y / 2));
  _posPerso.push_back(arcade::Vector2u(dim.x / 2 - 2, dim.y / 2));
  _posPerso.push_back(arcade::Vector2u(dim.x / 2 - 3, dim.y / 2));
  _map = new arcade::Map(dim);
  _snake = new arcade::Personnage();
  _map->setPosBlock(arcade::Vector2u(dim.x / 2, dim.y / 2), arcade::Map::Player);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2 - 1, dim.y / 2), arcade::Map::Player);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2 - 2, dim.y / 2), arcade::Map::Player);
  _map->setPosBlock(arcade::Vector2u(dim.x / 2 - 3, dim.y / 2), arcade::Map::Player);
  _map->createObject(Vector2u(0, 0));
  _name = "Snake";
}

bool arcade::Snake::isPlayerAlive() {
  return _alive;
}

bool arcade::Snake::move_player(void) {
  return (true);
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
  return _score;
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
  return _dim;
}

arcade::Map *arcade::Snake::getMap(void) const {
  return _map;
}

std::vector<arcade::Vector2u> const&	arcade::Snake::getPos() const {
  return _posPerso;
}

bool arcade::Snake::updateGame() {
  std::vector<Vector2u>::iterator it;
  arcade::Direction	dir;
  arcade::Vector2u	newPos;
  int			r = 0;
  Vector2u		tmp(0, 0);

  dir = _snake->getDir();
  it = _posPerso.begin();
  switch(dir) {
  case D_UP :
    newPos.x = it->x;
    newPos.y = it->y - 1;
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
  }
  _posPerso.pop_back();
  if (_map->getPosBlock(newPos) == arcade::Map::Player)
    return false;
  _map->clear();
  _posPerso.insert(it, newPos);
  it = _posPerso.begin();
  if (_map->getPosBlock(*it) == arcade::Map::Block)
    return false;
  else if (_map->getPosBlock(*it) == arcade::Map::Object)
    {
      it = _posPerso.end();
      _posPerso.insert(it, newPos);
      r = 1;
      _score += 10;
    }
  _snake->setPos(_posPerso);
  for (it = _posPerso.begin(); it != _posPerso.end(); it++) {
    _map->setPosBlock(*it, arcade::Map::Player);
  }
  it = _posPerso.begin();
  if (r == 1)
    _map->createObject(*it);
  return true;
}

extern "C" {
  arcade::IGame *createGame(arcade::Vector2u const &dim) {
    (void)dim;
    return (new arcade::Snake(dim));
  }
}

/*
 * Mouli
 */

void				arcade::Snake::getMap()
{
  struct GetMap			*getMap;
  
  getMap = new GetMap[sizeof(GetMap) + (_dim.x * _dim.y) * sizeof(TileType)];
  getMap->type = arcade::CommandType::GET_MAP;
  getMap->width = _dim.x;
  getMap->height = _dim.y;
  for (unsigned int i = 0; i < _dim.y; i++) {
    for (unsigned int y = 0; y < _dim.x; y++) {
      switch (_map->getPosBlock(Vector2u(i, y))) {
      case arcade::Map::Player :
	getMap->tile[i * y] = arcade::TileType::OTHER;
	break;
      case arcade::Map::Empty :
	getMap->tile[i * y] = arcade::TileType::EMPTY;
	break;
      case arcade::Map::Block :
	getMap->tile[i * y] = arcade::TileType::BLOCK;
	break;
      case arcade::Map::Object :
	getMap->tile[i * y] = arcade::TileType::POWERUP;
	break;
      default:
	break;
      }
    }
  }
  std::cout.write((char*)getMap, sizeof(GetMap) * (_dim.x * _dim.y) * sizeof(TileType));
}

void				        arcade::Snake::whereAmI()
{
  struct WhereAmI			*whereAmI;
  int					i;

  i = 0;
  whereAmI = new arcade::WhereAmI[sizeof(WhereAmI) + _posPerso.size() * sizeof(Position)];
  whereAmI->type = arcade::CommandType::WHERE_AM_I;
  whereAmI->lenght = (uint16_t)(_posPerso.size());
  for (std::vector<Vector2u>::iterator it = _posPerso.begin(); it != _posPerso.end(); it++) {
std::cout << "PASS\n";
    whereAmI->position[i].x = it->x;
    whereAmI->position[i].y = it->y;
    i++;
}
std::cout.write((char*)whereAmI, sizeof(WhereAmI) + ((_dim.x * _dim.y) - whereAmI->lenght));// + _posPerso.size() * sizeof(Position)
delete(whereAmI);
}

extern "C" void				Play() {
  arcade::CommandType		lastInput;
  arcade::Snake		        snake(arcade::Vector2u(20, 20));

  while (!std::cout.eof())
    {
      lastInput = (arcade::CommandType)std::cin.get();
      switch(lastInput)
	{
	case arcade::CommandType::GO_UP :
	  snake.goUp();
	  break;
	case arcade::CommandType::GO_DOWN :
	  snake.goDown();
	  break;
	case arcade::CommandType::GO_LEFT :
	  snake.goLeft();
	  break;
	case arcade::CommandType::GO_RIGHT :
	  snake.goRight();
	  break;
	case arcade::CommandType::WHERE_AM_I :
	  snake.whereAmI();
	  break;
	case arcade::CommandType::GET_MAP :
	  snake.getMap();
	  break;
	case arcade::CommandType::PLAY :
	  snake.updateGame();
	  break;
	default:
	  break;
	}
    }
}
