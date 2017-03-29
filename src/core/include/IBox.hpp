//
// IBox.hpp for  in /home/aneopsy/cpp_arcade/src/core/include/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Tue Mar 28 16:38:57 2017 Paul THEIS
// Last update Wed Mar 29 18:46:05 2017 Paul THEIS
//

#ifndef _IBOX_HPP_
# define _IBOX_HPP_

# include <iostream>
# include <string>

# include "Error.hpp"
# include "Input.hpp"

// # include "IGFX.hpp"

namespace                   arcade {
  class                     IBox {
      public:
        virtual             ~IBox(void) {}
        // virtual void        draw(IGFX *&graphic, bool const bright) = 0;
        virtual void        setPosition(Vector2u const& pos) = 0;
        virtual void        setSize(Vector2u const& size) = 0;
        virtual void        setCharacterSize(size_t const size) = 0;
        virtual void        setText(std::string const& text) = 0;
        // virtual void        setColor(Color const& rgba) = 0;

        virtual Vector2u    getPosition(void) const = 0;
        virtual Vector2u    getRPosition(void) const = 0;
        virtual Vector2u    getSize(void) const = 0;
        virtual size_t      getCharacterSize(void) const = 0;
        virtual std::string getText(void) const = 0;
        // virtual Color       getColor(void) const = 0;

        virtual bool        isClickable(void) const = 0;
        virtual void        setClickable(bool const value) = 0;
        virtual bool        isSelectable(void) const = 0;
        virtual void        setSelectable(bool const value) = 0;
      };
}

#endif /* !_IBOX_HPP_ */
