#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Eigen::Vector3d A = std::get<0>(corners);
  // Eigen::Vector3d B = std::get<1>(corners);
  // Eigen::Vector3d C = std::get<2>(corners);

  // Eigen::MatrixXd mat(3, 3);
  // mat(0, 0) = A[0]-B[0];
  // mat(0, 1) = A[0]-C[0];
  // mat(0, 2) = ray.direction[0];
  // mat(1, 0) = A[1]-B[1];
  // mat(1, 1) = A[1]-C[1];
  // mat(1, 2) = ray.direction[1];
  // mat(2, 0) = A[2]-B[2];
  // mat(2, 1) = A[2]-C[2];
  // mat(2, 2) = ray.direction[2];

  // Eigen::Vector3d ori(A[0] - ray.origin[0], A[1] - ray.origin[1], A[2] - ray.origin[2]);
  // Eigen::Vector3d ans = mat.colPivHouseholderQr().solve(ori);
  // bool hit;
  // t = ans[2];

  // if (t < min_t){
  //   hit = false;
  // }
  // else if (ans[1] < 0 || ans[1] > 1){
  //   hit = false;
  // }
  // else if (ans[0] < 0 || ans[0] > 1 - ans[1]){
  //   hit = false;
  // }
  // else{
  //   Eigen::Vector3d pt = ray.origin + t * ray.direction;
  //   Eigen::Vector3d line1 = pt - A;
  //   Eigen::Vector3d line2 = pt - B;
  //   n = line1.cross(line2);
  //   n.normalized();
  //   hit = true;
  // }
  // return hit;
  // Replace with your code here:
  Eigen::Vector3d A = std::get<0>(corners);
  Eigen::Vector3d B = std::get<1>(corners);
  Eigen::Vector3d C = std::get<2>(corners);
  double a, b, c, d, e, f, g, h, i, j, k, l;

  a = A[0]-B[0];
  b = A[1]-B[1];
  c = A[2]-B[2];
  d = A[0]-C[0];
  e = A[1]-C[1];
  f = A[2]-C[2];
  g = ray.direction[0];
  h = ray.direction[1];
  i = ray.direction[2];
  j = A[0]-ray.origin[0];
  k = A[1]-ray.origin[1];
  l = A[2]-ray.origin[2];

  double yellow = (e*i-h*f);
  double red = (g*f-d*i);
  double pink = (d*h-e*g);
  double brown = (a*k-j*b);
  double green = (j*c-a*l);
  double blue = (b*l-k*c);

  double M = a*yellow+b*red+c*pink;
  double t_p = -(f*brown+e*green+d*blue)/M;
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
  Eigen::Vector3d u = C-A;
  Eigen::Vector3d v = B-A;
  t = t_p;
  n = v.cross(u).normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}


