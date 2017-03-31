/* ************************************************************************** *
 *   Error.hpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 28/03/17                               #+#     #+#  #+#         *
 *   Updated: 28/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef CPP_ARCADE_ERROR_HPP
#define CPP_ARCADE_ERROR_HPP

# include <iostream>
# include <string>
# include <exception>

namespace                     arcade {
    class                     ArcadeError : public std::exception {
      public:
                              ArcadeError(std::string const &msg) throw();
          virtual             ~ArcadeError(void) throw();
          virtual const char  *error(void) const throw();

      private:
          std::string         _msg;
    };
}

#endif //CPP_ARCADE_ERROR_HPP
