/* ************************************************************************** *
 *   core.h
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */


#ifndef _CORE_HPP_
# define _CORE_HPP_

# include <iostream>
# include <string>
# include <map>
# include <functional>
# include <signal.h>

# include "Protocol.hpp"
# include "Utils.hpp"
# include "Input.hpp"
# include "Error.hpp"

enum                          GameState {
  PlayState = 0,
  MenuState = 1,
  Pause = 2
};

namespace                       arcade {
  class                         Core {
    public:
                                Core(void);
                                ~Core(void);
      void                      init(std::string const &lib, std::string const &conf);
      bool                      play(void);
      void                      initLibGraphic(std::string const &lib);
      void                      initLibGames(std::string const &lib);
    private:

        std::map<InputT, std::function<void(void)> > _input;
       GameState                _state;
    };

}

void                            arcade_ragequit(int n);

#endif /* !_CORE_HPP_ */
