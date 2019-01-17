#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double max = std::max(std::max(r, g), b);
  double min = std::min(std::min(r, g), b);
  double delta = max - min;
  
  h = 0;
  s = 0;
  v = 0;
  ////////////////////////////////////////////////////////////////////////////
}
