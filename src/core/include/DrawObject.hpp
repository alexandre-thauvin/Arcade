//
// DrawObject.hpp for  in /home/aneopsy/cpp_arcade/src/core/include/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Wed Mar 29 17:48:48 2017 Paul THEIS
// Last update Wed Mar 29 18:46:39 2017 Paul THEIS
//

#ifndef _DRAWOBJECT_HPP_
# define _DRAWOBJECT_HPP_

# include <string>
# include <vector>

# include "IBox.hpp"

namespace                 arcade {
    class                 DrawObject : public IBox {
    private:
        Color             _rgba;
        Vector2i          _position;
        Vector2i          _r_position;
        Vector2u          _size;
        std::string       _text;
        size_t            _charactere_size;
        bool              _is_clickable;
        bool              _is_selectable;

    public:
                          DrawObject(void);
        virtual           ~DrawObject(void);
        virtual void      draw(IGFX *&graphic, bool const bright);
        virtual void      setPosition(Vector2i const &pos);
        virtual void      setSize(Vector2u const &size);
        virtual void      setCharacterSize(size_t const size);
        virtual void      setText(std::string const &text);
        virtual void      setColor(Color const &rgba);
        virtual Vector2i  getPosition(void) const;
        virtual Vector2i  getRPosition(void) const;
        virtual Vector2u  getSize(void) const;
        virtual size_t    getCharacterSize(void) const;
        virtual std::string getText(void) const;
        virtual Color     getColor(void) const;
        virtual bool      isClickable(void) const;
        virtual void      setClickable(bool const value);
        virtual bool      isSelectable(void) const;
        virtual void      setSelectable(bool const value);
    };
}

#endif /* !_DRAWOBJECT_HPP_ */
