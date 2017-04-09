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

static bool quit = true;

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
  _input.insert(std::make_pair(
          InputT(InputT::KeyPressed, Input::PREV_GAME, InputT::None),
          std::bind(&arcade::Core::loadPrevGame, this)));
  _input.insert(std::make_pair(
          InputT(InputT::KeyPressed, Input::NEXT_GAME, InputT::None),
          std::bind(&arcade::Core::loadNextGame, this)));

  _gfxlib[SDL]     = "./lib/lib_arcade_sdl.so";
  _gfxlib[NCURSES] = "./lib/lib_arcade_ncurses.so";
//  _gfxlib[LAPIN] = "./lib/lib_arcade_lapin.so";

  _gamelib[SNAKE]    = "games/lib_arcade_snake.so";
  _gamelib[CENTIPED] = "games/lib_arcade_centipede.so";

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
  (void) conf;
  try {
    signal(SIGINT, arcade_ragequit);
    if (lib.empty()) {
      loadGfx(_libId);
    } else {
      for (std::map<int, std::string>::iterator it = _gfxlib.begin(); it != _gfxlib.end(); ++it )
        if (it->second == lib) {
          loadGfx(it->first);
          _libId = it->first;
        }
    }
    if (_gfx == NULL)
      throw arcade::Error("Error: ", INFO);
    play();
  } catch (Error &e) {
    throw (e);
  }
}

bool arcade::Core::play(void) {
  arcade::InputT input;
  clock_t        t;

  t = clock();
  while (quit) {
    input = _gfx->getInput();
    if (_input.find(input) != _input.end()) {
      _input[input]();
    }
    if ((clock() - t) > 100000) {
      _gfx->clear();
      t = clock();
      switch (_state) {
        case MenuState:
          menu();
          break;
        case PlayState:
          if (!_game->updateGame()) {
            _state = MenuState;
            _gfx->setWindowSize(Vector2u(SIZE_X, SIZE_Y));
          }
          drawMap();
          break;
        case PauseState:
          drawMap();
          break;
      }
      _gfx->display();
    }
  }
  return true;
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
        case arcade::Map::Shoot:
          a.setColor(arcade::Color((unsigned char) 220, (unsigned char) 220,
                                   (unsigned char) 0));
          a.setText("|");
          break;
        case arcade::Map::Centi:
          a.setColor(arcade::Color((unsigned char) 255, (unsigned char) 0,
                                   (unsigned char) 190));
          a.setText("@");
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
        case 2:
          a.setSize(Vector2u(28, 28));
          a.setPosition(pos * 30);
          break;
      }
      _gfx->draw(a);
    }
  }
}

void arcade::Core::menu(void) {
  arcade::DrawObject a;
  arcade::Vector2i   pos;

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
      for (int i = -1; i < GameSize; ++i) {
        a.setSize(Vector2u(SIZE_X - ((_menuId == i) ? 1 : 2), 1));
        a.setPosition(Vector2i(5, 4 - (i + 1)));
        a.setText(
                (_menuId == i) ? std::string("[*]").append(!_gamelib[i].empty() ? _gamelib[i] : "Quitter") : std::string("[ ]").append(
                        !_gamelib[i].empty() ? _gamelib[i] : "Quitter"));
        _gfx->draw(a);
      }
      break;
    case 2:
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
      quit = false;
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
  switch (_state) {
    case MenuState:
      if (_menuId >= 0) {
        _gameId = _menuId;
        loadGame(_menuId);
        _state = GameState::PauseState;
        _gfx->setWindowSize(_game->getDimension() * 30);
        _gfx->setTitleWindow(_game->getGamesName());
      } else {
        quit = false;
      }
      break;
    case PlayState:
      _game->shoot();
      _state = GameState::PauseState;
      break;
    case PauseState:
      _state = GameState::PlayState;
      break;
  }
}

void arcade::Core::goShoot(void) {
  switch (_state) {
    case PlayState:
      _game->shoot();
      break;
    default:
      break;
  }
}


void arcade::Core::loadGfx(int id) {
  std::cout << "LoadGfx: " << _gfxlib[id] << std::endl;
  Loader <IGFX> *gfx_loader = new Loader<IGFX>(_gfxlib[id]);
  if (!(_gfx = gfx_loader->getInstance("createLib", Vector2u(SIZE_X, SIZE_Y))))
    throw arcade::Error("Error: ", INFO);
}

void arcade::Core::loadNextGfx(void) {
  _gfx->close();
  _libId = (++_libId > (GfxSize - 1)) ? 0 : _libId;
  loadGfx(_libId);
  if (_state != MenuState) {
    _state = PauseState;
    _gfx->setWindowSize(_game->getDimension() * 30);
  }
}

void arcade::Core::loadPrevGfx(void) {
  _gfx->close();
  if (_gfx)
    delete _gfx;
  _libId = (--_libId < 0) ? (GfxSize - 1) : _libId;
  loadGfx(_libId);
  if (_state != MenuState) {
    _state = PauseState;
    _gfx->setWindowSize(_game->getDimension() * 30);
  }
}

void arcade::Core::loadGame(int id) {
  std::cout << "LoadGame: " << _gamelib[id % GameSize] << std::endl;
  if (_game)
    delete _game;
  Loader <IGame> *game_loader = new Loader<IGame>(_gamelib[id % GameSize]);
  if ((_game = game_loader->getInstance("createGame", Vector2u(20, 20))) ==
      NULL)
    throw arcade::Error("Error: ", INFO);
  _map       = _game->getMap();
  _gfx->setTitleWindow(_game->getGamesName());
}

void arcade::Core::loadNextGame(void) {
  _gameId = (++_gameId > (GameSize - 1)) ? 0 : _gameId;
  _state = MenuState;
  _menuId = _gameId;
  goEnter();
}

void arcade::Core::loadPrevGame(void) {
  _gameId = (--_gameId < 0) ? (GameSize - 1) : _gameId;
  _state = MenuState;
  _menuId = _gameId;
  goEnter();
}

void arcade_ragequit(int x) {
  (void) x;
  std::cout << std::endl << "OMFG! Don't ragequit!" << std::endl;
  quit = false;
}
