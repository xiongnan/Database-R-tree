
#ifndef RTREE_H
#define RTREE_H

#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include "mbr.h"
#include "pf.h"
#include "r-tree.h"

using namespace std;

class RTree {

  //node structure
  //(1) MBR
  //(2) Parent id (root's parent is -1)
  //(3) Num of Child
  //(4) 1st child id
  //(5) ....

  //object structure
  //(1) MBR
  //(2) Parent id
  //(3) object id (real object id * -1)


 public:
  RTree(PF_FileHandle fileHandle);
  void RTree::createTree();
  void insertEntry(int object_id, MBR mbr);
  void DeleteEntry(int object_id, MBR mbr);
  

  int m = 5;
  int M = 10;
  
 private:
  
  // Store the root node id
  int root_node;

  // The file handle used for this index
  PF_FileHandle fh;

  /* InsertEntry-related methods */
  // Choose a leaf node to insert
  int chooseLeaf(MBR object);
  // Determine if a node is leaf node
  bool isLeaf(int node);
  // Determine if a node is object
  bool isObject(int node);
  // Calculate the expended size if adding new_mbr to node
  float calculateExpand(MBR object, int node);
  // Expand mbr recursively to root
  void recursiveExpend(int node, MBR mbr);
  // Expand node by adding mbr
  void expand(int node, MBR mbr);
  // Adjust Tree by checking from node
  void adjustTree(int L, int LL);
  // Split node into two nodes
  int split(int node);
  // Find best split
  set<int> split_two_groups(int numOfChild, int * childList, set<int> & all_child);
  // Split helper for split_two_groups
  int split_helper(int numOfChild, int * childList, int curr, set<int> &temp, set<int> & best);
  // Merge the mbr of two node and return
  MBRR merge_two_nodes(int node1, int node2);
  // Merge a group of node into a mbr
  MBR merge_group_mbr(set<int> nodes);
  // Get complement of a set of nodes
  set<int> get_complement(int numOfChild, int * all_child, set<int> & A);
  
  
  /* DeleteEntry-related methods */

  // Find all overlap node with mbr
  set<int> findOverlap(MBR mbr);
  // Determine if node1 is overlap with mbr2
  bool isOverlap(int node1, MBR mbr2);
  // Adjust tree after delete
  void condenseTree(int L);
  // Merge a group of node into a mbr
  MBR merge_group_mbr(int * nodes, int n);
  // Get node's level
  int getLevel(int N);
  // Insert node to level of tree
  void insertToLevel(int node, int level);



  // Get and Set for Node

  // Create a new node
  int createNewNode();
  // Node data pointer
  char ** getNodeData(int node);

  // MBR-related
  MBR getMBR(int node);
  void setMBR(int node, MBR mbr);

  // Parent-related
  int getParent(int node);
  void setParent(int node,int parent);

  // Child-related
  void getChildList(int node, int & numOfChild, int *& childList);
  void addChild(int node, int child_id);
  void removeChild(int node, int child_id);
  int getNumOFChild(int node);
  void setNumOFChild(int node, int numOfChild);


  // Object-related
  int getObjectID(int node);
  void setObjectID(int node,int object_id);

  
};


#endif
