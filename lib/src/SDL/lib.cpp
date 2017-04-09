//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
//
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
//
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Wed Apr  5 10:29:08 2017 Cedric
//

#include "libSDL.hpp"
#include "Input.hpp"

arcade::GfxSDL::GfxSDL(arcade::Vector2u const &dim) {
  SDL_Init(SDL_INIT_EVERYTHING);
  _input[SDLK_i]      = InputT(InputT::KeyPressed, Input::PREV_LIB,
                               InputT::None);
  _input[SDLK_p]      = InputT(InputT::KeyPressed, Input::NEXT_LIB,
                               InputT::None);
  _input[SDLK_k]      = InputT(InputT::KeyPressed, Input::PREV_GAME,
                               InputT::None);
  _input[SDLK_m]      = InputT(InputT::KeyPressed, Input::NEXT_GAME,
                               InputT::None);
  _input[SDLK_RETURN] = InputT(InputT::KeyPressed, Input::ENTER, InputT::None);
  _input[SDLK_SPACE]  = InputT(InputT::KeyPressed, Input::SPACE, InputT::None);
  _input[SDLK_ESCAPE] = InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None);
  _input[SDLK_DOWN]   = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[SDLK_LEFT]   = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[SDLK_RIGHT]  = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[SDLK_UP]     = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _input[SDLK_s]      = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[SDLK_q]      = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[SDLK_d]      = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[SDLK_z]      = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _mainSize   = dim;
  _isOpen     = true;
  _mainWindow = SDL_CreateWindow("Arcade", 300, 400, _mainSize.x, _mainSize.y,
                                 0);
  _renderer   = SDL_CreateRenderer(_mainWindow, -1, 0);
}

arcade::GfxSDL::~GfxSDL() {
  close();
}

void arcade::GfxSDL::setTitleWindow(std::string const &title) {
  SDL_SetWindowTitle(_mainWindow, title.c_str());
}

bool arcade::GfxSDL::isOpen() const {
  return (_isOpen);
}

void arcade::GfxSDL::clear() {
  SDL_RenderClear(_renderer);
}

void arcade::GfxSDL::close() {
  SDL_Quit();
}

arcade::InputT arcade::GfxSDL::getInput() {
  SDL_Event event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYUP)
    if (_input.find(event.key.keysym.sym) != _input.end())
      return (_input[event.key.keysym.sym]);
  return (InputT(InputT::None, Input::NONE, InputT::None));
}

void arcade::GfxSDL::display() {
  SDL_RenderPresent(_renderer);
}

void arcade::GfxSDL::setWindowSize(arcade::Vector2u const &dim) {
  SDL_SetWindowSize(_mainWindow, dim.x, dim.y);
}

void arcade::GfxSDL::draw(DrawObject const &obj) {
  arcade::Vector2i pos  = obj.getPosition();
  arcade::Vector2u size = obj.getSize();
  SDL_Surface      *a;
  SDL_Texture      *b;
  SDL_Rect         rect{pos.x, pos.y, (int) size.x, (int) size.y};

  SDL_SetRenderDrawColor(_renderer, (obj.getColor()).getRed(),
                         (obj.getColor()).getGreen(),
                         (obj.getColor()).getBlue(),
                         (obj.getColor()).getAlpha());
  SDL_RenderFillRect(_renderer, &rect);
  a = IMG_Load(obj.getText().c_str());
  b = SDL_CreateTextureFromSurface(_renderer, a);
  SDL_RenderCopy(_renderer, b, NULL, &rect);
  SDL_SetRenderDrawColor(_renderer, 40, 44, 52, 255);
}

extern "C" {
  arcade::IGFX *createLib(arcade::Vector2u dim) {
    return (new arcade::GfxSDL(dim));
  }
}
