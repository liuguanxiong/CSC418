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
    Eigen::MatrixXd J;
    Skeleton cp_skeleton = copy_skeleton_at(skeleton, A);
    kinematics_jacobian(cp_skeleton, b, J);
    Eigen::VectorXd E_deriv = Eigen::VectorXd::Zero(3 * b.size());
    Eigen::VectorXd transformed = transformed_tips(cp_skeleton, b);
    double prev_E = f(A);
    double dx = 1.0e-7;
    for (int i = 0; i < E_deriv.size(); i++){
      Eigen::VectorXd cp_transformed = transformed;
      cp_transformed[i] += dx;
      double result = 0.0;
      for (int j = 0; j < b.size(); j++){
        result += (Eigen::Vector3d(cp_transformed[3 * j], cp_transformed[3 * j + 1], cp_transformed[3 * j + 2]) - Eigen::Vector3d(xb0[3 * j], xb0[3 * j + 1], xb0[3 * j + 2])).squaredNorm();
      }
      E_deriv[i] = (result - prev_E)/dx;
    }
    return J.transpose() * E_deriv;
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
