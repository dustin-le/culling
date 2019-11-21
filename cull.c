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

  Vertex toTriangle, normal, a, b;

  a.x = v1->x - v2->x;
  a.y = v1->y - v2->y;
  a.z = v1->z - v2->z;

  b.x = v1->x - v3->x;
  b.y = v1->y - v3->y;
  b.z = v1->z - v3->z;


  // To calculate the normal vector, perform the cross product of two vectors.
  normal.x = a.y * b.z - a.z * b.y;
  normal.y = a.z * b.x - a.x * b.z;
  normal.z = a.x * b.y - a.y * b.x;

  if (cameraPosition->z == 0)
  {
    cameraPosition->z = +HUGE_VAL;
  }
  
  toTriangle.x = v1->x - cameraPosition->x;
  toTriangle.y = v1->y - cameraPosition->y;
  toTriangle.z = v1->z - cameraPosition->z;

  // > 0 = facing us, so don't cull it.
  if ( (normal.x * toTriangle.x + normal.y * toTriangle.y + normal.z * toTriangle.z) > 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
  
}

//----------------------------------------------------------
