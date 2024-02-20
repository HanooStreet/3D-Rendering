#include <stdio.h>
#include "vector3d.h"
#include "matrix3d.h"

struct Vector3D modelToWorldSpace(struct Vector3D v, struct Vector3D location);
struct Vector3D worldToCameraSpace(struct Vector3D v, struct Vector3D cameraLocation, struct Vector3D cameraRotation, struct Matrix3D rotationMatrix);
struct Vector3D cameraToProjectionSpace(struct Vector3D v, struct Matrix3D clippingMatrix, float WIDTH, float HEIGHT);