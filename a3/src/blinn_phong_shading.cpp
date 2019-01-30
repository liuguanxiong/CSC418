#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d rgb(0, 0, 0);
  rgb += (objects[hit_id]->material->ka.array()*Eigen::Vector3d(1.0, 1.0, 1.0).array()).matrix();

  Eigen::Vector3d p = ray.origin + t * ray.direction;
  for (int i = 0; i < lights.size(); i++){
    
  }
  // Replace with your code here:
  return Eigen::Vector3d(0,0,0);
  ////////////////////////////////////////////////////////////////////////////
}
