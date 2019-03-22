#include "end_effectors_objective_and_gradient.h"
#include "transformed_tips.h"
#include "kinematics_jacobian.h"
#include "copy_skeleton_at.h"
#include <iostream>

void end_effectors_objective_and_gradient(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  const Eigen::VectorXd & xb0,
  std::function<double(const Eigen::VectorXd &)> & f,
  std::function<Eigen::VectorXd(const Eigen::VectorXd &)> & grad_f,
  std::function<void(Eigen::VectorXd &)> & proj_z)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  f = [&](const Eigen::VectorXd & A)->double
  {
    Skeleton cp_skeleton = copy_skeleton_at(skeleton, A);
    Eigen::VectorXd transformed = transformed_tips(cp_skeleton, b);
    double result = 0.0;
    for (int i = 0; i < b.size(); i++){
      result += (Eigen::Vector3d(transformed[3 * i], transformed[3 * i + 1], transformed[3 * i + 2]) - Eigen::Vector3d(xb0[3 * i], xb0[3 * i + 1], xb0[3 * i + 2])).squaredNorm();
    }
    return result;
  };

  grad_f = [&](const Eigen::VectorXd & A)->Eigen::VectorXd
  {
    return Eigen::VectorXd::Zero(A.size());
  };
  
  proj_z = [&](Eigen::VectorXd & A)
  {
    for (int i = 0; i < skeleton.size(); i++) {
      A[3*i] = std::max(skeleton[i].xzx_min[0], std::min(skeleton[i].xzx_max[0], A[3*i]));
      A[3*i+1] = std::max(skeleton[i].xzx_min[1], std::min(skeleton[i].xzx_max[1], A[3*i+1]));
      A[3*i+2] = std::max(skeleton[i].xzx_min[2], std::min(skeleton[i].xzx_max[2], A[3*i+2]));
    }
    assert(skeleton.size()*3 == A.size());
  };
  /////////////////////////////////////////////////////////////////////////////
}
