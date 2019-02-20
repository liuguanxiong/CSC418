#include "triangle_area_normal.h"
#include <Eigen/Geometry>

Eigen::RowVector3d triangle_area_normal(
  const Eigen::RowVector3d & a, 
  const Eigen::RowVector3d & b, 
  const Eigen::RowVector3d & c)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  Eigen::RowVector3d n = ((c-a).cross(b-a)).normalized();
  double A =  ((c-a).cross(b-a)).norm()/2.0;
  return A * n;
  ////////////////////////////////////////////////////////////////////////////
}
