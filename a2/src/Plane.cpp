#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  double result = (point - e).dot(normal) / d.dot(normal);

  if (d.dot(normal) == 0){
    return false;
  }
  else if (result < min_t){
    return false;
  }
  else if (result >= min_t){
    t = result;
    n = normal;
    return true;
  }
  ////////////////////////////////////////////////////////////////////////////
}

