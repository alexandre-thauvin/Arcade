//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
//
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
//
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Wed Apr  5 10:29:08 2017 Cedric
//

#include "libLAPIN.hpp"
#include "Input.hpp"

t_bunny_response my_loop(void *data) {
  (void) data;
  return (GO_ON);
}

void arcade::GfxLAPIN::setLastKey(char c) {
  this->_lastKey = c;
  std::cout << "key" <<std::endl;
}

t_bunny_response
my_keyevent(t_bunny_event_state state, t_bunny_keysym key, void *data) {
  arcade::GfxLAPIN *lapin = (arcade::GfxLAPIN *) data;

  if (state == 0x1)
    lapin->setLastKey(0x10);
  else {
    if (key >= BKS_A && key <= BKS_Z)
      lapin->setLastKey((char) key + 0x61);
    else
      lapin->setLastKey((char) key);
  }
  return (EXIT_ON_SUCCESS);
}

arcade::GfxLAPIN::GfxLAPIN(arcade::Vector2u const &dim) {
  _input['i']        = InputT(InputT::KeyPressed, Input::PREV_LIB,
                              InputT::None);
  _input['p']        = InputT(InputT::KeyPressed, Input::NEXT_LIB,
                              InputT::None);
  _input['k']        = InputT(InputT::KeyPressed, Input::PREV_GAME,
                              InputT::None);
  _input['m']        = InputT(InputT::KeyPressed, Input::NEXT_GAME,
                              InputT::None);
  _input[BKS_RETURN] = InputT(InputT::KeyPressed, Input::ENTER, InputT::None);
  _input[BKS_SPACE]  = InputT(InputT::KeyPressed, Input::SPACE, InputT::None);
  _input[BKS_ESCAPE] = InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None);
  _input['J']        = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input['G']        = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input['H']        = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input['I']        = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _input['s']        = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input['q']        = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input['d']        = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input['z']        = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _mainSize    = dim;
  _isOpen      = true;
  if ((_window = bunny_start_style(dim.x, dim.y, (t_bunny_window_style)(
          TITLEBAR | CLOSE_BUTTON), "Arcade")) != NULL) {
    bunny_display(_window);
    _screen = bunny_new_pixelarray(dim.x, dim.y);
  }
  bunny_set_loop_main_function(&my_loop);
  bunny_set_key_response(&my_keyevent);
}

arcade::GfxLAPIN::~GfxLAPIN() {
  close();
}

void arcade::GfxLAPIN::setTitleWindow(std::string const &title) {
  (void) title;
//  SDL_SetWindowTitle(_mainWindow, title.c_str());
}

bool arcade::GfxLAPIN::isOpen() const {
  return (_isOpen);
}

void arcade::GfxLAPIN::clear() {
  unsigned     *pixels = (unsigned *) this->_screen->pixels;
  unsigned int i       = 0;

  while (i < _mainSize.x * _mainSize.y) {
    pixels[i] = BLACK;
    ++i;
  }
  display();
}

void arcade::GfxLAPIN::close() {
  bunny_stop(_window);
  bunny_delete_clipable(&_screen->clipable);
}

arcade::InputT arcade::GfxLAPIN::getInput() {
  bunny_loop(_window, 100, (void *) this);
  if (_input.find(_lastKey) != _input.end()) {
    InputT in = _input[_lastKey];
    in.type    = InputT::KeyPressed;
    in.unicode = _lastKey;
    return (in);
  }
  return (InputT(InputT::None, Input::NONE, InputT::None));
}

void arcade::GfxLAPIN::display() {
  t_bunny_position position;

  position.x = 0;
  position.y = 0;
  bunny_blit(&_window->buffer, &_screen->clipable, &position);
  bunny_display(_window);
  std::cout << "display" <<std::endl;
}

void arcade::GfxLAPIN::setWindowSize(arcade::Vector2u const &dim) {
  t_bunny_size pos;
  pos.x = dim.x;
  pos.y = dim.y;
  bunny_resize_window(_window, pos);
}

void arcade::GfxLAPIN::draw(DrawObject const &obj) {
  unsigned         *pixels = (unsigned *) _screen->pixels;
  unsigned int     start;
  unsigned int     save;
  unsigned int     i;
  arcade::Vector2i pos     = obj.getPosition();
  arcade::Vector2u size    = obj.getSize();
  std::cout << "draw" <<std::endl;
  start = ((_mainSize.x * pos.y) + (pos.x));
  save  = start;
  while (start <= (save + (size.y * _mainSize.x))) {
    i = start;
    while (i < (start + size.x)) {
      pixels[i] = obj.getColor().rgba();
      ++i;
    }
    start += _mainSize.x;
  }
  display();
}

extern "C" {
arcade::IGFX *createLib(arcade::Vector2u dim) {
  return (new arcade::GfxLAPIN(dim));
}
}
