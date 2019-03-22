#include "line_search.h"
#include <iostream>

double line_search(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const Eigen::VectorXd & z,
  const Eigen::VectorXd & dz,
  const double max_step)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  double sigma = 10000.0;
  Eigen::VectorXd new_z = z - sigma * dz;
  proj_z(new_z);

  while (f(new_z) > f(z)) {
    sigma /= 2.0;
    new_z = z - sigma * dz;
    proj_z(new_z);
  }
  return sigma;
  /////////////////////////////////////////////////////////////////////////////
}