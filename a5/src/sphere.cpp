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
  int total_vertices = (num_faces_u + 1) * (num_faces_v + 1);
  V.resize(total_vertices, 3);
  F.resize(total_faces, 4);
  UV.resize(total_vertices, 2);
  UF.resize(total_faces, 4);
  NV.resize(total_vertices, 3);
  NF.resize(total_faces, 4);

  int count = 0;
  int i, j;
  for (i = 0; i < num_faces_u; i++){
    for (j = 0; j < num_faces_v; j++){

      int ver1 = i * (num_faces_v + 1) + j;
      int ver2 = (i+1) * (num_faces_v + 1) + j;
      int ver3 = ver2 + 1;
      int ver4 = ver1 + 1;

      F.row(count) = Eigen::RowVector4i(ver1, ver2, ver3, ver4);
      UF.row(count) = Eigen::RowVector4i(ver1, ver2, ver3, ver4);
      NF.row(count) = Eigen::RowVector4i(ver1, ver2, ver3, ver4);
      count++;
    }
  }

  count = 0;
  for (i = 0; i < num_faces_u + 1; i++){
    for (j = 0; j < num_faces_v + 1; j++){

      double x, y, z, phi, theta;
      theta = static_cast<double>(i) / num_faces_u * 2.0 * M_PI;
      phi = static_cast<double>(j) / num_faces_v * M_PI;
      x = -sin(phi) * cos(theta);
      y = -sin(phi) * sin(theta);
      z = -cos(phi);

      V.row(count) = Eigen::RowVector3d(x, y, z);
      UV.row(count) = Eigen::RowVector2d(static_cast<double>(i) / num_faces_u, static_cast<double>(j) / num_faces_v);
      NV.row(count) = Eigen::RowVector3d(x, y, z);
      count++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
