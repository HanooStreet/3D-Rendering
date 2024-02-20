#include <stdio.h>
#include <math.h>
#include "vector3d.h"

// Function to rotate a vector along the x-axis
struct Vector3D rotateX(struct Vector3D v, float angle) {
 struct Vector3D rotatedVector;

  // Compute rotation matrix
  float cosAngle = cos(angle);
  float sinAngle = sin(angle);

  rotatedVector.x = v.x;
  rotatedVector.y = v.y * cosAngle - v.z * sinAngle;
  rotatedVector.z = v.y * sinAngle + v.z * cosAngle;

  return rotatedVector;
}

// Function to rotate a vector along the y-axis
struct Vector3D rotateY(struct Vector3D v, float angle) {
  struct Vector3D rotatedVector;

  // Compute rotation matrix
  float cosAngle = cos(angle);
  float sinAngle = sin(angle);

  rotatedVector.x = v.x * cosAngle + v.z * sinAngle;
  rotatedVector.y = v.y;
  rotatedVector.z = -v.x * sinAngle + v.z * cosAngle;

  return rotatedVector;
}

// Function to rotate a vector along the z-axis
struct Vector3D rotateZ(struct Vector3D v, float angle) {
  struct Vector3D rotatedVector;

  // Compute rotation matrix
  float cosAngle = cos(angle);
  float sinAngle = sin(angle);

  rotatedVector.x = v.x * cosAngle - v.y * sinAngle;
  rotatedVector.y = v.x * sinAngle + v.y * cosAngle;
  rotatedVector.z = v.z;

  return rotatedVector;
}

struct Vector3D translate(struct Vector3D v, struct Vector3D t){
  struct Vector3D translated;
  translated.x = v.x + t.x;
  translated.y = v.y + t.y;
  translated.z = v.z + t.z;
  return translated;
}

struct Vector3D translateReverse(struct Vector3D v, struct Vector3D t){
  struct Vector3D translated;
  translated.x = v.x - t.x;
  translated.y = v.y - t.y;
  translated.z = v.z - t.z;
  return translated;
}

struct Vector3D scalarMultiplication(struct Vector3D v, float s) {
  struct Vector3D scaled;
  scaled.x = v.x * s;
  scaled.y = v.y * s;
  scaled.z = v.z * s;
  return scaled;
}

float dotProduct(struct Vector3D a, struct Vector3D b) {
  return a.x*b.x + a.y*b.y + a.z*b.z;
}

float lengthSquared(struct Vector3D v) {
  return v.x*v.x + v.y*v.y + v.z*v.z;
}

float lengthSquaredSquareRooted(struct Vector3D v) {
  return sqrt(lengthSquared(v));
}

float angleBetweenVectors(struct Vector3D v1, struct Vector3D v2) {
  return acos(dotProduct(v1, v2) / (lengthSquaredSquareRooted(v1) * lengthSquaredSquareRooted(v2)));
}

struct Vector3D proj(struct Vector3D v, struct Vector3D p){
  return scalarMultiplication(p,dotProduct(v, p)/lengthSquared(p));
}

