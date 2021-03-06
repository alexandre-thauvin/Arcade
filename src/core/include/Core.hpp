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
# include "Map.hpp"

# define MAIN_SLEEP 10000
# define SIZE_X 400
# define SIZE_Y 400

namespace                       arcade {
    enum                        GameState {
        PlayState = 0,
        MenuState,
        PauseState
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
        GfxSize = 2
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
      void                      drawMap(void);
      void                      menu(void);
      void                      loadGfx(int id);
      void                      loadGame(int id);
      void                      loadNextGame(void);
      void                      loadPrevGame(void);
      void                      loadNextGfx(void);
      void                      loadPrevGfx(void);
    private:
      std::map<InputT, std::function<void(void)>> _input;
      std::map<int, std::string> _gfxlib;
      std::map<int, std::string> _gamelib;
      std::map<int, std::string> _img;
      GameState                 _state;
      IGFX                      *_gfx;
      IGame                     *_game;
      const Map                 *_map;
      int                       _gameId;
      int                       _libId;
      int                       _menuId;
    };
}

void                            arcade_ragequit(int x);

#endif /* !_CORE_HPP_ */
