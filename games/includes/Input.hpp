/* ************************************************************************** *
 *   Input.hpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 23/03/17                               #+#     #+#  #+#         *
 *   Updated: 23/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef CPP_ARCADE_INPUT_HPP
#define CPP_ARCADE_INPUT_HPP
# include <iostream>
# include <string>

namespace                   arcade
{
    struct                  InputT
    {
        static const int    None = 0;
        static const int    KeyPressed = 1;
        static const int    KeyReleased = 2;
        static const int    TextEntered = 3;
        InputT(void)
        {
          type = None;
          key = None;
          unicode = None;
        }
        InputT(int const type, int const key, int const unicode)
        {
          this->type = type;
          this->key = key;
          this->unicode = unicode;
        }
        ~InputT(void) {}
        int                 type;
        int                 key;
        int                 unicode;
    };

    enum                    Input
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ESCAPE,
    };
}

namespace                   std
{
    template<>
    class                   less<arcade::InputT>
    {
    public:
        bool operator()(arcade::InputT const& lhs, arcade::InputT const& rhs)
        {
          if (lhs.type != rhs.type)
            return (lhs.type < rhs.type);
          return (lhs.key < rhs.key);
        }
    };
}

#endif //CPP_ARCADE_INPUT_HPP
