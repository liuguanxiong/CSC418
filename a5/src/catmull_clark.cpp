#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include <list>
#include <string>

template<typename T>
struct matrix_hash : std::unary_function<T, size_t> {
  std::size_t operator()(T const& matrix) const {
    // Note that it is oblivious to the storage order of Eigen matrix (column- or
    // row-major). It will give you the same hash value for two different matrices if they
    // are the transpose of each other in different storage order.
    size_t seed = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
      auto elem = *(matrix.data() + i);
      seed ^= std::hash<typename T::Scalar>()(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

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
  
  std::unordered_map<std::string, std::list<int>> edgepoint_idx_to_face;
  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < F.cols(); j++){
      std::string k;
      if (F(i, j) < F(i, (j + 1) % F.cols())){
        k = std::to_string(F(i, j)) + "-" + std::to_string(F(i, (j + 1) % F.cols()));
      }
      else{
        k = std::to_string(F(i, (j + 1) % F.cols())) + "-" + std::to_string(F(i, j));
      }
      edgepoint_idx_to_face[k].emplace_back(i);
    }
  }

  
  SV = V;
  SF = F;
  ////////////////////////////////////////////////////////////////////////////
}
