#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////
  std::list<std::pair<std::shared_ptr<AABBTree>, std::shared_ptr<AABBTree> > > q;
  if (box_box_intersect(rootA->box, rootB->box)) {
      q.emplace_back(rootA, rootB);
  }
  
  while (!q.empty()) {
      const std::shared_ptr<AABBTree> nodeA = q.front().first;
      const std::shared_ptr<AABBTree> nodeB = q.front().second;
      q.pop_front();
      // both nodes are leaf nodes
      if (nodeA->num_leaves <= 2 && nodeB->num_leaves <= 2) {
          if (nodeA->left && nodeB->left && box_box_intersect(nodeA->left->box, nodeB->left->box)) {
              leaf_pairs.emplace_back(nodeA->left, nodeB->left);
          }
          if (nodeA->left && nodeB->right && box_box_intersect(nodeA->left->box, nodeB->right->box)) {
              leaf_pairs.emplace_back(nodeA->left, nodeB->right);
          }
          if (nodeA->right && nodeB->left && box_box_intersect(nodeA->right->box, nodeB->left->box)) {
              leaf_pairs.emplace_back(nodeA->right, nodeB->left);
          }
          if (nodeA->right && nodeB->right && box_box_intersect(nodeA->right->box, nodeB->right->box)) {
              leaf_pairs.emplace_back(nodeA->right, nodeB->right);
          }
      // A is a leaf node, but B is not
      } else if (nodeA->num_leaves <= 2) {
          if (box_box_intersect(nodeA->box, nodeB->left->box)) {
              q.emplace_back(nodeA, std::static_pointer_cast<AABBTree>(nodeB->left));
          }
          if (box_box_intersect(nodeA->box, nodeB->right->box)) {
              q.emplace_back(nodeA, std::static_pointer_cast<AABBTree>(nodeB->right));
          }
      // B is leaf node, but A is not
      } else if (nodeB->num_leaves <= 2) {
          if (box_box_intersect(nodeA->left->box, nodeB->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->left), nodeB);
          }
          if (box_box_intersect(nodeA->right->box, nodeB->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->right), nodeB);
          }
      // both are not leaf nodes
      } else {
          if (box_box_intersect(nodeA->left->box, nodeB->left->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->left), std::static_pointer_cast<AABBTree>(nodeB->left));
          }
          if (box_box_intersect(nodeA->left->box, nodeB->right->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->left), std::static_pointer_cast<AABBTree>(nodeB->right));
          }
          if (box_box_intersect(nodeA->right->box, nodeB->left->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->right), std::static_pointer_cast<AABBTree>(nodeB->left));
          }
          if (box_box_intersect(nodeA->right->box, nodeB->right->box)) {
              q.emplace_back(std::static_pointer_cast<AABBTree>(nodeA->right), std::static_pointer_cast<AABBTree>(nodeB->right));
          }
      }
  }
  // Add your code here
  // std::list<std::pair<std::shared_ptr<AABBTree>, std::shared_ptr<AABBTree>>> Q;
  // if (box_box_intersect(rootA->box, rootB->box)){
  //   Q.emplace_front(rootA, rootB);
  // }

  // while (!Q.empty()){
  //   std::shared_ptr<Object> node_A = Q.back().first;
  //   std::shared_ptr<Object> node_B = Q.back().second;
  //   Q.pop_back();

  //   std::shared_ptr<AABBTree> new_nodeA = std::dynamic_pointer_cast<AABBTree>(node_A);
  //   std::shared_ptr<AABBTree> new_nodeB = std::dynamic_pointer_cast<AABBTree>(node_B);
  //   if (!new_nodeA && !new_nodeB){
  //     leaf_pairs.emplace_back(node_A, node_B);
  //   }
  //   else if (!new_nodeA){
  //     if (box_box_intersect(node_A->box, new_nodeB->left->box)){
  //       Q.emplace_front(node_A, new_nodeB->left);
  //     }
  //     if (box_box_intersect(node_A->box, new_nodeB->right->box)){
  //       Q.emplace_front(node_A, new_nodeB->right);
  //     }
  //   }
  //   else if (!new_nodeB){
  //     if (box_box_intersect(new_nodeA->left->box, node_B->box)){
  //       Q.emplace_front(new_nodeA->left, node_B);
  //     }
  //     if (box_box_intersect(new_nodeA->right->box, node_B->box)){
  //       Q.emplace_front(new_nodeA->right, node_B);
  //     }
  //   }
  //   else{
  //     if (box_box_intersect(new_nodeA->left->box, new_nodeB->left->box)){
  //       Q.emplace_front(new_nodeA->left, new_nodeB->left);
  //     }
  //     if (box_box_intersect(new_nodeA->left->box, new_nodeB->right->box)){
  //       Q.emplace_front(new_nodeA->left, new_nodeB->right);
  //     }
  //     if (box_box_intersect(new_nodeA->right->box, new_nodeB->right->box)){
  //       Q.emplace_front(new_nodeA->right, new_nodeB->right);
  //     }
  //     if (box_box_intersect(new_nodeA->right->box, new_nodeB->left->box)){
  //       Q.emplace_front(new_nodeA->right, new_nodeB->left);
  //     }
  //   }
  // }
  ////////////////////////////////////////////////////////////////////////////
}
