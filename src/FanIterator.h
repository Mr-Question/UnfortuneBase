// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

#include <HalfEdge.h>

class FanIterator
{
public:

  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  FanIterator (HalfEdge* theSeedHalfEdge)
    : mySeedHalfEdge (theSeedHalfEdge)
    , myCurrHalfEdge (theSeedHalfEdge)
  {
  }

  // =======================================================================
  // function : Destructor
  // purpose  :
  // =======================================================================
  ~FanIterator()
  {
  }

  // =======================================================================
  // function : !
  // purpose  :
  // =======================================================================
  bool operator! ()
  {
    return myCurrHalfEdge != nullptr;
  }

  // =======================================================================
  // function : ++
  // purpose  :
  // =======================================================================
  void operator++()
  {
    if (myCurrHalfEdge == nullptr)
    {
      return;
    }

    if (myCurrHalfEdge->HalfPtr != nullptr)
    {
      myCurrHalfEdge = myCurrHalfEdge->HalfPtr->NextPtr;
      if (myCurrHalfEdge == mySeedHalfEdge)
      {
        myCurrHalfEdge = nullptr;
      }
    }
  }

  // =======================================================================
  // function : ++
  // purpose  :
  // =======================================================================
  void operator++(int)
  {
    this->operator ++ ();
  }

  // =======================================================================
  // function : ->
  // purpose  :
  // =======================================================================
  const HalfEdge* operator->() const
  {
    return myCurrHalfEdge;
  }

  // =======================================================================
  // function : ->
  // purpose  :
  // =======================================================================
  HalfEdge* operator->()
  {
    return myCurrHalfEdge;
  }

  // =======================================================================
  // function : *
  // purpose  :
  // =======================================================================
  const HalfEdge* operator*() const
  {
    return myCurrHalfEdge;
  }

  // =======================================================================
  // function : *
  // purpose  :
  // =======================================================================
  HalfEdge* operator*()
  {
    return myCurrHalfEdge;
  }

private:
  HalfEdge* mySeedHalfEdge;
  HalfEdge* myCurrHalfEdge;
};
