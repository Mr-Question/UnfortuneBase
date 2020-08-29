// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

#include <Point.h>

#include <algorithm>

struct BndBox
{
  union
  {
    struct
    {
      Point Min;
      Point Max;
    } Corners;

    Point Data[2];
  };

  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  BndBox()
    : Corners {Point{std::numeric_limits<double>::max   (), std::numeric_limits<double>::max   ()},
               Point{std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest()}}
  {
  }

  // =======================================================================
  // function : AddPoint
  // purpose  :
  // =======================================================================
  void AddPoint (const Point& thePoint)
  {
    for (int i = 0; i < 2; ++i)
    {
      Corners.Min.Data[i] = std::min (Corners.Min.Data[i], thePoint.Data[i]);
      Corners.Max.Data[i] = std::max (Corners.Max.Data[i], thePoint.Data[i]);
    }
  }

  // =======================================================================
  // function : AddBox
  // purpose  :
  // =======================================================================
  void AddBox (const BndBox& theBox)
  {
    AddPoint (theBox.Corners.Min);
    AddPoint (theBox.Corners.Max);
  }

  // =======================================================================
  // function : Center
  // purpose  :
  // =======================================================================
  Point Center() const
  {
    return (Data[0] + Data[1]) / 2.;
  }

  // =======================================================================
  // function : operator-=
  // purpose  :
  // =======================================================================
  BndBox& operator-=(const Point& thePoint)
  {
    Corners.Min -= thePoint;
    Corners.Max -= thePoint;
    return *this;
  }

  // =======================================================================
  // function : operator+=
  // purpose  :
  // =======================================================================
  BndBox& operator+=(const Point& thePoint)
  {
    Corners.Min += thePoint;
    Corners.Max += thePoint;
    return *this;
  }

  // =======================================================================
  // function : operator-
  // purpose  :
  // =======================================================================
  BndBox operator-(const Point& thePoint) const
  {
    BndBox aBox = *this;
    aBox -= thePoint;
    return aBox;
  }

  // =======================================================================
  // function : operator+
  // purpose  :
  // =======================================================================
  BndBox operator+(const Point& thePoint) const
  {
    BndBox aBox = *this;
    aBox += thePoint;
    return aBox;
  }
};
