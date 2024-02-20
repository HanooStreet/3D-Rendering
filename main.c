#include "vector3d.c"
#include "camera.h"
#include <stdio.h>

// Multithreading with OpenBLAS later maybe

// OP THING 
// https://www.desmos.com/calculator/nqom2ih05g
// LESSER OP THING
// https://bvisness.me/desmos/
// IMPLEMENTATION W/ CODE EXAMPLES
// https://www.codeproject.com/Articles/1168552/Build-My-Own-3D-Graphics-Engine-Step-By-Step

int main() {

  //this stuff is for camera to perspective
  float PI = 3.14159265358979323846;
  float VIEW_ANGLE = PI / 2; //angle of the cone of vision
  float NEAR = 0;
  float FAR = 100; //these two represent max and min render distance
  float WIDTH = 800;
  float HEIGHT = 600; //these two are the resolution of screen
  float fov = 1 / tan(VIEW_ANGLE / 2);
  float aspectRatio = WIDTH / HEIGHT;
  struct Matrix3D clippingMatrix = { {fov * aspectRatio, 0, 0, 0}, 
                                     {0, fov, 0, 0}, 
                                     {0, 0, (FAR + NEAR) / (NEAR - FAR), 1}, 
                                     {0, 0, 2 * NEAR * FAR / (NEAR - FAR), 0} };
  

  
  return 0;
}