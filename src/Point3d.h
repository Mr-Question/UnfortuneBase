// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

struct Point3d
{
  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  Point3d (const double theX, const double theY, const double theZ)
    : Data {theX, theY, theZ}
  {
  }

  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  Point3d (const Point thePoint, const double theElevation)
    : Height {thePoint, theElevation}
  {
  }

  // =======================================================================
  // function : Dot
  // purpose  :
  // =======================================================================
  double Dot (const Point3d& theOther) const
  {
    return Height.Point2d.Dot (theOther.Height.Point2d) +
           Height.Elevation * theOther.Height.Elevation;
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
  Point3d Cross (const Point3d& theOther) const
  {
    Point3d aPoint (Coord.Y * theOther.Coord.Z - Coord.Z * theOther.Coord.Y,
                    Coord.Z * theOther.Coord.X - Coord.X * theOther.Coord.Z,
                    Coord.X * theOther.Coord.Y - Coord.Y * theOther.Coord.X);
    return aPoint;
  }

  // =======================================================================
  // function : operator-
  // purpose  :
  // =======================================================================
  Point3d operator-(const Point3d& thePoint) const
  {
    Point3d aPoint = *this;
    aPoint.Height.Point2d   -= thePoint.Height.Point2d;
    aPoint.Height.Elevation -= thePoint.Height.Elevation;
    return aPoint;
  }

  // =======================================================================
  // function : operator+
  // purpose  :
  // =======================================================================
  Point3d operator+(const Point3d& thePoint) const
  {
    Point3d aPoint = *this;
    aPoint.Height.Point2d   += thePoint.Height.Point2d;
    aPoint.Height.Elevation += thePoint.Height.Elevation;
    return aPoint;
  }

  // =======================================================================
  // function : operator/
  // purpose  :
  // =======================================================================
  Point3d operator/(const double theScale) const
  {
    Point3d aPoint = *this;
    aPoint.Height.Point2d   /= theScale;
    aPoint.Height.Elevation /= theScale;
    return aPoint;
  }

  // =======================================================================
  // function : operator*
  // purpose  :
  // =======================================================================
  Point3d operator*(const double theScale) const
  {
    Point3d aPoint = *this;
    aPoint.Height.Point2d   *= theScale;
    aPoint.Height.Elevation *= theScale;
    return aPoint;
  }

  // =======================================================================
  // function : operator-
  // purpose  :
  // =======================================================================
  Point3d operator-() const
  {
    Point3d aPoint = *this;
    aPoint.Height.Point2d   = -aPoint.Height.Point2d;
    aPoint.Height.Elevation = -aPoint.Height.Elevation;
    return aPoint;
  }

  union
  {
    struct
    {
      double X;
      double Y;
      double Z;
    } Coord;

    struct
    {
      Point  Point2d;
      double Elevation;
    } Height;

    double Data[3];
  };
};
