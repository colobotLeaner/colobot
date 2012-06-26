// * This file is part of the COLOBOT source code
// * Copyright (C) 2012, Polish Portal of Colobot (PPC)
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see    http://www.gnu.org/licenses/.

/** @defgroup MathPointModule math/point.h
     Contains the Point struct and related functions.
 */

#pragma once

#include "const.h"
#include "func.h"

#include <cmath>


// Math module namespace
namespace Math
{

/* @{ */ // start of group

/** \struct Point math/point.h
    \brief 2D point

    Represents a 2D point (x, y).
    Contains the required methods for operating on points.

    All methods are made inline to maximize optimization.

 */
struct Point
{
    //! X coord
    float x;
    //! Y coord
    float y;

    //! Constructs a zero point: (0,0)
    inline Point()
    {
        LoadZero();
    }

    //! Constructs a point from given coords: (x,y)
    inline explicit Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    //! Sets the zero point: (0,0)
    inline void LoadZero()
    {
        x = y = 0.0f;
    }

    //! Returns the distance from (0,0) to the point (x,y)
    inline float Length()
    {
        return sqrtf(x*x + y*y);
    }

        //! Returns the inverted point
    inline Point operator-() const
    {
        return Point(-x, -y);
    }

    //! Adds the given point
    inline const Point& operator+=(const Point &right)
    {
        x += right.x;
        y += right.y;
        return *this;
    }

    //! Adds two points
    inline friend const Point operator+(const Point &left, const Point &right)
    {
        return Point(left.x + right.x, left.y + right.y);
    }

    //! Subtracts the given vector
    inline const Point& operator-=(const Point &right)
    {
        x -= right.x;
        y -= right.y;
        return *this;
    }

    //! Subtracts two points
    inline friend const Point operator-(const Point &left, const Point &right)
    {
        return Point(left.x - right.x, left.y - right.y);
    }

    //! Multiplies by given scalar
    inline const Point& operator*=(const float &right)
    {
        x *= right;
        y *= right;
        return *this;
    }

    //! Multiplies point by scalar
    inline friend const Point operator*(const float &left, const Point &right)
    {
        return Point(left * right.x, left * right.y);
    }

    //! Multiplies point by scalar
    inline friend const Point operator*(const Point &left, const float &right)
    {
        return Point(left.x * right, left.y * right);
    }

    //! Divides by given scalar
    inline const Point& operator/=(const float &right)
    {
        x /= right;
        y /= right;
        return *this;
    }

    //! Divides point by scalar
    inline friend const Point operator/(const Point &left, const float &right)
    {
        return Point(left.x / right, left.y / right);
    }

}; // struct Point


//! Checks if two vectors are equal within given \a tolerance
inline bool PointsEqual(const Point &a, const Point &b, float tolerance = TOLERANCE)
{
    return IsEqual(a.x, b.x, tolerance) && IsEqual(a.y, b.y, tolerance);
}

//! Permutes two points
inline void Swap(Point &a, Point &b)
{
    Point c;

    c = a;
    a = b;
    b = c;
}

//! Returns the distance between two points
inline float Distance(const Point &a, const Point &b)
{
    return sqrtf((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

/* @} */ // end of group

}; // namespace Math
