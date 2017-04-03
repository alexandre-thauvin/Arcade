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

#define SIZE_X 400
#define SIZE_Y 600

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
  _gfxlib[OPENGL] = "./lib/lib_arcade_opengl.so";
  _gfxlib[NCURSES] = "./lib/lib_arcade_ncurses.so";

  _gamelib[SNAKE] = "games/lib_arcade_snake.so";
  _gamelib[CENTIPED] = "games/lib_arcade_snake.so";
  _gfx = NULL;
  _game = NULL;
  _gameId = 0;
  _libId = 0;
  _menuId = 0;
}

arcade::Core::~Core(void) {}

void arcade::Core::init(std::string const &lib, std::string const &conf)
{
  (void) lib;
  (void) conf;
  try {
    signal(SIGINT, arcade_ragequit);
    for (std::map<int, std::string>::iterator it = _gfxlib.begin(); it != _gfxlib.end(); ++it )
      if (it->second == lib) {
        _libId = it->first;
        loadGfx(_libId);
      }
    if (_gfx == NULL)
      throw Error("Error: I can't Load GFX Library: ", lib, "", 0);
  } catch (Error &e) {
    throw (e);
  }
}

bool                    arcade::Core::play(void)
{
    arcade::InputT       input;
    int i = 0;

    (void)input;
    while (true)
    {
        input = _gfx->getInput();
        if(_input.find(input) != _input.end()) {
            _input[input]();
        }
        _gfx->clear();
        switch (_state) {
          case MenuState:
            menu();
            break;
          case PlayState:
            _game->updateGame(i++);
            break;
          default:
            break;
        }
        _gfx->display();
        usleep(MAIN_SLEEP);
    }
    return (true);
}

void                    arcade::Core::menu(void)
{
  arcade::DrawObject    a;
  arcade::Vector2i      pos;

  switch (_libId) {
    case 0:
      a.setColor(arcade::Color((unsigned char) 238, (unsigned char) 110,
                               (unsigned char) 115));
      for (int i = 0; i <= GameSize; ++i) {
        a.setText(_gamelib[i]);
        a.setSize(Vector2u(SIZE_X - ((_menuId == i) ? 100 : 140), 75));
        a.setPosition(Vector2i((_menuId == i) ? 30 : 50,
                               SIZE_Y - (50 + (100 * (i + 1)))));
        _gfx->draw(a);

      }
        break;
    case 1:
      for (int i = 0; i <= GameSize; ++i) {
        a.setText(_gamelib[i]);
//        a.setSize(Vector2u(SIZE_X - ((_menuId == i) ? 100 : 140), 75));
        a.setPosition(Vector2i(1, i));
        _gfx->draw(a);
      }
      break;
  }
}

void                    arcade::Core::goUp(void)
{
    std::cout << "Up!" << std::endl;
  if (_state == MenuState)
    _menuId = (++_menuId > GameSize) ? 0 : _menuId;
}

void                    arcade::Core::goDown(void)
{
    std::cout << "Down!" << std::endl;
  if (_state == MenuState)
    _menuId = (--_menuId < 0) ? GameSize : _menuId;
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
  switch (_state) {
    case MenuState:
      arcade_ragequit(0);
      break;
    case PlayState:
//      _gfx->setWindowSize(Vector2u(SIZE_X, SIZE_Y));
      _state = MenuState;
      break;
    default:
      break;
  }
}

void                    arcade::Core::goEnter(void)
{
    std::cout << "Enter!" << std::endl;
  switch (_state) {
    case MenuState:
      loadGame(_menuId);
      _state = GameState::PlayState;
      _game->play();
      _gfx->setWindowSize(_game->getDimension());
      break;
    case PlayState:
//      _game->shoot;
      break;
    default:
      break;
  }
}

void                    arcade::Core::goShoot(void)
{
    std::cout << "Shoot!" << std::endl;
}


void                    arcade::Core::loadGfx(int id)
{
  std::cout << "LoadGfx: " << _gfxlib[id%GfxSize] << std::endl;
  Loader<IGFX> *gfx_loader = new Loader<IGFX>(_gfxlib[id%GfxSize]);
  _gfx = gfx_loader->getInstance("createLib", Vector2u(SIZE_X, SIZE_Y));
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
