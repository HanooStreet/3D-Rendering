#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <stdio.h>

struct Vector3D {
  float x;
  float y;
  float z;
  float w;
};

struct Vector3D ex = {1, 0, 0, 1};
struct Vector3D ey = {0, 1, 0, 1};
struct Vector3D ez = {0, 0, 1, 1};

struct Vector3D invalid = {-1, -1, -1, -1};

struct Vector3D rotateX(struct Vector3D v, float angle)
struct Vector3D rotateY(struct Vector3D v, float angle);
struct Vector3D rotateZ(struct Vector3D v, float angle);
struct Vector3D translate(struct Vector3D v, struct Vector3D t);
struct Vector3D translateReverse(struct Vector3D v, struct Vector3D t);
struct Vector3D scalarMultiplication(struct Vector3D v, float s);
float dotProduct(struct Vector3D a, struct Vector3D b);
float lengthSquared(struct Vector3D v);
float lengthSquaredSquareRooted(struct Vector3D v);
float angleBetweenVectors(struct Vector3D v1, struct Vector3D v2);
struct Vector3D proj(struct Vector3D v, struct Vector3D p);

#endif