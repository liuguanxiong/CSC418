#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::vector<std::vector<int>> VF;
  vertex_triangle_adjacency(F, V.rows(), VF);

  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      Eigen::RowVector3d V_acc(0, 0, 0);
      double total_A = 0;
      Eigen::RowVector3d area_n1 = triangle_area_normal(V.row(F(i, 0)), V.row(F(i, 1)), V.row(F(i, 2)));
      for (int k : VF[F(i, j)]){
        Eigen::RowVector3d area_n2 = triangle_area_normal(V.row(F(k, 0)), V.row(F(k, 1)), V.row(F(k, 2)));
        if ((area_n1.normalized()).dot(area_n2.normalized()) > cos(corner_threshold * M_PI / 180.0)){
          total_A += area_n2.norm();
          V_acc += area_n2;
        }
      }
      N.row(i * 3 + j) = (V_acc / total_A).normalized();
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
