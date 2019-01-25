#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ray.origin = camera.e;
  double u = (-camera.width/2) + camera.width * (j + 0.5) / width; 
  double v = (camera.height/2) - camera.height * (i + 0.5) / height;
  ray.direction = -camera.d * camera.w + u * camera.u + v * camera.v;
  ////////////////////////////////////////////////////////////////////////////
}

