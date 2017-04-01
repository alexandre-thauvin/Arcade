/* ************************************************************************** *
 *   Core.cpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#include <unistd.h>

#include "Core.hpp"
#include "Loader.hpp"

arcade::Core::Core(void) {
  _state = GameState::MenuState;
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None), std::bind(&arcade::Core::goQuit, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::ENTER, InputT::None), std::bind(&arcade::Core::goEnter, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::UP, InputT::None), std::bind(&arcade::Core::goUp, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::DOWN, InputT::None), std::bind(&arcade::Core::goDown, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::LEFT, InputT::None), std::bind(&arcade::Core::goLeft, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::RIGHT, InputT::None), std::bind(&arcade::Core::goRight, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::SPACE, InputT::None), std::bind(&arcade::Core::goShoot, this)));

  _gfxlib[SDL] = "./lib/lib_arcade_sdl.so";
  _gfxlib[OPENGL] = "./lib/lib_arcade_ncurses.so";
  _gfxlib[NCURSES] = "./lib/lib_arcade_opengl.so";

  _gamelib[SNAKE] = "games/lib_arcade_snake.so";
  _gamelib[CENTIPED] = "games/centipede_path";
  _gfx = NULL;
  _game = NULL;
  _gameId = 0;
  _libId = 0;
}

arcade::Core::~Core(void) {}

void arcade::Core::init(std::string const &lib, std::string const &conf)
{
  (void) lib;
  (void) conf;
  try {
    signal(SIGINT, arcade_ragequit);
    for (std::map<int, std::string>::iterator it = _gfxlib.begin(); it != _gfxlib.end(); ++it )
      if (it->second == lib)
        loadGfx(it->first);
    if (_gfx == NULL)
      throw Error("Error: I can't Load GFX Library: ", lib, "", 0);
  } catch (Error &e) {
    throw (e);
  }
}

bool                    arcade::Core::play(void)
{
//    arcade::InputT       input;
//
//    (void)input;
//    while (true)
//    {
//        input = gfx.getInput();
//        if(_input.find(input) != _input.end()) {
//            _input[input]();
//        }
//        usleep(MAIN_SLEEP);
//    }
    return (true);
}

void                    arcade::Core::goUp(void)
{
    std::cout << "Up!" << std::endl;
}

void                    arcade::Core::goDown(void)
{
    std::cout << "Down!" << std::endl;
}

void                    arcade::Core::goLeft(void)
{
    std::cout << "Left!" << std::endl;
}

void                    arcade::Core::goRight(void)
{
    std::cout << "Right!" << std::endl;
}

void                    arcade::Core::goQuit(void)
{
    std::cout << "Quit!" << std::endl;
}

void                    arcade::Core::goEnter(void)
{
    std::cout << "Enter!" << std::endl;
}

void                    arcade::Core::goShoot(void)
{
    std::cout << "Shoot!" << std::endl;
}

void                    arcade::Core::menu(void)
{
  std::cout << "Menu" << std::endl;
}

void                    arcade::Core::loadGfx(int id)
{
  std::cout << "LoadGfx: " << _gfxlib[id%GfxSize] << std::endl;
  Loader<IGFX> *gfx_loader = new Loader<IGFX>(_gfxlib[id%GfxSize]);
  _gfx = gfx_loader->getInstance("createLib");
  if (_gfx == NULL)
    throw arcade::Error("Error: ", INFO);
}

void                    arcade::Core::loadGame(int id)
{
  std::cout << "LoadGame: " << _gamelib[id%GameSize] << std::endl;
  Loader<IGames> *game_loader = new Loader<IGames>(_gamelib[id%GameSize]);
  _game = game_loader->getInstance("createGame", Vector2u(20, 20));
  if (_game == NULL)
    throw arcade::Error("Error: ", INFO);
}

void                    arcade::Core::loadNextGame(void)
{

}

void                    arcade::Core::loadPrevGame(void)
{

}

void                    arcade_ragequit(int x)
{
  (void)x;
  std::cout << std::endl << "OMFG! Don't ragequit!" << std::endl;
  std::cout << "exit" << std::endl;
  exit(1);
}
