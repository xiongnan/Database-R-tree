
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

  void insertEntry(int object_id, MBR mbr);
  void DeleteEntry(int object_id, MBR mbr);
  int chooseLeaf(MBR object);

  int m;
  int M;
  
 private:
  int root_node;
  PF_FileHandle fh;
  float calculateExpand(MBR object, int node);
  MBR merge_two_nodes(int node1, int node2);

  void getChildList(int node, int & numOfChild, int *& childList);
  void addChild(int node, int child_id);
  void removeChild(int node, int child_id);
  int getNumOFChild(int node);

  int getParent(int node);
  void setParent(int node,int parent);

  MBR getMBRbyNode(int node);
  void setMBRbyNode(int node, MBR mbr);
  MBR merge_group_mbr(set<int> nodes);
  MBR merge_group_mbr(int * nodes, int n);
  void expand(MBR object, int node);

  bool isLeaf(int node);
  bool isObject(int node);
  char ** getNodeData(int node);

  void adjustTree(MBR object, int node);
  void adjustTree(int L, int LL);
  void isFull(int node);
  void splitNode(int node, void * pData, int nodeL, int nodeLL);
  int split(int node);
  set<int> get_complement(int numOfChild, int * all_child, set<int> & A);
  int split_helper(int numOfChild, int * childList, int curr, set<int> &temp, set<int> & best);
  set<int> split_two_groups(int numOfChild, int * childList, set<int> & all_child);
 
  int getObjectID(int node);

  int getLevel(int N);

  void insertToLevel(int node, int level);

  void condenseTree(int L);

  set<int> findOverlap(MBR mbr);

  bool isOverlap(int node1, MBR mbr2);
  
};


#endif
