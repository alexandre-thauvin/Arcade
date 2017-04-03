//
// libSDL.hpp for  in /home/cedric/workTek2/cpp_arcade/src/core/include
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Wed Mar 29 14:20:27 2017 Cedric
// Last update Mon Apr  3 13:53:43 2017 Cedric
//

#ifndef LIBSDL_HPP_
# define LIBSDL_HPP_

# include <vector>
# include <map>
# include <SDL2/SDL.h>

# include "IGFX.hpp"

namespace                       arcade
{
  class                         GfxSDL : public IGFX {
    public:
                                GfxSDL(Vector2u const& dim);
      virtual                   ~GfxSDL(void);
      virtual InputT            getInput(void);
      virtual void              setTitleWindow(std::string const &title);
      virtual void              setWindowSize(Vector2u const &dim);
      virtual bool              isOpen(void) const;
      virtual void              close(void);
      virtual void              clear(void);
      virtual void              draw(DrawObject const &drawObject);
      virtual void              display(void);
    private:
      std::map<int, InputT>     _input;
      bool			            _isOpen;
      SDL_Window*		        _mainWindow;
      SDL_Renderer*		        _renderer;
      Vector2u                  _mainSize;
    };
}

#endif /* !LIBSDL_HPP_ */
