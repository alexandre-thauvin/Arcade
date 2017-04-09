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
# include "Utils.hpp"

namespace arcade {

    class Color {
    public:
        unsigned char red_, green_, blue_, alpha_;

        Color()
                : red_(0), green_(0), blue_(0), alpha_(0xFF) {}

        Color(unsigned char red, unsigned char green, unsigned char blue,
              unsigned char alpha = 0xFF)
                : red_(red), green_(green), blue_(blue), alpha_(alpha) {}

        Color(float red, float green, float blue, float alpha = 1.0)
                : red_(red * 255.0 + .5), green_(green * 255.0 + .5),
                  blue_(blue * 255.0 + .5), alpha_(alpha * 255.0 + .5) {}

        Color(const Color &rhs)
                : red_(rhs.red_), green_(rhs.green_), blue_(rhs.blue_),
                  alpha_(rhs.alpha_) {}

        unsigned char &getRed() { return red_; }

        unsigned char &getGreen() { return green_; }

        unsigned char &getBlue() { return blue_; }

        unsigned char &getAlpha() { return alpha_; }

        const unsigned char &getRed() const { return red_; }

        const unsigned char &getGreen() const { return green_; }

        const unsigned char &getBlue() const { return blue_; }

        const unsigned char &getAlpha() const { return alpha_; }

        void setFRed(float val) { red_ = val * 255.0 + .5; }

        void setFGreen(float val) { green_ = val * 255.0 + .5; }

        void setFblue(float val) { blue_ = val * 255.0 + .5; }

        void setFAlpha(float val) { alpha_ = val * 255.0 + .5; }

        float getFRed() const { return red_ / 255.0; }

        float getFGreen() const { return green_ / 255.0; }

        float getFblue() const { return blue_ / 255.0; }

        float getFAlpha() const { return alpha_ / 255.0; }

        unsigned int rgba() {
          return (red_ << 24) | (green_ << 16) | (blue_ << 8) | (alpha_ << 0);
        }
    };

    class DrawObject {
    private:
        Vector2i    _position;
        Vector2i    _rotation;
        Vector2u    _size;
        std::string _text;
        Color       _rgba;
        size_t      _charactere_size;
        std::string _img;

    public:
        DrawObject(void);
        virtual           ~DrawObject(void);
        virtual void setPosition(Vector2i const &pos);
        virtual void setRotation(Vector2i const &pos);
        virtual void setSize(Vector2u const &size);
        virtual void setCharacterSize(size_t const size);
        virtual void setText(std::string const &text);
        virtual void setColor(Color const &rgba);
        virtual Vector2i getPosition(void) const;
        virtual Vector2i getRotation(void) const;
        virtual Vector2u getSize(void) const;
        virtual size_t getCharacterSize(void) const;
        virtual std::string getText(void) const;
        virtual Color getColor(void) const;
        virtual void setImg(std::string const &path);
        virtual std::string getImg(void) const;
    };
}

#endif /* !_DRAWOBJECT_HPP_ */
