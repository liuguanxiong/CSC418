#include "point_box_squared_distance.h"

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  double x = fmin(fabs(box.min_corner(0)-query(0)),fabs(box.max_corner(0)-query(0)));
  double y = fmin(fabs(box.min_corner(1)-query(1)),fabs(box.max_corner(1)-query(1)));
  double z = fmin(fabs(box.min_corner(2)-query(2)),fabs(box.max_corner(2)-query(2)));
  return pow(x, 2) + pow(y, 2) + pow(z, 2);
  ////////////////////////////////////////////////////////////////////////////
}
