#include "Triangle.h"
#include "Ray.h"

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // let vertex a = the first element in corners, vertex b = the second element in corners, vertex c = the third element in corners.
  double a, b, c, d, e, f, g, h, i, j, k, l;
  a = std::get<0>(corners)[0]-std::get<1>(corners)[0];
  b = std::get<0>(corners)[1]-std::get<1>(corners)[1];
  c = std::get<0>(corners)[2]-std::get<1>(corners)[2];
  d = std::get<0>(corners)[0]-std::get<2>(corners)[0];
  e = std::get<0>(corners)[1]-std::get<2>(corners)[1];
  f = std::get<0>(corners)[2]-std::get<2>(corners)[2];
  g = ray.direction[0];
  h = ray.direction[1];
  i = ray.direction[2];
  j = std::get<0>(corners)[0]-ray.origin[0];
  k = std::get<0>(corners)[1]-ray.origin[1];
  l = std::get<0>(corners)[2]-ray.origin[2];

  double yellow = (e*i-h*f);
  double red = (g*f-d*i);
  double pink = (d*h-e*g);
  double brown = (a*k-j*b);
  double green = (j*c-a*l);
  double blue = (b*l-k*c);

  double M = a*yellow+b*red+c*pink;
  double t_p = (-f*brown+e*green+d*blue)/M;
  if (t_p < min_t){
    return false;
  }
  double gamma = (i*brown+h*green+g*blue)/M;
  if (gamma < 0 || gamma > 1){
    return false;
  }
  double beta = (j*yellow+k*red+l*pink)/M;
  if (beta < 0 || beta > 1-gamma){
    return false;
  }
  Eigen::Vector3d u = std::get<2>(corners)-std::get<0>(corners);
  Eigen::Vector3d v = std::get<1>(corners)-std::get<0>(corners);
  t = t_p;
  n = v.cross(u).normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}


