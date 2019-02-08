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
  const auto comparator = [](const std::pair<double, std::shared_ptr<AABBTree>> node1, const std::pair<double, std::shared_ptr<AABBTree>> node2) -> bool {
      return node1.first > node2.first;
  };
  std::priority_queue<std::pair<double, std::shared_ptr<AABBTree>>, std::vector<std::pair<double, std::shared_ptr<AABBTree>>>, decltype(comparator)> q(comparator);
  
  sqrd = std::numeric_limits<double>::infinity();
  q.emplace(point_box_squared_distance(query, root->box), root);
  while (!q.empty()) {
      const double d_s = q.top().first;
      const std::shared_ptr<AABBTree> node = q.top().second;
      q.pop();
      if (d_s < sqrd) {
          // the current node is a leaf
          if (node->num_leaves <= 2) {
              double sqrd_;
              std::shared_ptr<Object> descendant_;
              // calculate the distance between the query point and the left object, and compare it to the current global minimum found
              if (node->left && node->left->point_squared_distance(query, min_sqrd, max_sqrd, sqrd_, descendant_) && sqrd_ < sqrd) {
                  sqrd = sqrd_;
                  descendant = node->left;
              }
              // calculate the distance between the query point and the right object, and compare it to the current global minimum found
              if (node->right && node->right->point_squared_distance(query, min_sqrd, max_sqrd, sqrd_, descendant_) && sqrd_ < sqrd) {
                  sqrd = sqrd_;
                  descendant = node->right;
              }
          // push the left and right children into the queue
          } else {
              q.emplace(point_box_squared_distance(query, node->left->box), std::static_pointer_cast<AABBTree>(node->left));
              q.emplace(point_box_squared_distance(query, node->right->box), std::static_pointer_cast<AABBTree>(node->right));
          }
      }
  }
  return descendant != NULL;
  // Replace with your code here
  // auto cmp = [](std::pair<double, std::shared_ptr<AABBTree>> n1, std::pair<double, std::shared_ptr<AABBTree>> n2){return n1.first > n2.first;};
  // std::priority_queue<std::pair<double, std::shared_ptr<AABBTree>>, std::vector<std::pair<double, std::shared_ptr<AABBTree>>>, decltype(cmp)> q(cmp);
  
  // double minimum = std::numeric_limits<double>::infinity();
  // std::shared_ptr<Object> cur_descendant;
  // q.emplace(point_box_squared_distance(query, root->box), root);
  // while (!q.empty()){
  //   double distance = q.top().first;
  //   std::shared_ptr<Object> n = q.top().second;
  //   q.pop();
  //   if (distance < minimum){
  //     std::shared_ptr<AABBTree> new_n = std::dynamic_pointer_cast<AABBTree>(n);
  //     double cur_distance;
  //     if (!new_n && n->point_squared_distance(query, min_sqrd, max_sqrd, cur_distance, cur_descendant)){
  //       if (cur_distance < minimum){
  //         minimum = cur_distance;
  //         cur_descendant = new_n;
  //       }
  //     }
  //     else{
  //       double d_l = point_box_squared_distance(query, new_n->left->box);
  //       q.emplace(d_l, new_n->left);
  //       double d_r = point_box_squared_distance(query, new_n->right->box);
  //       q.emplace(d_r, new_n->right);
  //     }
  //   }
  // }
  // sqrd = minimum;
  // descendant = cur_descendant;
  // if (descendant){
  //   return true;
  // }
  // return false;
  ////////////////////////////////////////////////////////////////////////////
}
