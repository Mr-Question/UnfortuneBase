// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

#include <Point.h>
#include <BndBox.h>

#include <deque>

class Frame
{
public:

  enum Type
  {
    Triangle,
    Rectangle,
    WidthCutTriangle,
    WidthCutRectangle,
    Grid
  };

  // =======================================================================
  // function : Add
  // purpose  :
  // =======================================================================
  static BndBox Add(
    const BndBox&      theBox,
    std::deque<Point>& thePoints,
    const Type         theFrameType)
  {
    BndBox aBox;
    switch (theFrameType)
    {
    case Triangle:
      aBox = addFrameTriangle (theBox, thePoints);
      break;

    case Rectangle:
      aBox = addFrameRectangle (theBox, thePoints);
      break;

    case WidthCutTriangle:
      aBox = addFrameWidthCutTriangle (theBox, thePoints);
      break;

    case WidthCutRectangle:
      aBox = addFrameWidthCutRectangle (theBox, thePoints);
      break;

    case Grid:
      aBox = addFrameGrid (theBox, thePoints);
      break;

    default:
      break;
    }

    return aBox;
  }

private:

  // =======================================================================
  // function : addFrameTriangle
  // purpose  :
  // =======================================================================
  static BndBox addFrameTriangle(
    const BndBox&      theBox,
    std::deque<Point>& thePoints)
  {
    const double aDelta[2] = {
      (theBox.Corners.Max.Coord.X - theBox.Corners.Min.Coord.X),
      (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y)
    };

    const double aDeltaMin = std::min (aDelta[0], aDelta[1]);
    const double aDeltaMax = std::max (aDelta[0], aDelta[1]);
    const double aDeltaSum = aDelta[0] + aDelta[1];

    thePoints.push_back (Point {
      (theBox.Corners.Max.Coord.X + theBox.Corners.Min.Coord.X) / 2.,
      (theBox.Corners.Max.Coord.Y + aDeltaMax)});

    thePoints.push_back (Point {
      (theBox.Corners.Min.Coord.X - aDeltaSum),
      (theBox.Corners.Min.Coord.Y - aDeltaMin)});

    thePoints.push_back (Point {
      (theBox.Corners.Max.Coord.X + aDeltaSum),
      (theBox.Corners.Min.Coord.Y - aDeltaMin)});

    BndBox aBox = theBox;
    aBox.AddPoint (thePoints[thePoints.size () - 1]);
    aBox.AddPoint (thePoints[thePoints.size () - 2]);
    aBox.AddPoint (thePoints[thePoints.size () - 3]);

    return aBox;
  }

  // =======================================================================
  // function : addFrameRectangle
  // purpose  :
  // =======================================================================
  static BndBox addFrameRectangle(
    const BndBox&      theBox,
    std::deque<Point>& thePoints)
  {
    const double aDX = (theBox.Corners.Max.Coord.X - theBox.Corners.Min.Coord.X) / 2.;
    const double aDY = (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y) / 2.;
    thePoints.push_back (Point {
      theBox.Corners.Min.Coord.X - aDX,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Max.Coord.X + aDX,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Min.Coord.X - aDX,
      theBox.Corners.Max.Coord.Y + aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Max.Coord.X + aDX,
      theBox.Corners.Max.Coord.Y + aDY
    });

    BndBox aBox = theBox;
    aBox.AddPoint (thePoints[thePoints.size () - 1]);
    aBox.AddPoint (thePoints[thePoints.size () - 2]);
    aBox.AddPoint (thePoints[thePoints.size () - 3]);
    aBox.AddPoint (thePoints[thePoints.size () - 4]);

    return aBox;
  }

  // =======================================================================
  // function : addFrameWidthCutTriangle
  // purpose  :
  // =======================================================================
  static BndBox addFrameWidthCutTriangle(
    const BndBox&      theBox,
    std::deque<Point>& thePoints)
  {
    const double aDY = (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y) / 2.;
    thePoints.push_back (Point {
      theBox.Corners.Min.Coord.X,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Max.Coord.X,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
     (theBox.Corners.Min.Coord.X + theBox.Corners.Max.Coord.X) / 2.,
      theBox.Corners.Max.Coord.Y + aDY
    });

    BndBox aBox = theBox;
    aBox.AddPoint (thePoints[thePoints.size () - 1]);
    aBox.AddPoint (thePoints[thePoints.size () - 2]);
    aBox.AddPoint (thePoints[thePoints.size () - 3]);

    return aBox;
  }

  // =======================================================================
  // function : addFrameWidthCutRectangle
  // purpose  :
  // =======================================================================
  static BndBox addFrameWidthCutRectangle(
    const BndBox&      theBox,
    std::deque<Point>& thePoints)
  {
    const double aDY = (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y) / 2.;
    thePoints.push_back (Point {
      theBox.Corners.Min.Coord.X,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Max.Coord.X,
      theBox.Corners.Min.Coord.Y - aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Min.Coord.X,
      theBox.Corners.Max.Coord.Y + aDY
    });

    thePoints.push_back (Point {
      theBox.Corners.Max.Coord.X,
      theBox.Corners.Max.Coord.Y + aDY
    });

    BndBox aBox = theBox;
    aBox.AddPoint (thePoints[thePoints.size () - 1]);
    aBox.AddPoint (thePoints[thePoints.size () - 2]);
    aBox.AddPoint (thePoints[thePoints.size () - 3]);
    aBox.AddPoint (thePoints[thePoints.size () - 4]);

    return aBox;
  }

  // =======================================================================
  // function : addFrameGrid
  // purpose  :
  // =======================================================================
  static BndBox addFrameGrid(
    const BndBox&      theBox,
    std::deque<Point>& thePoints)
  {
    const int aAuxSize = 10;

    const double aDelta[2] = {
      2. * (theBox.Corners.Max.Coord.X - theBox.Corners.Min.Coord.X) / (aAuxSize - 1),
      2. * (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y) / (aAuxSize - 1)
    };

    const Point aStartPoint {
      (theBox.Corners.Max.Coord.X + theBox.Corners.Min.Coord.X) / 2. -
        (theBox.Corners.Max.Coord.X - theBox.Corners.Min.Coord.X),
      (theBox.Corners.Max.Coord.Y + theBox.Corners.Min.Coord.Y) / 2. -
        (theBox.Corners.Max.Coord.Y - theBox.Corners.Min.Coord.Y)
    };

    BndBox aBox = theBox;
    for (int j = 0; j < aAuxSize; ++j)
    {
      for (int i = 0; i < aAuxSize; ++i)
      {
        if (j < aAuxSize - 1)
        {
          if (i > 0 && i < aAuxSize - 1)
            continue;
        }

        const Point aPoint {
          aStartPoint.Coord.X + i * aDelta[0],
          aStartPoint.Coord.Y + j * aDelta[1]
        };

        aBox.AddPoint       (aPoint);
        thePoints.push_back (aPoint);
      }
    }

    return aBox;
  }
};
