#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  Eigen::RowVector3d edge_point(const Eigen::MatrixXd &V, 
  std::unordered_map<std::string, std::vector<int>> &edge_to_adj_faces, 
  std::unordered_map<int, Eigen::RowVector3d> &face_point, 
  int p1, 
  int p2);

  Eigen::RowVector3d update_point(std::unordered_map<int, std::vector<int>> &point_to_adj_faces, 
  std::unordered_map<int, Eigen::RowVector3d> &face_point, 
  std::unordered_map<int, std::vector<int>> &point_to_neighbors, 
  const Eigen::MatrixXd &V, 
  int p);

  void construct_faces(Eigen::MatrixXd &SV, 
  Eigen::MatrixXi &SF, 
  Eigen::RowVector3d ver1, 
  Eigen::RowVector3d ver2, 
  Eigen::RowVector3d ver3, 
  Eigen::RowVector3d ver4);
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  if (num_iters == 0){
    return;
  }

  std::unordered_map<int, Eigen::RowVector3d> face_point;
  std::unordered_map<int, std::vector<int>> point_to_adj_faces;
  std::unordered_map<std::string, std::vector<int>> edge_to_adj_faces;
  std::unordered_map<int, std::vector<int>> point_to_neighbors;

  for (int i = 0; i < F.rows(); i++){

    //face_point
    Eigen::RowVector3d accumulator(0, 0, 0);

    for (int j = 0; j < F.cols(); j++){
      //face_point
      accumulator += V.row(F(i, j));

      //point_to_adj_faces
      point_to_adj_faces[F(i, j)].emplace_back(i);

      //edge_to_adj_faces
      std::string key;
      key = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      if (std::find(edge_to_adj_faces[key].begin(), edge_to_adj_faces[key].end(), i) == edge_to_adj_faces[key].end()){
        edge_to_adj_faces[key].push_back(i);
      }
      key = std::to_string(F(i, (j + 1) % F.cols())) + "-" + std::to_string(F(i, j));
      if (std::find(edge_to_adj_faces[key].begin(), edge_to_adj_faces[key].end(), i) == edge_to_adj_faces[key].end()){
        edge_to_adj_faces[key].push_back(i);
      }

      //point_to_neighbors
      int neighbor;
      neighbor = F(i, (j + 1) % F.cols());
      if (std::find(point_to_neighbors[F(i, j)].begin(), point_to_neighbors[F(i, j)].end(), neighbor) == point_to_neighbors[F(i, j)].end()){
        point_to_neighbors[F(i, j)].push_back(neighbor);
      }
      neighbor = F(i, (j - 1 + F.cols()) % F.cols());
      if (std::find(point_to_neighbors[F(i, j)].begin(), point_to_neighbors[F(i, j)].end(), neighbor) == point_to_neighbors[F(i, j)].end()){
        point_to_neighbors[F(i, j)].push_back(neighbor);
      }
    }

    //face_point
    face_point[i] = accumulator / 4.0;
  }

  SV.resize(0, 3);
  SF.resize(0, 4);
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){

      Eigen::RowVector3d ver1 = update_point(point_to_adj_faces, face_point, point_to_neighbors, V, F(i, j));
      Eigen::RowVector3d ver2 = edge_point(V, edge_to_adj_faces, face_point, F(i, j), F(i, (j+1)%F.cols()));
      Eigen::RowVector3d ver3 = face_point[i];
      Eigen::RowVector3d ver4 = edge_point(V, edge_to_adj_faces, face_point, F(i, j), F(i, ((j-1)+F.cols())%F.cols()));

      //construct new sv and sf
      construct_faces(SV, SF, ver1, ver2, ver3, ver4);
    }
  }
  //recursive call
  catmull_clark(Eigen::MatrixXd(SV), Eigen::MatrixXi(SF), num_iters - 1, SV, SF);
  ////////////////////////////////////////////////////////////////////////////
}

Eigen::RowVector3d edge_point(const Eigen::MatrixXd &V,
std::unordered_map<std::string, std::vector<int>> &edge_to_adj_faces, 
std::unordered_map<int, Eigen::RowVector3d> &face_point, 
int p1, 
int p2){
  std::string key = std::to_string(p1) + "-" + std::to_string(p2);
  Eigen::RowVector3d edgepoint(0, 0, 0);
  for (int k: edge_to_adj_faces[key]){
     edgepoint += face_point[k];
  }
  edgepoint += V.row(p1);
  edgepoint += V.row(p2);
  return (edgepoint/4.0);
}

Eigen::RowVector3d update_point(std::unordered_map<int, std::vector<int>> &point_to_adj_faces, 
std::unordered_map<int, Eigen::RowVector3d> &face_point, 
std::unordered_map<int, std::vector<int>> &point_to_neighbors, 
const Eigen::MatrixXd &V,
int p){
  Eigen::RowVector3d old = V.row(p);
  Eigen::RowVector3d avg_face(0, 0, 0);
  for (int k: point_to_adj_faces[p]){
    avg_face += face_point[k];
  }
  avg_face /= (double)point_to_adj_faces[p].size();

  Eigen::RowVector3d avg_edge(0, 0, 0);
  for (int neighbor_idx: point_to_neighbors[p]){
    avg_edge += (V.row(p) + V.row(neighbor_idx))/2.0;
  }
  avg_edge /= (double)point_to_neighbors[p].size();

  double n = point_to_adj_faces[p].size();
  return (avg_face + 2.0 * avg_edge + (n - 3) * old) / n;
}

void construct_faces(Eigen::MatrixXd &SV, 
Eigen::MatrixXi &SF, 
Eigen::RowVector3d ver1, 
Eigen::RowVector3d ver2, 
Eigen::RowVector3d ver3, 
Eigen::RowVector3d ver4){
  Eigen::RowVector4i face_index(-1, -1, -1, -1);
  std::vector<Eigen::RowVector3d> l = {ver1, ver2, ver3, ver4};
  int counter = 0;
  for (auto vertex : l ){
    for (int k = 0; k < SV.rows(); k++){
      if (vertex.isApprox(SV.row(k))){
        face_index(counter) = k;
      }
    }
    if (face_index(counter) == -1){
      SV.conservativeResize(SV.rows() + 1, Eigen::NoChange);
      SV.row(SV.rows() - 1) = vertex;
      face_index(counter) = SV.rows() - 1;
    }
    counter++;
  }
  SF.conservativeResize(SF.rows() + 1, Eigen::NoChange);
  SF.row(SF.rows() - 1) = face_index;
}