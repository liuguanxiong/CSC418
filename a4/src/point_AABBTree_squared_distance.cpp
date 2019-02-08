#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  auto cmp = [](std::pair<double, std::shared_ptr<AABBTree>> n1, std::pair<double, std::shared_ptr<AABBTree>> n2){return n1.first > n2.first;};
  std::priority_queue<std::pair<double, std::shared_ptr<AABBTree>>, std::vector<std::pair<double, std::shared_ptr<AABBTree>>>, decltype(cmp)> q(cmp);

  double minimum = std::numeric_limits<double>::infinity();
  std::shared_ptr<Object> cur_descendant;
  double cur_distance;
  q.emplace(point_box_squared_distance(query, root->box), root);
  while (!q.empty()){
    double distance = q.top().first;
    std::shared_ptr<AABBTree> n = q.top().second;
    q.pop();
    if (distance < minimum){
      if (n->num_leaves <= 2){
        if (n->left && n->left->point_squared_distance(query, min_sqrd, max_sqrd, cur_distance, cur_descendant)){
          if (cur_distance < minimum){
            minimum = cur_distance;
            descendant = n->left;
          }
        }
        if (n->right && n->right->point_squared_distance(query, min_sqrd, max_sqrd, cur_distance, cur_descendant)){
          if (cur_distance < minimum){
            minimum = cur_distance;
            descendant = n->right;
          }
        }
      }
      else{
        q.emplace(point_box_squared_distance(query, n->left->box), std::static_pointer_cast<AABBTree>(n->left));
        q.emplace(point_box_squared_distance(query, n->right->box), std::static_pointer_cast<AABBTree>(n->right));
      }
    }
  }
  sqrd = minimum;
  if (descendant){
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
