#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d c = center;

  double discriminant = square(d.dot(e - c)) - d.dot(d) * ((e - c).dot(e - c) - square(radius));
  if (discriminant == 0.0){
    double result = -d.dot(e-c)/d.dot(d);
    if (result >= min_t){
      t = result;
      n = (e + t * d - c) / radius; //unit n = (p-c)/radius
      return true;
    }
    else{
      return false;
    }
  }
  else if (discriminant > 0.0){
    double root_1 = (-d.dot(e-c)+sqrt(discriminant))/d.dot(d);
    double root_2 = (-d.dot(e-c)-sqrt(discriminant))/d.dot(d);
    double minimum = fmin(root_1, root_2);
    if (minimum >= min_t){
      t = minimum;
      n = (e + t * d - c) / radius;
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}

