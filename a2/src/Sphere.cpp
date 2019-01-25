#include "Sphere.h"
#include "Ray.h"
#include <cmath>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////

  Eigen::Vector3d to_center = center - ray.origin;

  Eigen::Vector3d projection = ray.direction.normalized() * to_center.dot(ray.direction.normalized());

  Eigen::Vector3d orthogonal = to_center - projection;

  if(orthogonal.norm() > radius){//ray misses the sphere
    return false;
  }
  else{
    double x1 = sqrt(radius*radius - orthogonal.norm()*orthogonal.norm());
    double x2 = -x1;
    Eigen::Vector3d intersection_point = ray.origin + projection - x1*(projection.normalized());
    n = (intersection_point - center).normalized();
    t = (intersection_point - ray.origin).norm()/ray.direction.norm();
    if(t > min_t){
      return true;
    }
    else{
      return false;
    }
  }
  // Replace with your code here:
  // Eigen::Vector3d d = ray.direction;
  // Eigen::Vector3d e = ray.origin;
  // Eigen::Vector3d c = center;

  // double discriminant = pow(d.dot(e - c), 2) - d.dot(d) * ((e - c).dot(e - c) - pow(radius, 2));
  // if (discriminant == 0.0){
  //   double result = -d.dot(e-c)/d.dot(d);
  //   if (result >= min_t){
  //     t = result;
  //     n = (e + t * d - c) / radius; //unit n = (p-c)/radius
  //     return true;
  //   }
  //   else{
  //     return false;
  //   }
  // }
  // else if (discriminant > 0.0){
  //   double root_1 = (-d.dot(e-c)+sqrt(discriminant))/d.dot(d);
  //   double root_2 = (-d.dot(e-c)-sqrt(discriminant))/d.dot(d);
  //   double minimum = fmin(root_1, root_2);
  //   if (minimum >= min_t){
  //     t = minimum;
  //     n = (e + t * d - c) / radius;
  //     return true;
  //   }
  //   else{
  //     return false;
  //   }
  // }
  // else{
  //   return false;
  // }
  ////////////////////////////////////////////////////////////////////////////
}

