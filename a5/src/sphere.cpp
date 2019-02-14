#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  int total_faces = num_faces_u * num_faces_v;
  V.resize(total_faces, 3);
  F.resize(total_faces, 4);
  UV.resize(total_faces, 2);
  UF.resize(total_faces, 4);
  NV.resize(total_faces, 3);
  NF.resize(total_faces, 4);

  int count = 0;
  for (int i = 0; i < num_faces_u; i++){
    for (int j = 0; j < num_faces_v; j++){

      double x, y, z, phi, theta;
      phi = i / num_faces_u * M_PI;
      theta = j / num_faces_v * 2 * M_PI;
      x = sin(phi) * cos(theta);
      y = sin(phi) * sin(theta);
      z = cos(phi);

      int ver1 = i * (num_faces_v)

      V.row(count) = Eigen::RowVector3d(x, y, z);
      UV.row(count) = Eigen::RowVector3d(i / num_faces_u, j / num_faces_v);
      NV.row(count) = Eigen::RowVector3d(x, y, z);
      count++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
