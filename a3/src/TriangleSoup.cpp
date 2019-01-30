#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int id;
  if (first_hit(ray, min_t, triangles, id, t, n)){
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}



