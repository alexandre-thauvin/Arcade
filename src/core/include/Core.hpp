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

namespace                       arcade {
    enum                        GameState {
        PlayState = 0,
        MenuState,
        Pause
    };
    enum                        Game
    {
        SNAKE = 0,
        CENTIPED = 1,
        GameSize = 2
    };

    enum                        Gfx
    {
        SDL = 0,
        NCURSES = 1,
        OPENGL = 2,
        GfxSize = 3
    };
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
      void                      loadGfx(int id);
      void                      loadGame(int id);
      void                      loadNextGame(void);
      void                      loadPrevGame(void);
    private:
      std::map<InputT, std::function<void(void)>> _input;
      std::map<int, std::string> _gfxlib;
      std::map<int, std::string> _gamelib;
      GameState                _state;
      IGFX                      *_gfx;
      IGames                    *_game;
      int                       _gameId;
      int                       _libId;
    };
}

void                            arcade_ragequit(int x);

#endif /* !_CORE_HPP_ */
