//
// libSDL.hpp for  in /home/cedric/workTek2/cpp_arcade/src/core/include
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Wed Mar 29 14:20:27 2017 Cedric
// Last update Thu Mar 30 18:37:25 2017 Cedric
//

#ifndef LIBSDL_HPP_
# define LIBSDL_HPP_

# include <vector>
# include <map>
# include <SDL2/SDL.h>
# include <iostream>
# include "IGFX.hpp"

namespace                       arcade
{
  class                         GfxSDL : public IGFX {
    public:
                                GfxSDL(void);
      virtual                   ~GfxSDL(void);
      virtual InputT            getInput(void);
      virtual void              setTitleWindow(std::string const &title);
      virtual void              setWindowSize(Vector2u const &size);
      virtual bool              isOpen(void) const;
      virtual void              close(void);
      virtual void              clear(void);
      // virtual void           draw(DrawObject const& drawObject);
      virtual void              display(void);
    private:
      std::map<int, InputT>     _input;
      bool			_isOpen;
      SDL_Window*		_mainWindow;
      SDL_Renderer*		_renderer;
      int			_mainSizeX;
      int			_mainSizeY;
    };
}

#endif /* !LIBSDL_HPP_ */
