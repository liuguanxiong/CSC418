#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>
#include <math.h>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////
  // Source: https://stackoverflow.com/questions/9489736/catmull-rom-curve-with-no-cusps-and-no-self-intersections/19283471#19283471
  // Replace with your code

  //circulating keyframes
  t = fmod(t, keyframes.back().first);

  //find closest four points
  for (int i = 0; i < keyframes.size(); i++){
    if (keyframes[i].first > t){
      break;
    }
  }

  if (i == 0){
    return Eigen::Vector3d(0, 0, 0);
  }

  //cosine interpolation for extreme segments
  if (i - 2 < 0 || i == keyframes.size() - 1){
    Eigen::Vector3d P0, P1;
    P0 = keyframes[i-1].second;
    P1 = keyframes[i].second;
    double t0, t1;
    t0 = keyframes[i-1].first;
    t1 = keyframes[i].first;

    double mu = (t - t0)/(t1 - t0);
    double mu2 = (1 - cos(mu * M_PI))/2;
    return (P0 * (1 - mu2) + P1 * mu2);
  }
  Eigen::Vector3d P0, P1, P2, P3;
  P0 = keyframes[i-2].second;
  P1 = keyframes[i-1].second;
  P2 = keyframes[i].second;
  P3 = keyframes[i+1].second;

  double t0, t1, t2, t3;
  t0 = keyframes[i-2].first;
  t1 = keyframes[i-1].first;
  t2 = keyframes[i].first;
  t3 = keyframes[i+1].first;

  Eigen::Vector3d L01 = (t1 - t)/(t1 - t0) * P0 + (t - t0)/(t1 - t0) * P1;
  Eigen::Vector3d L12 = (t2 - t)/(t2 - t1) * P1 + (t - t1)/(t2 - t1) * P2;
  Eigen::Vector3d L23 = (t3 - t)/(t3 - t2) * P2 + (t - t2)/(t3 - t2) * P3;

  Eigen::Vector3d L012 = (t2 - t)/(t2 - t0) * L01 + (t - t0)/(t2 - t0) * L12;
  Eigen::Vector3d L123 = (t3 - t)/(t3 - t1) * L12 + (t - t1)/(t3 - t1) * L23;

  Eigen::Vector3d C12 = (t2 - t)/(t2 - t1) * L012 + (t - t1)/(t2 - t1) * L123;
  return C12;
  /////////////////////////////////////////////////////////////////////////////
}
