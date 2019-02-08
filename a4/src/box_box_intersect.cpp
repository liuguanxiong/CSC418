#include "box_box_intersect.h"
bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  return (B.min_corner(0) < A.max_corner(0)) &&
           (B.min_corner(1) < A.max_corner(1)) &&
           (B.min_corner(2) < A.max_corner(2)) &&
           (A.min_corner(0) < B.max_corner(0)) &&
           (A.min_corner(1) < B.max_corner(1)) &&
           (A.min_corner(2) < B.max_corner(2));
  // Replace with your code here:
  // Eigen::RowVector3d a_center = A.center();
  // Eigen::RowVector3d b_center = B.center();
  // if (a_center(0) < b_center(0)&&
  //     a_center(1) < b_center(1)&&
  //     a_center(2) < b_center(2)){
  //   if (A.max_corner(0) > B.min_corner(0)&&
  //       A.max_corner(1) > B.min_corner(1)&&
  //       A.max_corner(2) > B.min_corner(2)){
  //     return true;
  //   }
  // }
  // else if (a_center(0) == b_center(0)&&
  //          a_center(1) == b_center(1)&&
  //          a_center(2) == b_center(2)){
  //   return true;
  // }
  // else{
  //   if (B.max_corner(0) > A.min_corner(0)&&
  //       B.max_corner(1) > A.min_corner(1)&&
  //       B.max_corner(2) > A.min_corner(2)){
  //     return true;
  //   }
  // }
  // return false;
  ////////////////////////////////////////////////////////////////////////////
}

