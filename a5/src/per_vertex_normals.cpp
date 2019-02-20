#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::unordered_map<int, std::list<int>> point_to_adj_faces;
  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < F.cols(); j++) {
      point_to_adj_faces[F(i, j)].emplace_back(i);
    }
  }

  for (int i = 0; i < V.rows(); i++){
    double total_A = 0;
    Eigen::RowVector3d V_acc(0, 0, 0);
    for (int k : point_to_adj_faces[i]){
      Eigen::RowVector3d area_n = triangle_area_normal(V.row(F(k, 0)), V.row(F(k, 1)), V.row(F(k, 2)));
      total_A += area_n.norm();
      V_acc += area_n;
    }
    N.row(i) = (V_acc/total_A).normalized();
  }
  ////////////////////////////////////////////////////////////////////////////
}
