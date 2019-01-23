#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int min_index = -1;
  double min_distance = std::numeric_limits<double>::infinity();

  for (int i = 0; i < objects.size(); i++){
    
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

