#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  //Hint:
  V.resize(8,3);
  F.resize(6,4);
  UV.resize(14,2);
  UF.resize(6,4);
  NV.resize(6,3);
  NF.resize(6,4);

  V << 0,0,0,
       0,1,0,
       1,1,0,
       1,0,0,
       0,0,1,
       0,1,1,
       1,1,1,
       1,0,1;

  F << 0,1,2,3,
       0,4,5,1,
       1,5,6,2,
       2,6,7,3,
       0,3,7,4,
       4,7,6,5;

  
}
