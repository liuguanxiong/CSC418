#include "ray_intersect_triangle.h"

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double a, b, c, d, e, f, g, h, i, j, k, l;

  a = A(0)-B(0);
  b = A(1)-B(1);
  c = A(2)-B(2);
  d = A(0)-C(0);
  e = A(1)-C(1);
  f = A(2)-C(2);
  g = ray.direction(0);
  h = ray.direction(1);
  i = ray.direction(2);
  j = A(0)-ray.origin(0);
  k = A(1)-ray.origin(1);
  l = A(2)-ray.origin(2);

  double yellow = (e*i-h*f);
  double red = (g*f-d*i);
  double pink = (d*h-e*g);
  double brown = (a*k-j*b);
  double green = (j*c-a*l);
  double blue = (b*l-k*c);

  double M = a*yellow+b*red+c*pink;
  double t_p = -(f*brown+e*green+d*blue)/M;
  if (t_p < min_t || t_p >= max_t){
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
  
  t = t_p;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

