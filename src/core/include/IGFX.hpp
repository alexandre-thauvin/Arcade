//
// IGFX.hpp for  in /home/aneopsy/cpp_arcade/src/core/include/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Tue Mar 28 16:38:42 2017 Paul THEIS
// Last update Wed Mar 29 18:46:09 2017 Paul THEIS
//

#ifndef _IGFX_HPP_
# define _IGFX_HPP_

# include <iostream>
# include <string>
# include <stdlib.h>

# include "Error.hpp"
# include "Input.hpp"
# include "Utils.hpp"
# include "DrawObject.hpp"

class DrawObject;
namespace                       arcade {
  class                         IGFX {
      public:
        virtual                 ~IGFX(void) {}

        virtual void            setTitleWindow(std::string const& title) = 0;
        virtual void            setWindowSize(Vector2u const &size) = 0;
        virtual bool            isOpen(void) const = 0;
        virtual void            close(void) = 0;

        virtual InputT          getInput(void) = 0;

        virtual void            clear(void) = 0;
         virtual void           draw(DrawObject const &drawObject) = 0;
        virtual void            display(void) = 0;
      };
}

#endif /* !_IGRAPHIC_HPP_ */
