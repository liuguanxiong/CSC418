#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton, 
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Eigen::VectorXd result = Eigen::VectorXd::Zero(3*b.size());
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d>> T;
  forward_kinematics(skeleton, T);
  for (int i = 0; i < b.rows(); i++){
    Eigen::Vector4d coor = T[b[i]] * skeleton[b[i]].rest_T * Eigen::Vector4d(skeleton[b[i]].length, 0, 0, 1);
    coor = coor / coor[3];
    result[i * 3] = coor[0];
    result[i * 3 + 1] = coor[1];
    result[i * 3 + 2] = coor[2];
  }
  return result;
  /////////////////////////////////////////////////////////////////////////////
}
