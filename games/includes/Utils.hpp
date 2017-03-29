/* ************************************************************************** *
 *   Utils.hpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef CPP_ARCADE_UTILS_HPP
#define CPP_ARCADE_UTILS_HPP
namespace arcade {
    typedef unsigned int const t_usi_c;
    typedef unsigned int t_usi;

    template<typename T>
    struct Vector2 {
        Vector2(void);
        Vector2(Vector2<T> const &other);
        Vector2(T const &_x, T const &_y);
        Vector2<T> &operator=(Vector2<T> const &other);

        T x;
        T y;
    };

    template<typename T>
    Vector2<T>::Vector2(void) {
      x = 0;
      y = 0;
    }

    template<typename T>
    Vector2<T>::Vector2(Vector2<T> const &other) {
      x = other.x;
      y = other.y;
    }

    template<typename T>
    Vector2<T>::Vector2(T const &_x, T const &_y) {
      x = _x;
      y = _y;
    }

    template<typename T>
    Vector2<T> &Vector2<T>::operator=(Vector2<T> const &other) {
      x = other.x;
      y = other.y;
      return (*this);
    }

    template<typename T>
    Vector2<T> operator*(Vector2<T> const &lhs, Vector2<T> const &rhs) {
      return (Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y));
    }

    template<typename T>
    bool operator==(Vector2<T> const &lhs, Vector2<T> const &rhs) {
      return (lhs.x == rhs.x && lhs.y == rhs.y);
    }

    template<typename T>
    bool operator!=(Vector2<T> const &lhs, Vector2<T> const &rhs) {
      return (lhs.x != rhs.x || lhs.y != rhs.y);
    }

    template < class T >
    std::ostream& operator << (std::ostream& os, Vector2<T> const &v)
    {
      os << "x: " << v.x;
      os << "\n";
      os << "y: " << v.y;
      return os;
    }

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<unsigned int> Vector2u;

}
#endif //CPP_ARCADE_UTILS_HPP
