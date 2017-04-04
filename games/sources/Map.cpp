/* ************************************************************************** *
 *   Map.cpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 04/04/17                               #+#     #+#  #+#         *
 *   Updated: 04/04/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#include "Utils.hpp"

arcade::Map::Map(Vector2u const &dim) {
  _map = new Block*[dim.y];
  for (int i =0; i < dim.y;++i) {
    _map[i] = new Block[dim.x];
  }
  create();
}

arcade::Map::~Map() {
  for (int i = 0; i < _dim.y; ++i) {
    delete _map[i];
  }
  delete _map;
}

void arcade::Map::create() {
  Vector2i tmp;

  for (tmp.y = 0; tmp.y < _dim.y; ++tmp.y){
    for (tmp.x = 0; tmp.x < _dim.x; ++tmp.x) {
      if (tmp.x == 0 || tmp.y == 0 || tmp.y == _dim.y-1 || tmp.x == _dim.x-1)
        _map[tmp.y][tmp.x] = BLOCK;
      else
        _map[tmp.y][tmp.x] = EMPTY;
    }
  }
}

aracde::Map::CaseMap arcade::Map::getBlockPos(Vector2u const& pos) const {
  return _map[pos.y][pos.x]; //TODO: ERROR CHECK
}

void arcade::Map::setBlockPos(Vector2u const& pos, Block block) {
  _map[pos.y][pos.x] = block;
}

arcade::Vector2u aracde::Map::getMapSize() const {
  return _dim;
}

void arcade::Map::createObject() {

}