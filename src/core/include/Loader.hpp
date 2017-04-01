/* ************************************************************************** *
 *   Loader.hpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 31/03/17                               #+#     #+#  #+#         *
 *   Updated: 31/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef CPP_ARCADE_LOADER_HPP
#define CPP_ARCADE_LOADER_HPP

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "Error.hpp"

template<typename T>
class Loader {
    std::string _path;
    void        *_handler;
public:
    Loader(std::string const &path) {
      _path    = path;
      _handler = dlopen(_path.c_str(), RTLD_NOW | RTLD_GLOBAL);
      if (_handler == NULL) {
        std::string error = dlerror();
        throw arcade::Error(error, INFO);
      }
    }

    ~Loader() {
      if (dlclose(_handler) != 0) {
        throw arcade::Error("Error: dlclose", INFO);
      }
    }

    T *getInstance(std::string entry_point,
                   arcade::Vector2u dim = arcade::Vector2u(20, 20)) {
      T *(*ptr)(arcade::Vector2u);
      ptr = reinterpret_cast<T *(*)(arcade::Vector2u)>(dlsym(_handler,
                                                             entry_point.c_str()));
      std::cout << ptr << std::endl;
      if (ptr == NULL) {
        return (NULL);
      }
      return (ptr(dim));
    }
};

#endif //CPP_ARCADE_LOADER_HPP
