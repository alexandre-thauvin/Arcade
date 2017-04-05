/* ************************************************************************** *
 *   Map.hpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 04/04/17                               #+#     #+#  #+#         *
 *   Updated: 04/04/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef CPP_ARCADE_MAP_HPP
#define CPP_ARCADE_MAP_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.hpp"

namespace arcade {
    class Map {
    public:
        enum CaseMap {
            Error = -1,
            Empty,
            Block,
            Player,
            Object
        };
        Map(Vector2u const &dim);
        ~Map();
        Map(arcade::Map const &other);
        Map &operator=(Map const &other);
        void create();
        void clear();
        CaseMap getPosBlock(Vector2u const &pos) const;
        void setPosBlock(Vector2u const &pos, CaseMap casemap);
        void createObject(Vector2u const&);

        CaseMap **getMap() const;
        Vector2u getMapSize() const;
    private:
        Vector2u    _dim;
        CaseMap     **_map;
    };
}

#endif //CPP_ARCADE_MAP_HPP
