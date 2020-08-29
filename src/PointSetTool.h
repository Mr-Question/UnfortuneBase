// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

#include <Point.h>
#include <BndBox.h>

#include <limits>
#include <deque>
#include <algorithm>

class PointSetTool
{
private:

  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  PointSetTool()
  {
  }

public:

  // =======================================================================
  // function : Box
  // purpose  :
  // =======================================================================
  static BndBox Box(const std::deque<Point>& thePoints)
  {
    BndBox aBox;
    for (size_t i = 0; i < thePoints.size(); ++i)
    {
      aBox.AddPoint (thePoints[i]);
    }

    return aBox;
  }

  // =======================================================================
  // function : Scale
  // purpose  :
  // =======================================================================
  static BndBox Scale(
    std::deque<Point>& thePoints,
    const double       theScale,
    const BndBox&      theBox)
  {
    const Point aScale {
      theScale / (theBox.Corners.Max.Coord.X - theBox.Corners.Min.Coord.X),
      theScale / (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y)
    };

    BndBox aBox;
    std::for_each (thePoints.begin(), thePoints.end(), [&theBox, &aBox, &aScale](
      Point& thePoint)
    {
      for (int i = 0; i < 2; ++i)
      {
        thePoint.Data[i] = (thePoint.Data[i] - theBox.Corners.Min.Data[i]) * aScale.Data[i];
      }

      aBox.AddPoint (thePoint);
    });

    return aBox;
  }
};
