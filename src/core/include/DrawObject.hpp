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
        Vector2i          _position;
        Vector2i          _rotation;
        Vector2u          _size;
        std::string       _text;
        Color             _rgba;
        size_t            _charactere_size;
        std::string       _img;

    public:
                          DrawObject(void);
        virtual           ~DrawObject(void);
        virtual void      setPosition(Vector2i const &pos);
        virtual void      setRotation(Vector2i const &pos);
        virtual void      setSize(Vector2u const &size);
        virtual void      setCharacterSize(size_t const size);
        virtual void      setText(std::string const &text);
        virtual void      setColor(Color const &rgba);
        virtual Vector2i  getPosition(void) const;
        virtual Vector2i  getRotation(void) const;
        virtual Vector2u  getSize(void) const;
        virtual size_t    getCharacterSize(void) const;
        virtual std::string getText(void) const;
        virtual Color     getColor(void) const;
        virtual void      setImg(std::string const& path);
        virtual std::string getImg(void) const;
    };
}

#endif /* !_DRAWOBJECT_HPP_ */
