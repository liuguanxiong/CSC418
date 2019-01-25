#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <math.h>
#include <iostream>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d c = center;
  bool return_val = false;
  // compute k**2
  double k_2 = (d).dot(e - c) * (d).dot(e - c) - d.dot(d) * ((e - c).dot((e - c)) - radius * radius);

  if (k_2 >= 0) {
    // valid
    double k = sqrt(k_2);
    double t1 = (-(d).dot(e - c) + k) / d.dot(d);
    double t2 = (-(d).dot(e - c) - k) / d.dot(d);

    double min = fmin(t1, t2);
    double max = fmax(t1, t2);

    if (min > min_t) {
      t = min;
      return_val = true;
    } else if (min < min_t && max > min_t) {
      t = max;
      return_val = true;
    }
  }

  if(return_val == true) {
      Eigen::Vector3d p = e + t * d;
      n = (p - c) / radius;
  }

  return return_val;
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d c = center;

  double discriminant = pow(d.dot(e - c), 2) - d.dot(d) * ((e - c).dot(e - c) - pow(radius, 2));
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

