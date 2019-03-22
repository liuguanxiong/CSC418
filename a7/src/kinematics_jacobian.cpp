#include "kinematics_jacobian.h"
#include "transformed_tips.h"
#include <iostream>

void kinematics_jacobian(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  Eigen::MatrixXd & J)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  J = Eigen::MatrixXd::Zero(b.size()*3,skeleton.size()*3);
  Eigen::VectorXd transformed = transformed_tips(skeleton, b);
  double da = 1.0e-7;
  for (int i = 0; i < skeleton.size(); i++){
    for (int j = 0; j < skeleton[0].xzx.size(); j++){
      Skeleton cp_skeleton = skeleton;
      cp_skeleton[i].xzx[j] += da;
      Eigen::VectorXd dx = transformed_tips(cp_skeleton, b) - transformed;
      for (int k = 0; k < J.rows(); k++){
        J(k, 3 * i + j) = dx[k]/da;
      }
    }
  }
  /////////////////////////////////////////////////////////////////////////////
}
