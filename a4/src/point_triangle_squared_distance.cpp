#include "point_triangle_squared_distance.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define CLAMP(x, upper, lower) (MIN(upper, MAX(x, lower)))

double point_triangle_squared_distance(
  const Eigen::RowVector3d & query,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  Eigen::RowVector3d & bary)
{
  ////////////////////////////////////////////////////////////////////////////
  //Source http://web.mit.edu/ehliu/Public/Darmofal/DistancePoint3Triangle3.pdf
  // Replace with your code here
  Eigen::Vector3d query_(query);
  Eigen::Vector3d A_(A);
  Eigen::Vector3d B_(B);
  Eigen::Vector3d C_(C);

  Eigen::Vector3d edge0 = B_ - A_;
  Eigen::Vector3d edge1 = C_ - A_;
  Eigen::Vector3d v0 = A_ - query_;

  double a = edge0.dot(edge0);
  double b = edge0.dot(edge1);
  double c = edge1.dot(edge1);
  double d = edge0.dot(v0);
  double e = edge1.dot(v0);

  double det = a*c - b*b;
  double beta = b*e - c*d;
  double gamma = b*d - a*e;

  if (beta + gamma < det){
    if (beta < 0.0){
      if (gamma < 0.0){
        if (d < 0.0){
          beta = CLAMP(-d/a, 0.0, 1.0);
          gamma = 0.0;
        }
        else{
          beta = 0.0;
          gamma = CLAMP(-e/c, 0.0, 1.0);
        }
      }
      else{
        beta = 0.0;
        gamma = CLAMP(-e/c, 0.0, 1.0);
      }
    }
    else if (gamma < 0.0){
      beta = CLAMP(-d/a, 0.0, 1.0);
      gamma = 0.0;
    }
    else{
      double invDet = 1.0/det;
      beta *= invDet;
      gamma *= invDet;
    }
  }
  else{
    if (beta < 0.0){
      double temp0 = b + d;
      double temp1 = c + e;
      if (temp1 > temp0){
        double numberator = temp1 - temp0;
        double denomenator = a - 2 * b + c;
        beta = CLAMP(numberator/denomenator, 0.0, 1.0);
        gamma = 1 - beta;
      }
      else{
        beta = CLAMP(-e/c, 0.0, 1.0);
        gamma = 0.0;
      }
    }
    else{
      double numberator = c + e - b - d;
      double denomenator = a - 2 * b + c;
      beta = CLAMP(numberator/denomenator, 0.0, 1.0);
      gamma = 1.0 - beta;
    }
  }

  Eigen::Vector3d P = A_ + beta * edge0 + gamma * edge1;
  bary = {1-beta-gamma, beta, gamma};
  return (P - query_).squaredNorm();
  ////////////////////////////////////////////////////////////////////////////
}
