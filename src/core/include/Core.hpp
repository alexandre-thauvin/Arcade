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

# include "Input.hpp"
# include "Error.hpp"
# include "Protocol.hpp"
# include "Utils.hpp"
# include "IGFX.hpp"
# include "IGame.hpp"

# define MAIN_SLEEP 10

enum                            GameState {
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
      void                      goUp(void);
      void                      goDown(void);
      void                      goLeft(void);
      void                      goRight(void);
      void                      goQuit(void);
      void                      goEnter(void);
      void                      goShoot(void);
      void                      menu(void);
      void                      load(void);
    private:
      std::map<InputT, std::function<void(void)>> _input;
      std::map<std::string, std::string> _gfxlib;
      std::map<std::string, std::string> _gamelib;
      GameState                _state;
      IGFX                     *_gfx;
      IGames                   *_game;
    };
}

void                            arcade_ragequit(int x);

#endif /* !_CORE_HPP_ */
