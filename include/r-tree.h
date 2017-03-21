
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

  /*node structure
    (1) MBR.x1
    (2) MBR.y1
    (3) MBR.x2
    (4) MBR.y2
    (5) Parent id (root's parent is -1)
    (6) Num of Child
    (7) 1st child id
    (8) ....
  */

  /* object structure
     (1) MBR.x1 
     (2) MBR.y1 
     (3) MBR.x2
     (4) MBR.y2
     (5) Parent id
     (6) object id (real object id * -1)
  */

 public:
  RTree(PF_FileHandle fileHandle);
  void createTree();
  void insertEntry(int object_id, MBR mbr);
  void deleteEntry(int object_id, MBR mbr);
  

  // For debug                                                                                       
  void printNode(int node);

  int m;
  int M;
  
  //private:
  
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
  void recursiveMBRAdjust(int node);
  // Adjust Tree by checking from node
  void adjustTree(int node);
  // Split node into two nodes
  int split(int node);
  // Find best split
  set<int> split_two_groups(int numOfChild, int * childList, set<int> & all_child);
  // Split helper for split_two_groups
  set<int> split_helper(int numOfChild, int * childList, int curr, set<int> &temp);
  // Get area of a split
  int get_two_splited_area(int numOfChild, int * childList, set<int> &temp);
  // Merge the mbr of two node and return
  MBR merge_two_nodes(int node1, int node2);
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
  char * getNodeData(int node);

  // MBR-related
  MBR getMBR(int node);
  void setMBR(int node, MBR mbr);
  int getMBRArea(MBR mbr);

  // Parent-related
  int getParent(int node);
  void setParent(int node,int parent);

  // Child-related
  void getChildList(int node, int & numOfChild, int *& childList);
  void addChild(int node, int child_id);
  void removeChild(int node, int child_id);
  int getNumOfChild(int node);
  void setNumOfChild(int node, int numOfChild);


  // Object-related
  int getObjectID(int node);
  void setObjectID(int node,int object_id);

};


#endif
