#include "AABBTree.h"
#include "insert_box_into_box.h"

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int N = objects.size();
  if (N == 0){
    this->left = NULL;
    this->right = NULL;
  }
  else if (N == 1){
    this->left = objects[0];
    this->right = NULL;
    insert_box_into_box(this->left->box, this->box);
  }
  else if (N == 2){
    this->left = objects[0];
    this->right = objects[1];
    insert_box_into_box(this->left->box, this->box);
    insert_box_into_box(this->right->box, this->box);
  }
  else{
    for (int i = 0; i < objects.size(); i++){
      insert_box_into_box(objects[i]->box, this->box);
    }

    //find longest axis
    int max_i = 0;
    double longest = this->box.max_corner(max_i) - this->box.min_corner(max_i);
    for (int i = 1; i < 3; i++){
      double distance = this->box.max_corner(i) - this->box.min_corner(i);
      if (distance > longest){
        longest = distance;
        max_i = i;
      }
    }
    double m = 0.5*(box.max_corner(max_i)+box.min_corner(max_i));

    std::vector<std::shared_ptr<Object>> left;
    std::vector<std::shared_ptr<Object>> right;
    for (int i = 0; i < objects.size(); i++){
      if (objects[i]->box.center()(max_i) < m){
        left.emplace_back(objects[i]);
      }
      else{
        right.emplace_back(objects[i]);
      }
    }

    if (left.size() != 0 && right.size() == 0){
      this->left = std::make_shared<AABBTree>(left, a_depth+1);
      this->right = NULL;
    }
    else if (left.size() == 0 && right.size() != 0){
      this->right = std::make_shared<AABBTree>(right, a_depth+1);
      this->left = NULL;
    }
    else{
      this->left = std::make_shared<AABBTree>(left, a_depth+1);
      this->right = std::make_shared<AABBTree>(right, a_depth+1);
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}

bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  if (ray_intersect_box(ray, this->box, min_t, max_t, t)){
    
  }
  t = 0;
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
