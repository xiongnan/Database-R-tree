#include <set>
#include <iostream>
#include <algorithm> 
#include <stack> 
#include <vector>
#include "mbr.h"
#include "pf.h"
#include "r-tree.h"
#include "helper.h"
#include "limits.h"
#include "float.h"
using namespace std;

RTree::RTree(PF_FileHandle fileHandle)
{
  // Get file handle for this 
  fh = fileHandle;
  
}

void RTree::createTree()
{
  // Create initial root node
  root_node = createNewNode();

  // Set initial mbr
  MBR new_root_mbr(0,0,0,0);
  setMBR(root_node, new_root_mbr);

  // Set root's parent to be -1
  setParent(root_node, -1);

  // Set number of Child to be 0
  setNumOFChild(root_node, 0);

}

void RTree::insertEntry(int object_id, MBR mbr)
{
  cout << "insert:" << object_id << endl;
  int position;
  position = chooseLeaf(mbr);
  cout << "found leaf: " << position << endl;

  // Create a new node
  int new_node_id = createNewNode();
  setMBR(new_node_id, mbr);
  setParent(new_node_id, position);
  setObjectID(new_node_id,-1*object_id);

  // Add new node to child list
  addChild(position, new_node_id);

  // Expend mbr all the way to root
  recursiveExpend(position, mbr);

  // Split if necessary
  adjustTree(position);
}

// Choose a leaf node to insert
int RTree::chooseLeaf(MBR object)
{
  int curr_node = root_node;
  while(!isLeaf(curr_node)){
    int childNum;
    int * childList;
    getChildList(curr_node, childNum, childList);
    int min_child = 0;
    int min_area = INT_MAX;
    for (int i = 0 ;i < childNum ; i++){
      int temp = calculateExpand(object, childList[i]);
      if (temp < min_area){
	       min_child = i;
	       min_area = temp;
      }
    }
    curr_node = min_child;
  }
  return curr_node;
}


// Determine if a node is object
bool RTree::isObject(int node)
{
  // If object id < 0, then it's object
  // Otherwise that number is number of child 
  return getObjectID(node) < 0;
}

// Determine if a node is leaf node
bool RTree::isLeaf(int node)
{
  int numOfChild;
  int * childList;
  getChildList(node, numOfChild, childList);

  cout << "num of child:"  << numOfChild << endl;
  if (numOfChild == 0) //if it is new root
  {
    return true;
  } else {
    // See if 1st child is object
    return isObject(childList[0]);
  }
  
}

// Calculate the expended size if adding new_mbr to node
float RTree::calculateExpand(MBR new_mbr, int node)
{
  MBR mbr = getMBR(node);
  float new_x1 = min(mbr.x1, new_mbr.x1);
  float new_y1 = min(mbr.y1, new_mbr.y1);
  float new_x2 = max(mbr.x2, new_mbr.x2);
  float new_y2 = max(mbr.y2, new_mbr.y2);
  float new_area = (new_x2-new_x1) * (new_y2-new_y1);
  float old_area = (mbr.x2-mbr.x1) * (mbr.y2-mbr.y1);
  return new_area-old_area;  

}

// Expand mbr recursively to root
void RTree::recursiveExpend(int node, MBR mbr)
{
  while (node != -1)
  {
    expand(node, mbr);
    node = getParent(node);
  }
}

// Expand node by adding mbr
void RTree::expand(int node, MBR mbr)
{
  MBR node_mbr = getMBR(node);
  node_mbr.x1 = min(node_mbr.x1, mbr.x1);
  node_mbr.y1 = min(node_mbr.y1, mbr.y1);
  node_mbr.x2 = max(node_mbr.x2, mbr.x2);
  node_mbr.y2 = max(node_mbr.y2, mbr.y2);
  setMBR(node, node_mbr);
}

// Adjust Tree by checking from node
void RTree::adjustTree(int node)
{
  while (node != root_node && getNumOFChild(node) >= M)
  {
    int new_node_id = split(node);
    node = getParent(node);

  }
  if (node == root_node && getNumOFChild(node) >= M) {
    int new_node = split(node);
    int new_root = createNewNode();
    MBR new_root_mbr = merge_two_nodes(new_node, node);
    setMBR(new_root,new_root_mbr);
    setParent(new_root, -1);
    addChild(new_root, node);
    addChild(new_root, new_node);
    setParent(node, new_root);
    setParent(new_node, new_root);
  }
}

// Merge the mbr of two node and return
MBR RTree::merge_two_nodes(int node1, int node2)
{
  MBR mbr1 = getMBR(node1);
  MBR mbr2 = getMBR(node2);
  MBR result;
  result.x1 = min(mbr1.x1, mbr2.x1);
  result.y1 = min(mbr1.y1, mbr2.y1);
  result.x2 = max(mbr1.x2, mbr2.x2);
  result.y2 = max(mbr1.y2, mbr2.y2);
  return result;
}



// Split node into two nodes
int RTree::split(int node)
{
  int numOfChild;
  int * childList;
  //get child of node
  getChildList(node, numOfChild,childList);

  //[algorithm]
  //split childlist into 2 group: A, B
  set<int> all_child;
  for (int i =0; i <numOfChild; i++)
  {
    all_child.insert(childList[i]);
  }
  set<int> A = split_two_groups(numOfChild, childList, all_child);
  set<int> B = get_complement(numOfChild, childList, A);


  //update node's child to A
  //update mbr of node
  MBR mbr = merge_group_mbr(A);
  setMBR(node, mbr);
  setNumOFChild(node, A.size());
  for (set<int>::iterator it=A.begin();it!=A.end();++it){
    addChild(node, *it);
  }

  //create a new node
  int new_node = createNewNode();
  setParent(new_node, getParent(node));
  mbr = merge_group_mbr(B);
  setMBR(new_node, mbr);
  setNumOFChild(new_node, B.size());

  //update node's child to B
  for (set<int>::iterator it=B.begin();it!=B.end();++it){
    setParent(*it, new_node);
    addChild(new_node, *it);
  }
   //update new node's parent's child list
  addChild(getParent(node), new_node);
  
  return new_node;
}

// Find best split
set<int> RTree::split_two_groups(int numOfChild, int * childList, set<int> & all_child)
{
  set<int> temp; 
  set<int> best; 
  split_helper(numOfChild, childList, 0, temp, best);
  return best;
}

// Split helper for split_two_groups
int RTree::split_helper(int numOfChild, int * childList, int curr, set<int> &temp, set<int> & best)
{
  if (curr == numOfChild) {
    //evaluate current split
    set<int> comp = get_complement(numOfChild, childList, temp);
    //calculate area of comp and temp
    MBR mbr1 = merge_group_mbr(comp);
    MBR mbr2 = merge_group_mbr(temp);
    int area1 = (mbr1.x2 - mbr1.x1) * (mbr1.y2 - mbr1.y1);
    int area2 = (mbr2.x2 - mbr2.x1) * (mbr2.y2 - mbr2.y1);
    return area1 + area2;
  }
  set<int> best1;
  set<int> best2;
  //choose curr
  temp.insert(childList[curr]);
  int area1 = split_helper(numOfChild, childList, curr + 1, temp, best1);
  //not choose curr
  temp.erase(childList[curr]);
  int area2 = split_helper(numOfChild, childList, curr + 1, temp, best2);

  if (area1 < area2) {

    best = best1;
    return area1;
  } else {
    best = best2;
    return area2;
  }

}


// Merge a group of node into a mbr
MBR RTree::merge_group_mbr(set<int> nodes)
{
  MBR mbr;
  float new_x1 = FLT_MAX ;
  float new_y1 = FLT_MAX ;
  float new_x2 = FLT_MIN ;
  float new_y2 = FLT_MIN ;
  for (set<int>::iterator it=nodes.begin();it!=nodes.end();++it){
    MBR cur = getMBR(*it);
    new_x1 = min(new_x1,cur.x1);
    new_y1 = min(new_y1,cur.y1);
    new_x2 = max(new_x2,cur.x2);
    new_y2 = max(new_y2,cur.y2);
  }
  mbr.x1=new_x1;
  mbr.y1=new_y1;
  mbr.x2=new_x2;
  mbr.y2=new_y2;
  return mbr;
}

// Get complement of a set of nodes
set<int> RTree::get_complement(int numOfChild, int * all_child, set<int> & A)
{
  set<int> B;
  for (int i = 0; i < numOfChild; i++)
  {
    if (A.find(all_child[i]) == A.end())
    {
      B.insert(all_child[i]);
    }
  }
  return B;
}









void RTree::DeleteEntry(int object_id, MBR mbr){
  int target_node_id = -1;
  set<int> all_overlap_object = findOverlap(mbr);
  for (set<int>::iterator it=all_overlap_object.begin();it!=all_overlap_object.end();++it){
    int temp = getObjectID(*it);
    if (temp == object_id) {
      target_node_id = *it;
    }
  }
  if (target_node_id == -1) {
    return;
  }

  removeChild(getParent(target_node_id), target_node_id);
  condenseTree(getParent(target_node_id));
  
  int numOfChild = 0;
  int * childList;
  getChildList(root_node,numOfChild,childList);
  if (numOfChild == 1)
  {
    root_node = childList[0];
  }

}

// Find all overlap node with mbr
set<int> RTree::findOverlap(MBR mbr){
  set<int> result;
  stack<int> s;
  if (isOverlap(root_node, mbr)) {
    s.push(root_node);
  }
  while (!s.empty()){
    int temp = s.top();
    s.pop();
    //visit temp;

    int numOfChild;
    int * childList;
    getChildList(temp, numOfChild, childList);
   
    for (int i = 0; i < numOfChild; i++) {
        if (isOverlap(childList[i], mbr)){
          if (isLeaf(temp)){
            result.insert(childList[i]);
          } else { //not leaf
            s.push(childList[i]);
          }
        }
    }
  }
  return result;
}

// Determine if node1 is overlap with mbr2
bool RTree::isOverlap(int node1, MBR mbr2)
{
  MBR mbr1 = getMBR(node1);

  //  1x1 ... 1x2   2x1 .... 2x2
  //  2x1 ... 2x2   1x1 .... 1x2
  if (mbr1.x2 < mbr2.x1 || mbr2.x2 < mbr1.x1){
    return false;
  }

  if (mbr1.y2 < mbr2.y1 || mbr1.y1 > mbr2.y2){
    return false;
  }

  return true;
}

// Adjust tree after delete
void RTree::condenseTree(int L){
  int N = L;
  vector<int> level;
  vector<set<int>> Q;
  while (N != root_node){
    int P = getParent(N);

    int numOfChild = 0;
    int * childList;
    getChildList(root_node, numOfChild, childList);

    if (numOfChild < m) {
      if (N == L) {
        set<int> tQ;
        level.push_back(-1);
        for (int i = 0; i < numOfChild; i++){
          tQ.insert(childList[i]);
        }
        Q.push_back(tQ);
      } else {
        int l = getLevel(N);
        set<int> tQ;
        level.push_back(l);
        for (int i = 0; i < numOfChild; i++){
          tQ.insert(childList[i]);
        }
        Q.push_back(tQ);
      }
      removeChild(P, N);
    } else {
      MBR temp = merge_group_mbr(childList, numOfChild);
      setMBR(N, temp);
    }
    N = P;
  }

  //re-insert Q to tree
  for (int i = 0; i < level.size(); i++) {
    set<int> tQ = Q[i];
    if (level[i] == -1) { //leaf level
      for (set<int>::iterator it=tQ.begin(); it!=tQ.end(); ++it){
        insertEntry(getObjectID(*it), getMBR(*it));
      }
    } else {
      int curr_level = level[i];
      for (set<int>::iterator it=tQ.begin(); it!=tQ.end(); ++it){
        insertToLevel(*it, curr_level);
      }
    }
  }
}

// Merge a group of node into a mbr
MBR RTree::merge_group_mbr(int * nodes, int n)
{
  MBR mbr;
  float new_x1 = FLT_MAX ;
  float new_y1 = FLT_MAX ;
  float new_x2 = FLT_MIN ;
  float new_y2 = FLT_MIN ;
  for (int i = 0; i < n; i++){
    MBR cur = getMBR(nodes[i]);
    new_x1 = min(new_x1,cur.x1);
    new_y1 = min(new_y1,cur.y1);
    new_x2 = max(new_x2,cur.x2);
    new_y2 = max(new_y2,cur.y2);
  }
  mbr.x1=new_x1;
  mbr.y1=new_y1;
  mbr.x2=new_x2;
  mbr.y2=new_y2;
  return mbr;
}

// Insert node to level of tree
void RTree::insertToLevel(int node, int level) {
  int curr_node = root_node;
  int curr_level = 0;
  MBR mbr = getMBR(node);
  while(curr_level < level){
    int childNum;
    int * childList;
    getChildList(curr_node, childNum, childList);
    int min_child = 0;
    int min_area = INT_MAX;
    for (int i = 0 ;i < childNum ; i++){
      int temp = calculateExpand(mbr, childList[i]);
      if (temp < min_area){
         min_child = i;
         min_area = temp;
      }
    }
    curr_node = min_child;
    curr_level++;
  }
  addChild(curr_node, node);
  setParent(node, curr_node);
  while (curr_node != -1) {
    int numOfChild = 0;
    int * childList;
    getChildList(curr_node, numOfChild, childList);
    MBR temp = merge_group_mbr(childList, numOfChild);
    setMBR(curr_node, temp);
    curr_node = getParent(curr_node);
  }

}

// Get node's level
int RTree::getLevel(int node){
  int level = 0;
  while (node != root_node) {
    node = getParent(node);
    level++;
  }
  return level;
}



int RTree::createNewNode()
{
  PF_PageHandle pageHandle;
  fh.AllocatePage(pageHandle);
  int new_root_id;
  pageHandle.GetPageNum(new_root_id);
  return new_root_id;
}

// Get data pointer of a node
char * RTree::getNodeData(int node)
{ 
  PF_PageHandle pageHandle;
  fh.GetThisPage(node,pageHandle);
  char * pData;
  pageHandle.GetData (pData);
  return pData;
}

// Get MBR of a node
MBR RTree::getMBR(int node)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  int x1 = *iData;
  iData++;
  int y1 = *iData;
  iData++;
  int x2 = *iData;
  iData++;
  int y2 = *iData;
  iData++;
  MBR mbr(x1, y1, x2, y2);
  return mbr;
}

// Set MBR to a node
void RTree::setMBR(int node, MBR mbr)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  *iData = mbr.x1;
  iData++;
  *iData = mbr.y1;
  iData++;
  *iData = mbr.x2;
  iData++;
  *iData = mbr.y2;
  iData++;
}

// Get parent id of a node
int RTree::getParent(int node)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  int parent_id = *iData;
  return parent_id;
}

// Set parent id to a node
void RTree::setParent(int node,int parent_id)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  *iData = parent_id;
}


// Get object id of a node
int RTree::getObjectID(int node)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  int object_id = *iData;
  return object_id;
}

// Set object id to a node
void RTree::setObjectID(int node,int object_id)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  *iData = object_id;
}

// Get child list of a node
void RTree::getChildList(int node, int & numOfChild, int *& childList)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  iData += 1; //skip parent id part
  numOfChild = *iData;
  iData++;
  childList = new int[numOfChild];
  for (int i = 0; i < numOfChild; i++)
  {
    childList[i] = *iData;
    iData++;
  }
}

// Add a new child to a node
void RTree::addChild(int node, int child_id)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  iData += 1; //skip parent id part
   // Adjust number of child
  int numOfChild = *iData;
  numOfChild++;
  *iData = numOfChild;
  iData++;
  // Add new child to the end of list
  iData += numOfChild-1;
  *iData = child_id;
  
}

// Remove a child from a node
void RTree::removeChild(int node, int child_id)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  iData += 1; //skip parent id part
  // Adjust number of child
  int numOfChild = *iData;
  if (numOfChild <= 0) {
    return;
  }
  numOfChild--;
  *iData = numOfChild;
  iData++;

  for (int i = 0; i < numOfChild + 1; i++) {
    if (iData[i] == child_id){ // If found
      if (i < numOfChild) { // If it is not the last one
        // replace this one with last one
        iData[i] = iData[numOfChild];
      }
    }
  }
}

// Get number of child of a node
int RTree::getNumOFChild(int node)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  iData += 1; //skip parent id part
  // Adjust number of child
  int numOfChild = *iData;
  return numOfChild;
}

// Set number of child of a node
void RTree::setNumOFChild(int node, int numOfChild)
{
  char * pData = getNodeData(node);
  int * iData = (int *) pData;
  iData += 4; //skip MBR part
  iData += 1; //skip parent id part
  // Adjust number of child
  *iData = numOfChild;
}


