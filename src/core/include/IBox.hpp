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

# include "IGFX.hpp"

namespace arcade {
    class                 Color {
    public:
        unsigned char     red_, green_, blue_, alpha_;

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

        unsigned char     &getRed() { return red_; }
        unsigned char     &getGreen() { return green_; }
        unsigned char     &getBlue() { return blue_; }
        unsigned char     &getAlpha() { return alpha_; }
        const unsigned char &getRed() const { return red_; }
        const unsigned char &getGreen() const { return green_; }
        const unsigned char &getBlue() const { return blue_; }
        const unsigned char &getAlpha() const { return alpha_; }
        void              setFRed(float val) { red_ = val * 255.0 + .5; }
        void              setFGreen(float val) { green_ = val * 255.0 + .5; }
        void              setFblue(float val) { blue_ = val * 255.0 + .5; }
        void              setFAlpha(float val) { alpha_ = val * 255.0 + .5; }
        float             getFRed() const { return red_ / 255.0; }
        float             getFGreen() const { return green_ / 255.0; }
        float             getFblue() const { return blue_ / 255.0; }
        float             getFAlpha() const { return alpha_ / 255.0; }
        unsigned int      rgba() {
          return (red_ << 24) | (green_ << 16) | (blue_ << 8) | (alpha_ << 0);
        }
    };

    class IBox {
    public:
        virtual             ~IBox(void) {}

        virtual void draw(IGFX *&graphic, bool const bright) = 0;
        virtual void setPosition(Vector2u const &pos) = 0;
        virtual void setSize(Vector2u const &size) = 0;
        virtual void setCharacterSize(size_t const size) = 0;
        virtual void setText(std::string const &text) = 0;
        virtual void setColor(Color const &rgba) = 0;

        virtual Vector2u getPosition(void) const = 0;
        virtual Vector2u getRPosition(void) const = 0;
        virtual Vector2u getSize(void) const = 0;
        virtual size_t getCharacterSize(void) const = 0;
        virtual std::string getText(void) const = 0;
        virtual Color getColor(void) const = 0;

        virtual bool isClickable(void) const = 0;
        virtual void setClickable(bool const value) = 0;
        virtual bool isSelectable(void) const = 0;
        virtual void setSelectable(bool const value) = 0;
    };
}

#endif /* !_IBOX_HPP_ */
