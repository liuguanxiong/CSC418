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
  // Add your code here
  std::list<<std::pair<std::shared_ptr<AABBTree>, std::shared_ptr<AABBTree>> Q;
  if (box_box_intersect(rootA->box, rootB->box)){
    Q.emplace_front(rootA, rootB);
  }

  while (!Q.empty()){
    std::shared_ptr<AABBTree> node_A = Q.back().first;
    std::shared_ptr<AABBTree> node_B = Q.back().second;
    Q.pop_back();

    std::shared_ptr<Object> new_nodeA = std::dynamic_pointer_cast<Object>(node_A);
    std::shared_ptr<Object> new_nodeB = std::dynamic_pointer_cast<Object>(node_B);
    if (new_nodeA && new_nodeB){
      leaf_pairs.emplace_back(new_nodeA, new_nodeB);
    }
    else if (new_nodeA){
      if (box_box_intersect(new_nodeA->box, node_B->left->box)){
        Q.emplace_front(new_nodeA, node_B->left);
      }
      if (box_box_intersect(new_nodeA->box, node_B->right->box)){
        Q.emplace_front(new_nodeA, node_B->right);
      }
    }
    else if (new_nodeB){
      if (box_box_intersect(node_A->left->box, new_nodeB->box)){
        Q.emplace_front(node_A->left, new_nodeB);
      }
      if (box_box_intersect(node_A->right->box, new_nodeB->box)){
        Q.emplace_front(node_A->right, new_nodeB);
      }
    }
    else{
      if (box_box_intersect(node_A->left->box, node_B->left->box)){
        Q.emplace_front(node_A->left, node_B->left);
      }
      if (box_box_intersect(node_A->left->box, node_B->right->box)){
        Q.emplace_front(node_A->left, node_B->right);
      }
      if (box_box_intersect(node_A->right->box, node_B->right->box)){
        Q.emplace_front(node_A->right, node_B->right);
      }
      if (box_box_intersect(node_A->right->box, node_B->left->box)){
        Q.emplace_front(node_A->right, node_B->left);
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
