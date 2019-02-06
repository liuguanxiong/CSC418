#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int minimum_f = -1;
  double minimum_t = std::numeric_limits<double>::infinity();

  for (int i = 0; i < F.rows(); i++){
    double cur;
    if (ray_intersect_triangle(ray, V.row(F(i,0)), V.row(F(i,2)), min_t, max_t, cur)){
      if (cur < minimum_t){
        minimum_f = i;
        minimum_t = cur;
      }
    }
  }

  if (minimum_f != -1){
    hit_t = minimum_t;
    hit_f = minimum_f;
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
