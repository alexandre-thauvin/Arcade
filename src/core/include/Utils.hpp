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

# include <cmath>
# include <cstring>
# include <ostream>

namespace arcade {
    template<class T>
    class Vector2 {
    public:
        union {
            T x;
            T s;
        };

        union {
            T y;
            T t;
        };

        Vector2() : x(0), y(0) {}

        Vector2(T nx, T ny) : x(nx), y(ny) {
        }

        Vector2(const Vector2<T> &src) : x(src.x), y(src.y) {
        }

        template<class FromT>
        Vector2(const Vector2<FromT> &src): x(static_cast<T>(src.x)), y(static_cast<T>(src.y)) {
        }

        template<class FromT>
        Vector2<T> &operator=(const Vector2<FromT> &rhs) {
          x = static_cast<T>(rhs.x);
          y = static_cast<T>(rhs.y);
          return *this;
        }

        Vector2<T> &operator=(const Vector2<T> &rhs) {
          x = rhs.x;
          y = rhs.y;
          return *this;
        }

        Vector2<T> operator+(const Vector2<T> &rhs) const {
          return Vector2<T>(x + rhs.x, y + rhs.y);
        }

        Vector2<T> operator-(const Vector2<T> &rhs) const {
          return Vector2<T>(x - rhs.x, y - rhs.y);
        }

        Vector2<T> operator*(const Vector2<T> &rhs) const {
          return Vector2<T>(x * rhs.x, y * rhs.y);
        }

        Vector2<T> operator/(const Vector2<T> &rhs) const {
          return Vector2<T>(x / rhs.x, y / rhs.y);
        }

        Vector2<T> &operator+=(const Vector2<T> &rhs) {
          x += rhs.x;
          y += rhs.y;
          return *this;
        }

        Vector2<T> &operator-=(const Vector2<T> &rhs) {
          x -= rhs.x;
          y -= rhs.y;
          return *this;
        }

        Vector2<T> &operator*=(const Vector2<T> &rhs) {
          x *= rhs.x;
          y *= rhs.y;
          return *this;
        }

        Vector2<T> &operator/=(const Vector2<T> &rhs) {
          x /= rhs.x;
          y /= rhs.y;
          return *this;
        }

        Vector2<T> operator+(T rhs) const {
          return Vector2<T>(x + rhs, y + rhs);
        }

        Vector2<T> operator-(T rhs) const {
          return Vector2<T>(x - rhs, y - rhs);
        }

        Vector2<T> operator*(T rhs) const {
          return Vector2<T>(x * rhs, y * rhs);
        }

        Vector2<T> operator/(T rhs) const {
          return Vector2<T>(x / rhs, y / rhs);
        }

        Vector2<T> &operator+=(T rhs) {
          x += rhs;
          y += rhs;
          return *this;
        }

        Vector2<T> &operator-=(T rhs) {
          x -= rhs;
          y -= rhs;
          return *this;
        }

        Vector2<T> &operator*=(T rhs) {
          x *= rhs;
          y *= rhs;
          return *this;
        }

        Vector2<T> &operator/=(T rhs) {
          x /= rhs;
          y /= rhs;
          return *this;
        }

        bool operator!=(const Vector2<T> &rhs) const {
          return !(*this == rhs);
        }

        Vector2<T> operator-() const {
          return Vector2<T>(-x, -y);
        }

        T length() const {
          return (T) std::sqrt(x * x + y * y);
        }

        operator T *() {
          return (T *) this;
        }

        operator const T *() const {
          return (const T *) this;
        }

        friend std::ostream &
        operator<<(std::ostream &lhs, const Vector2<T> &rhs) {
          lhs << "(" << rhs.x << ", " << rhs.y << ")";
          return lhs;
        }

    };

    typedef class Vector2<float>        Vector2f;
    typedef class Vector2<double>       Vector2d;
    typedef class Vector2<unsigned int> Vector2u;
    typedef class Vector2<int>          Vector2i;
}
#endif //CPP_ARCADE_UTILS_HPP
