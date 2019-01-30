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
  // Replace with your code here:
  Eigen::Vector3d rgb(0, 0, 0);
  rgb += (objects[hit_id]->material->ka.array()*Eigen::Vector3d(1.0, 1.0, 1.0).array()).matrix();

  Eigen::Vector3d p = ray.origin + t * ray.direction;
  for (int i = 0; i < lights.size(); i++){
    Eigen::Vector3d l_direction;
    double max_t;
    lights[i]->direction(p, l_direction, max_t);
    Ray light_ray;
    light_ray.origin = p;
    light_ray.direction = l_direction;

    int light_hit_id;
    double light_t;
    Eigen::Vector3d light_n;
    if (!first_hit(light_ray, 1.0e-6, objects, light_hit_id, light_t, light_n) || light_t >= max_t){
      Eigen::Vector3d h = (-ray.direction.normalized() + light_ray.direction.normalized()).normalized();
      rgb += (objects[hit_id]->material->kd.array()*lights[i]->I.array()).matrix()*fmax(0.0, n.dot(light_ray.direction));
      rgb += (objects[hit_id]->material->ks.array()*lights[i]->I.array()).matrix()*pow(fmax(0.0, n.dot(h)), objects[hit_id]->material->phong_exponent);
    }
  }
  return rgb;
  ////////////////////////////////////////////////////////////////////////////
}
