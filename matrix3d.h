#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <stdio.h>
#include "vector3d.h"

struct Matrix3D {
  float x[4];
  float y[4];
  float z[4];
  float w[4];
};

struct Vector3D matrixVectorMult(struct Matrix3D m, struct Vector3D v);
struct Matrix3D getRotationMatrix(struct Vector3D cameraRotation);
struct Matrix3D matrixMatrixMult(struct Matrix3D m1, struct Matrix3D m2);
#endif