#include <stdio.h>
#include <math.h>
#include "vector3d.h"
#include "matrix3d.h"



struct Vector3D modelToWorldSpace(struct Vector3D v, struct Vector3D location) {
  return translate(v, location);
}

struct Vector3D worldToCameraSpace(struct Vector3D v, struct Vector3D cameraLocation, struct Vector3D cameraRotation, struct Matrix3D rotationMatrix) {
  //move v such that the camera vector becomes (0,0,0) to make rotating easier
  v = translateReverse(v, cameraLocation);
  v = matrixVectorMult(rotationMatrix, v);
  
  return v;
}

struct Vector3D cameraToProjectionSpace(struct Vector3D v, struct Matrix3D clippingMatrix, float WIDTH, float HEIGHT) {
  v = matrixVectorMult(clippingMatrix, v);

  //this checks if the vector is outside our field of view, thus we dont need to render it
  if (v.w < 0) return invalid;
  
  v.x = (v.x * WIDTH) / ((2 * v.w) + (WIDTH / 2));
  v.y = (v.y * HEIGHT) / ((2 * v.w) + (HEIGHT / 2));

  return v;
}
