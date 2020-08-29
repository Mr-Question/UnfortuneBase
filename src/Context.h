// MIT License
// Copyright (c) 2020 Oleg Agashin
// See file LICENSE for detail.

#pragma once

#include <Mesh.h>
#include <cmath>

struct Context
{
  // =======================================================================
  // function : Constructor
  // purpose  :
  // =======================================================================
  Context(Mesh& theMesh)
    : Data  (theMesh)
    , Front (nullptr)
  {
  }

  Mesh&     Data;
  HalfEdge* Front;
};
