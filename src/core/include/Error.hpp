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
# define CPP_ARCADE_ERROR_HPP

# include <sstream>
# include <string>
# include <exception>

# define INFO __FUNCTION__,__FILE__,__LINE__
# define ERROR(error, msg) {std::ostringstream oss; oss << msg; throw( error(os.str(), INFO));}

namespace arcade {
    class Error : public std::exception {
    public:
        Error(std::string const &desc, std::string const &func,
              std::string const &file, int const line) :
                _desc(desc), _func(func), _file(file), _line(line) {}

        virtual             ~Error(void) throw() {}

        std::string what(void) {
          std::ostringstream msg;

          msg << _desc << "(" << _func << " at " << _file << ": " << _line
              << ")";
          return (msg.str());
        }

    protected:
        std::string _desc;
        std::string _func;
        std::string _file;
        int         _line;
    };
}

#endif //CPP_ARCADE_ERROR_HPP
