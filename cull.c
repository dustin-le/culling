// Le, Dustin E.
// dxl0689
// 2019-11-22

//----------------------------------------------------------
#include <math.h>
#include <stdio.h>

#include "cull.h"
#include "vertex.h"

//----------------------------------------------------------
int cull( Vertex *v1, Vertex *v2, Vertex *v3, Vertex *cameraPosition )
{
  // TODO: Compute the toTriangle vector.  Compute the triangle
  //       normal vector.  Compute the dot product of these two
  //       vectors.  Return an indication of whether this triangle
  //       should be culled.

  Vertex toTriangle, normal;

  // To calculate the normal vector, perform the cross product of two vectors.
  normal.x = v1->y * v2->z - v1->z * v2->y;
  normal.y = v1->z * v2->x - v1->x * v2->z;
  normal.z = v1->x * v2->y - v1->y * v2->x;

  if (cameraPosition->z == 0)
  {
    cameraPosition->z = +HUGE_VAL;
  }
  
  toTriangle.x = v1->x - cameraPosition->x;
  toTriangle.y = v1->y - cameraPosition->y;
  toTriangle.z = v1->z - cameraPosition->z;

  if ( (normal.x * toTriangle.x + normal.y * toTriangle.y + normal.z * toTriangle.z) > 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}

//----------------------------------------------------------
