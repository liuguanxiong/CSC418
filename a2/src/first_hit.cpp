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
  Eigen::Vector3d min_n;

  for (int i = 0; i < objects.size(); i++){
    double distance;
    Eigen::Vector3d normal;
    if (objects[i]->intersect(ray, min_t, distance, normal)){
      if (distance < min_distance):
      min_index = i;
      min_distance = distance;
      min_n = normal;
    }
  }

  if (min_index != -1){
    hit_id = min_index;
    t = min_distance;
    n = min_n;
    return true;
  }
  else{
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}

