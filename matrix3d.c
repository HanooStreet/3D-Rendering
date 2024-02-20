#include <stdio.h>
#include <math.h>
#include "vector3d.h"
#include "matrix3d.h"

// x1 x2 x3 x4
// y1 y2 y3 y4
// z1 z2 z3 z4
// w1 w2 w3 w4 

struct Vector3D matrixVectorMult(struct Matrix3D m, struct Vector3D v) {
  struct Vector3D result = {1, 1, 1, 1};

  result.x = m.x[0]*v.x + m.x[1]*v.y + m.x[2]*v.z + m.x[3]*v.w; 
  result.y = m.y[0]*v.x + m.y[1]*v.y + m.y[2]*v.z + m.y[3]*v.w; 
  result.z = m.z[0]*v.x + m.z[1]*v.y + m.z[2]*v.z + m.z[3]*v.w; 
  result.w = m.w[0]*v.x + m.w[1]*v.y + m.w[2]*v.z + m.w[3]*v.w; 

  return result;
}

struct Matrix3D matrixMatrixMult(struct Matrix3D m1, struct Matrix3D m2){
  struct Matrix3D result;
  struct Vector3D col1 = {m2.x[0], m2.y[0], m2.z[0], m2.w[0]};
  struct Vector3D col1Res = matrixVectorMult(m1, col1);
  result.x[0] = col1Res.x;
  result.y[0] = col1Res.y;
  result.z[0] = col1Res.z;
  result.w[0] = col1Res.w;
  struct Vector3D col2 = {m2.x[1], m2.y[1], m2.z[1], m2.w[1]};
  struct Vector3D col2Res = matrixVectorMult(m1, col2);
  result.x[1] = col2Res.x;
  result.y[1] = col2Res.y;
  result.z[1] = col2Res.z;
  result.w[1] = col2Res.w;
  struct Vector3D col3 = {m2.x[2], m2.y[2], m2.z[2], m2.w[2]};
  struct Vector3D col3Res = matrixVectorMult(m1, col3);
  result.x[2] = col3Res.x;
  result.y[2] = col3Res.y;
  result.z[2] = col3Res.z;
  result.w[2] = col3Res.w;
  struct Vector3D col4 = {m2.x[3], m2.y[3], m2.z[3], m2.w[3]};
  struct Vector3D col4Res = matrixVectorMult(m1, col4);
  result.x[3] = col4Res.x;
  result.y[3] = col4Res.y;
  result.z[3] = col4Res.z;
  result.w[3] = col4Res.w;
  return result;
}

struct Matrix3D getRotationMatrix(struct Vector3D cameraRotation){
  //to rotate arond x axis, angleToXZPlane
  float a = atan(cameraRotation.y/cameraRotation.z);
  //to rotate around y axis, angleToYZPlane
  float b = atan(cameraRotation.x/cameraRotation.z);
  struct Matrix3D rotationMatrix;
  rotationMatrix.x[0] = cos(b);
  rotationMatrix.x[1] = 0;
  rotationMatrix.x[2] = -sin(b);
  rotationMatrix.x[3] = 0;
  rotationMatrix.y[0] = sin(a)*sin(b);
  rotationMatrix.y[1] = cos(a);
  rotationMatrix.y[2] = sin(a)*cos(b);
  rotationMatrix.y[3] = 0;
  rotationMatrix.z[0] = cos(a)*sin(b);
  rotationMatrix.z[1] = -sin(a);
  rotationMatrix.z[2] = cos(a)*cos(b);
  rotationMatrix.w[0] = 0;
  rotationMatrix.w[1] = 0;
  rotationMatrix.w[2] = 0;
  rotationMatrix.w[3] = 1;
  return rotationMatrix;
}

