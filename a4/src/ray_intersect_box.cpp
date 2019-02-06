#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double x, y, z;
  x = 1/ray.direction(0);
  y = 1/ray.direction(1);
  z = 1/ray.direction(2);

  if (x >= 0) {
    txmin = x*(box.min_corner(0)-ray.origin(0));
    txmax = x*(box.max_corner(0)-ray.origin(0));
  } 
  else{
    txmin = x*(box.max_corner(0)-ray.origin(0));
    txmax = x*(box.min_corner(0)-ray.origin(0));
  }

  if (y >= 0) {
    tymin = y*(box.min_corner(1)-ray.origin(1));
    tymax = y*(box.max_corner(1)-ray.origin(1));
  } 
  else{
    tymin = y*(box.max_corner(1)-ray.origin(1));
    tymax = y*(box.min_corner(1)-ray.origin(1));
  }

  if (z >= 0) {
    tzmin = z*(box.min_corner(2)-ray.origin(2));
    tzmax = z*(box.max_corner(2)-ray.origin(2));
  } 
  else{
    tzmin = z*(box.max_corner(2)-ray.origin(2));
    tzmax = z*(box.min_corner(2)-ray.origin(2));
  }

  double largest_min = fmax(fmax(txmin, tymin), tzmin);
  double smallest_max = fmin(fmin(txmax, tymax), tzmax);
  if (smallest_max < largest_min){
    return false;
  }

  double overlap_min = fmax(min_t, largest_min);
  double overlap_max = fmin(max_t, smallest_max);
  if (overlap_max < overlap_min){
    return false;
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
