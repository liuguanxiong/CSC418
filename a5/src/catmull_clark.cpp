#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include <list>
#include <string>

void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  if (num_iters == 0){
    return;
  }

  std::unordered_map<int, Eigen::RowVector3d> face_point;
  for (int i = 0; i < F.rows(); i++){
    Eigen::RowVector3d accumulator(0, 0, 0);
    for (int j = 0; j < F.cols(); j++){
      accumulator += V.row(F(i, j));
    }
    face_point[i] = accumulator / 4.0;
  }

  std::unordered_map<int, std::list<int>> point_to_adj_faces;
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      point_to_adj_faces[F(i, j)].emplace_back(i);
    }
  }
  
  std::unordered_map<std::string, std::list<int>> edge_to_adj_faces;
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      std::string key;
      if (F(i, j) < F(i, (j + 1) % F.cols())){
        key = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      }
      else{
        key = std::to_string(F(i, (j + 1) % F.cols())) + "-" + std::to_string(F(i, j));
      }
      edge_to_adj_faces[key].emplace_back(i);
    }
  }

  std::unordered_map<int, std::list<std::string>> point_to_edges;
  std::unordered_map<int, std::list<int>> point_to_neighbors;
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      std::string value;
      value = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      point_to_edges[F(i, j)].emplace_back(value);
      point_to_neighbors[F(i, j)].emplace_back(F(i, (j + 1) % F.cols()));
    }
  }

  std::unordered_map<std::string, Eigen::RowVector3d> edge_point;
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      std::string key;
      if (F(i, j) < F(i, (j + 1) % F.cols())){
        key = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      }
      else{
        key = std::to_string(F(i, (j + 1) % F.cols())) + "-" + std::to_string(F(i, j));
      }
      Eigen::RowVector3d edgepoint(0, 0, 0);
      for (int k: edge_to_adj_faces[key]){
        edgepoint += face_point[k];
      }
      edgepoint += V.row(F(i, (j + 1) % F.cols()));
      edgepoint += V.row(F(i, j));
      edgepoint /= 4.0;

      std::string key1, key2;
      key1 = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      key2 = std::to_string(F(i, (j + 1) % F.cols())) + "-" + std::to_string(F(i, j));

      edge_point[key1] = edgepoint;
      edge_point[key2] = edgepoint;
    }
  }



  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){

      //vertex 1
      Eigen::RowVector3d ver1;
      Eigen::RowVector3d old = V.row(F(i, j));
      Eigen::RowVector3d avg_F(0, 0, 0);
      for (int k: point_to_adj_faces[F(i, j)]){
        avg_F += face_point[k];
      }
      avg_F /= (double)point_to_adj_faces[F(i, j)].size();

      Eigen::RowVector3d avg_edge(0, 0, 0);
      for (int neighbor_idx: point_to_neighbors[F(i, j)]){
        avg_edge += (V.row(F(i, j)) + V.row(neighbor_idx))/2.0;
      }
      avg_edge /= (double)point_to_neighbors[F(i, j)].size();

      n = (double)point_to_adj_faces[F(i, j)].size()
      ver1 = (avg_F + 2 * avg_edge + (n - 3) * old) / n

      //vertex 2
      Eigen::RowVector3d ver2;
      std::string key;
      key = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      ver2 = edge_point[key];

      //vertex 3
      Eigen::RowVector3d ver3;
      ver3 = face_point[i];

      //vertex 4
      Eigen::RowVector3d ver4;
      std::string key;
      key = std::to_string(F(i, (j + 3) % F.cols())) + "-" + std::to_string(F(i, j));
      ver4 = edge_point[key];

    }
  }

  
  SV = V;
  SF = F;
  ////////////////////////////////////////////////////////////////////////////
}
