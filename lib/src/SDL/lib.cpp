//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Thu Mar 30 19:24:14 2017 Cedric
//

#include "libSDL.hpp"

arcade::GfxSDL::GfxSDL() {
  SDL_Init(SDL_INIT_EVERYTHING);
  _input[SDLK_i] = InputT(InputT::KeyPressed, Input::PREV_LIB, InputT::None);
  _input[SDLK_p] = InputT(InputT::KeyPressed, Input::NEXT_LIB, InputT::None);
  _input[SDLK_k] = InputT(InputT::KeyPressed, Input::PREV_GAME, InputT::None);
  _input[SDLK_m] = InputT(InputT::KeyPressed, Input::NEXT_GAME, InputT::None);  
  _input[SDLK_KP_ENTER] = InputT(InputT::KeyPressed, Input::ENTER, InputT::None);
  _input[SDLK_KP_SPACE] = InputT(InputT::KeyPressed, Input::SPACE, InputT::None);
  _input[SDLK_ESCAPE] = InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None);
  _input[SDLK_DOWN] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[SDLK_LEFT] = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[SDLK_RIGHT] = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[SDLK_UP] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _input[SDLK_s] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[SDLK_q] = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[SDLK_d] = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[SDLK_z] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
}

arcade::GfxSDL::~GfxSDL() {
  SDL_Quit();
}

void	arcade::GfxSDL::setTitleWindow(std::string const &title) {
  SDL_SetWindowTitle(_mainWindow, title.c_str());
}

bool	arcade::GfxSDL::isOpen() const {
  return (_isOpen);
}

void	arcade::GfxSDL::clear() {
  SDL_RenderClear(_renderer);
}

arcade::InputT	arcade::GfxSDL::getInput() {
  
}

void	arcade::GfxSDL::display() {
  _mainSizeX = 600;
  _mainSizeY = 600;
  _isOpen = true;
  _mainWindow = SDL_CreateWindow("Main Window", 0, 0, _mainSizeX, _mainSizeY, 0);
  _renderer = SDL_CreateRenderer(_mainWindow, -1, 0);
  std::cin.ignore();
}
