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
#include <time.h>

#define SIZE_X 400
#define SIZE_Y 600

arcade::Core::Core(void) {
  _state = GameState::MenuState;
  _input.insert(std::make_pair(
          InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None),
          std::bind(&arcade::Core::goQuit, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::ENTER, InputT::None),
                         std::bind(&arcade::Core::goEnter, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::UP, InputT::None),
                         std::bind(&arcade::Core::goUp, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::DOWN, InputT::None),
                         std::bind(&arcade::Core::goDown, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::LEFT, InputT::None),
                         std::bind(&arcade::Core::goLeft, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::RIGHT, InputT::None),
                         std::bind(&arcade::Core::goRight, this)));
  _input.insert(
          std::make_pair(InputT(InputT::KeyPressed, Input::SPACE, InputT::None),
                         std::bind(&arcade::Core::goShoot, this)));
  _input.insert(std::make_pair(
          InputT(InputT::KeyPressed, Input::PREV_LIB, InputT::None),
          std::bind(&arcade::Core::loadPrevGfx, this)));
  _input.insert(std::make_pair(
          InputT(InputT::KeyPressed, Input::NEXT_LIB, InputT::None),
          std::bind(&arcade::Core::loadNextGfx, this)));

  _gfxlib[SDL]     = "./lib/lib_arcade_sdl.so";
//  _gfxlib[OPENGL]  = "./lib/lib_arcade_opengl.so";
  _gfxlib[NCURSES] = "./lib/lib_arcade_ncurses.so";

  _gamelib[SNAKE]    = "games/lib_arcade_snake.so";
  _gamelib[CENTIPED] = "games/lib_arcade_snake.so";

  _img[0]  = "assets/snake.png";
  _img[1]  = "assets/centipede.png";
  _img[-1] = "assets/quitter.png";
  _gfx    = NULL;
  _game   = NULL;
  _gameId = GameSize - 1;
  _libId  = 0;
  _menuId = 0;
}

arcade::Core::~Core(void) {
  if (_gfx)
    _gfx->close();
}

void arcade::Core::init(std::string const &lib, std::string const &conf) {
  (void) lib;
  (void) conf;
  try {
    signal(SIGINT, arcade_ragequit);
    if (lib.empty()) {
      loadGfx(_libId);
    } else {
      Loader <IGFX> *gfx_loader = new Loader<IGFX>(_gfxlib[_libId]);
      _gfx = gfx_loader->getInstance("createLib", Vector2u(SIZE_X, SIZE_Y));
    }
    if (_gfx == NULL)
      throw arcade::Error("Error: ", INFO);
  } catch (Error &e) {
    throw (e);
  }
}

bool arcade::Core::play(void) {
  arcade::InputT input;
  clock_t        t;

  t = clock();
  while (true) {
    input = _gfx->getInput();
    if (_input.find(input) != _input.end()) {
      _input[input]();
    }
    _gfx->clear();
    switch (_state) {
      case MenuState:
        menu();
        break;
      case PlayState:
        if ((clock() - t) > 100000) {
          t       = clock();
          if (!_game->updateGame()) {
            _state = MenuState;
            _gfx->setWindowSize(Vector2u(SIZE_X, SIZE_Y));
          }
        }
        drawMap();
        break;
      case PauseState:
        drawMap();
        break;
    }
    usleep(MAIN_SLEEP);
    _gfx->display();
  }
}

void arcade::Core::drawMap(void) {
  int                todraw;
  arcade::DrawObject a;
  Vector2u           dim = _map->getMapSize();
  Vector2u           pos;

  for (pos.y = 0; pos.y < dim.y; pos.y++) {
    for (pos.x = 0; pos.x < dim.x; pos.x++) {
      todraw = _map->getPosBlock(pos);
      switch (todraw) {
        case arcade::Map::Empty:
          a.setColor(arcade::Color((unsigned char) 60, (unsigned char) 66,
                                   (unsigned char) 78));
          a.setText(" ");
          break;
        case arcade::Map::Block:
          a.setColor(arcade::Color((unsigned char) 27, (unsigned char) 29,
                                   (unsigned char) 35));
          a.setText("#");
          break;
        case arcade::Map::Object:
          a.setColor(arcade::Color((unsigned char) 110, (unsigned char) 238,
                                   (unsigned char) 115));
          a.setText("X");
          break;
        case arcade::Map::Player:
          a.setColor(arcade::Color((unsigned char) 238, (unsigned char) 110,
                                   (unsigned char) 115));
          a.setText("O");
          break;
      }
      switch (_libId) {
        case 0:
          a.setSize(Vector2u(28, 28));
          a.setPosition(pos * 30);
          break;
        case 1:
          a.setSize(Vector2u(1, 1));
          a.setPosition(pos);
          break;
      }
      _gfx->draw(a);
    }
  }
}

void arcade::Core::menu(void) {
  arcade::DrawObject a;
  arcade::Vector2i   pos;
  std::string        selector("[ ]");

  switch (_libId) {
    case 0:
      a.setColor(arcade::Color((unsigned char) 238, (unsigned char) 110,
                               (unsigned char) 115));
      for (int i = -1; i < GameSize; ++i) {
        a.setText(_img[i]);
        a.setSize(Vector2u(SIZE_X - ((_menuId == i) ? 100 : 140), 75));
        a.setPosition(Vector2i((_menuId == i) ? 30 : 50,
                               SIZE_Y - (150 + (100 * (i + 1)))));
        _gfx->draw(a);
      }
      break;
    case 1:
      a.setSize(Vector2u(SIZE_X - 1, 1));
      a.setPosition(Vector2i(0, 0));
      _gfx->draw(a);
      for (int i = 0; i < GameSize; ++i) {
        a.setSize(Vector2u(SIZE_X - ((_menuId == i) ? 1 : 2), 1));
        a.setPosition(Vector2i(5, i + 1));
        a.setText((_menuId == i) ? selector.append(_gfxlib[i]) : selector.append(_gfxlib[i]));
        _gfx->draw(a);
      }
      break;
  }
}

void arcade::Core::goUp(void) {
  switch (_state) {
    case MenuState:
      _menuId = (++_menuId > GameSize - 1) ? -1 : _menuId;
      break;
    case PlayState:
      _game->goUp();
      break;
    default:
      break;
  }
}

void arcade::Core::goDown(void) {
  switch (_state) {
    case MenuState:
      _menuId = (--_menuId < -1) ? GameSize - 1 : _menuId;
      break;
    case PlayState:
      _game->goDown();
      break;
    default:
      break;
  }
}

void arcade::Core::goLeft(void) {
  switch (_state) {
    case MenuState:
      break;
    case PlayState:
      _game->goLeft();
      break;
    default:
      break;
  }
}

void arcade::Core::goRight(void) {
  switch (_state) {
    case MenuState:
      break;
    case PlayState:
      _game->goRight();
      break;
    default:
      break;
  }
}

void arcade::Core::goQuit(void) {
  switch (_state) {
    case MenuState:
      arcade_ragequit(0);
      break;
    case PlayState:
      _gfx->setWindowSize(Vector2u(SIZE_X, SIZE_Y));
      _state = MenuState;
      break;
    case PauseState:
      _gfx->setWindowSize(Vector2u(SIZE_X, SIZE_Y));
      _state = MenuState;
      break;
  }
}

void arcade::Core::goEnter(void) {
  std::cout << "Enter!" << std::endl;
  switch (_state) {
    case MenuState:
      if (_menuId >= 0) {
        loadGame(_menuId);
        _state = GameState::PauseState;
        _gfx->setWindowSize(_game->getDimension() * 30);
        _gfx->setTitleWindow(_game->getGamesName());
      } else {
        arcade_ragequit(0);
      }
      break;
    case PlayState:
//      _game->shoot;
      _state = GameState::PauseState;
      break;
    case PauseState:
      _state = GameState::PlayState;
      break;
  }
}

void arcade::Core::goShoot(void) {
  std::cout << "Shoot!" << std::endl;
}


void arcade::Core::loadGfx(int id) {
  std::cout << "LoadGfx: " << _gfxlib[id % GfxSize] << std::endl;
  if (_gfx)
    delete _gfx;
  Loader <IGFX> *gfx_loader = new Loader<IGFX>(_gfxlib[id % GfxSize]);
  _gfx = gfx_loader->getInstance("createLib", Vector2u(SIZE_X, SIZE_Y));
  if (_gfx == NULL)
    throw arcade::Error("Error: ", INFO);
}

void arcade::Core::loadNextGfx(void) {
  _gfx->close();
  _libId = (++_libId > (GfxSize - 1)) ? 0 : _libId;
  loadGfx(_libId);
  if (_libId == SDL)
    _gfx->setWindowSize(_game->getDimension() * 30);
  if (_state != MenuState)
    _state = PauseState;
}

void arcade::Core::loadPrevGfx(void) {
  _gfx->close();
  _libId = (--_libId < 0) ? (GfxSize - 1) : _libId;
  loadGfx(_libId);
  if (_libId == SDL)
    _gfx->setWindowSize(_game->getDimension() * 30);
  if (_state != MenuState)
    _state = PauseState;
}

void arcade::Core::loadGame(int id) {
  std::cout << "LoadGame: " << _gamelib[id % GameSize] << std::endl;
  if (_game)
    delete _game;
  Loader <IGame> *game_loader = new Loader<IGame>(_gamelib[id % GameSize]);
  _game = game_loader->getInstance("createGame", Vector2u(20, 20));
  if (_game == NULL)
    throw arcade::Error("Error: ", INFO);
  _map  = _game->getMap();
  _gfx->setTitleWindow(_game->getGamesName());
}

void arcade::Core::loadNextGame(void) {

}

void arcade::Core::loadPrevGame(void) {

}

void arcade_ragequit(int x) {
  (void) x;
  std::cout << std::endl << "OMFG! Don't ragequit!" << std::endl;
  std::cout << "exit" << std::endl;
  exit(1);
}
