// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

struct Point
{
  union
  {
    struct
    {
      double X;
      double Y;
    } Coord;

    double Data[2];
  };

  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  Point(const double theX = 0.0,
        const double theY = 0.0)
    : Coord {theX, theY}
  {
  }

  // =======================================================================
  // function : Dot
  // purpose  :
  // =======================================================================
  double Dot (const Point& theOther) const
  {
    return Coord.X * theOther.Coord.X + Coord.Y * theOther.Coord.Y;
  }

  // =======================================================================
  // function : SquareModulus
  // purpose  :
  // =======================================================================
  double SquareModulus () const
  {
    return this->Dot (*this);
  }

  // =======================================================================
  // function : Cross
  // purpose  :
  // =======================================================================
  double Cross (const Point& theOther) const
  {
    return Coord.X * theOther.Coord.Y - Coord.Y * theOther.Coord.X;
  }

  // =======================================================================
  // function : operator-=
  // purpose  :
  // =======================================================================
  Point& operator-=(const Point& thePoint)
  {
    Data[0] -= thePoint.Data[0];
    Data[1] -= thePoint.Data[1];
    return *this;
  }

  // =======================================================================
  // function : operator+=
  // purpose  :
  // =======================================================================
  Point& operator+=(const Point& thePoint)
  {
    Data[0] += thePoint.Data[0];
    Data[1] += thePoint.Data[1];
    return *this;
  }

  // =======================================================================
  // function : operator/=
  // purpose  :
  // =======================================================================
  Point& operator/=(const double theScale)
  {
    Data[0] /= theScale;
    Data[1] /= theScale;
    return *this;
  }

  // =======================================================================
  // function : operator-
  // purpose  :
  // =======================================================================
  Point operator-(const Point& thePoint) const
  {
    Point aPoint = *this;
    aPoint -= thePoint;
    return aPoint;
  }

  // =======================================================================
  // function : operator+
  // purpose  :
  // =======================================================================
  Point operator+(const Point& thePoint) const
  {
    Point aPoint = *this;
    aPoint += thePoint;
    return aPoint;
  }

  // =======================================================================
  // function : operator/
  // purpose  :
  // =======================================================================
  Point operator/(const double theScale) const
  {
    Point aPoint = *this;
    aPoint /= theScale;
    return aPoint;
  }

  // =======================================================================
  // function : operator-
  // purpose  :
  // =======================================================================
  Point operator-() const
  {
    Point aPoint {-Data[0], -Data[1]};
    return aPoint;
  }
};
