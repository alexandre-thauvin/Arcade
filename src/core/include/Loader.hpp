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
class               Loader {
    std::string     _path;
    void            *_handler;
public:
    Loader(std::string const &path) {
      _path    = path;
      _handler = dlopen(_path.c_str(), RTLD_NOW | RTLD_GLOBAL);
      if (_handler == NULL) {
        std::string error = "Error: ";
        error += dlerror();
//        std::cout << "ERREUR : " << error << std::endl;
        throw arcade::ArcadeError(error);
      }
    }

    ~Loader() {
      if (dlclose(_handler) != 0) {
        std::string error = "oki";
        throw arcade::ArcadeError("Error: Handler failed!");
      }
    }

    T *getInstance(std::string entry_point, int width = 20, int height = 20) {
      T * (*ptr)(int, int);
      ptr = reinterpret_cast<T *(*)(int, int)>(dlsym(_handler,
                                                     entry_point.c_str()));
      if (ptr == NULL)
        return (NULL);
      return (ptr(width, height));
    }

};

#endif //CPP_ARCADE_LOADER_HPP
