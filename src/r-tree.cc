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
  fh = fileHandle;
  PF_PageHandle pageHandle;
  fh.AllocatePage(pageHandle);
  int new_root_id;
  pageHandle.GetPageNum(new_root_id);
  char ** ppData = getNodeData(new_root_id);
  cout << (void *)*ppData << endl;
  MBR new_root_mbr(0,0,0,0);
  cout << new_root_mbr.x1 << " " << new_root_mbr.y1 << " " << new_root_mbr.x2 << " "<< new_root_mbr.y2 << endl;
  cout << "test" << endl;
  putMBR(ppData,new_root_mbr);
  cout << "test" << endl;
  cout << (void *)*ppData << endl;
  //putInt(ppData, -1); //root's parent
  //putInt(ppData,0); //number of child
  root_node = new_root_id; //store root id
  cout << "initial root: " << root_node << endl;

  ppData = getNodeData(root_node);
  cout << (void *)*ppData << endl;
  //MBR mbr = getMBR(ppData);
  //cout << new_root_mbr.x1 << " " << new_root_mbr.y1 << " " << new_root_mbr.x2 << " "<< new_root_mbr.y2 << endl;
  //cout << mbr.x1 << " " << mbr.y1 << " " << mbr.x2 << " "<< mbr.y2 << endl;

}

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

char ** RTree::getNodeData(int node)
{ 
  PF_PageHandle pageHandle;
  fh.GetThisPage(node,pageHandle);
  char * pData;
  pageHandle.GetData (pData);
  char ** ppData = &pData;
  return ppData;
}

bool RTree::isObject(int node)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData); //skip MBR
  getInt(ppData); //skip parent node id
  int id = getInt(ppData); //get object id
  return id < 0;
}

bool RTree::isLeaf(int node)
{
  cout << node << endl;
  char ** ppData = getNodeData(node);
  MBR mbr = getMBR(ppData); //skip MBR
  cout << mbr.x1 << " " << mbr.y1 << " " << mbr.x2 << " "<< mbr.y2 << endl;
  getInt(ppData); //skip parent node id
  int numOfChild = getInt(ppData); //get child number
  cout << "num of child:"  << numOfChild << endl;
  if (numOfChild == 0) //if it is new root
  {
    return true;
  }
  int first_child_node = getInt(ppData); //get first child node#
  return isObject(first_child_node);
}

float RTree::calculateExpand(MBR object, int node)
{
  char ** ppData = getNodeData(node);
  MBR mbr = getMBR(ppData);
  float new_x1 = min(mbr.x1, object.x1);
  float new_y1 = min(mbr.y1, object.y1);
  float new_x2 = max(mbr.x2, object.x2);
  float new_y2 = max(mbr.y2, object.y2);
  float new_area = (new_x2-new_x1) * (new_y2-new_y1);
  float old_area = (mbr.x2-mbr.x1) * (mbr.y2-mbr.y1);
  return new_area-old_area;  

}

MBR RTree::merge_two_nodes(int node1, int node2)
{
  char ** ppData = getNodeData(node1);
  MBR mbr1 = getMBR(ppData);
  ppData = getNodeData(node2);
  MBR mbr2 = getMBR(ppData);
  MBR result;
  result.x1 = min(mbr1.x1, mbr2.x1);
  result.y1 = min(mbr1.y1, mbr2.y1);
  result.x2 = max(mbr1.x2, mbr2.x2);
  result.y2 = max(mbr1.y2, mbr2.y2);
  return result;
}

void RTree::getChildList(int node, int & numOfChild, int *& childList)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);//skip MBR
  getInt(ppData); //skip parent node id
  numOfChild = getInt(ppData);
  childList = new int[numOfChild];
  for (int i = 0; i < numOfChild; i++)
  {
    childList[i] = getInt(ppData);
  }
}

void RTree::addChild(int node, int child_id)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);//skip MBR
  getInt(ppData); //skip parent node id
  char ** tmp = ppData;
  int numOfChild = getInt(ppData);
  putInt(tmp, numOfChild + 1);
  for (int i = 0; i < numOfChild-1; i++){
    getInt(ppData);
  }
  putInt(ppData, child_id);
}

void RTree::removeChild(int node, int child_id)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);//skip MBR
  getInt(ppData); //skip parent node id
  char ** tmp = ppData;
  int numOfChild = getInt(ppData);
  putInt(tmp, numOfChild - 1);
  char * pData = * ppData;
  int * ipointer = (int *) pData;

  for (int i = 0; i < numOfChild + 1; i++) {

    if (ipointer[i] == child_id){
      if (i < numOfChild) {
        ipointer[i] = ipointer[numOfChild];
      }
    }
  }
}

int RTree::getNumOFChild(int node)
{
  int numOfChild = 0;
  int * childList;
  getChildList(node,numOfChild,childList);
  return numOfChild;
}

int RTree::getParent(int node)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);
  return getInt(ppData);
}

MBR RTree::getMBRbyNode(int node)
{
  char ** ppData = getNodeData(node);
  return getMBR(ppData);//skip MBR
}

void RTree::setMBRbyNode(int node, MBR mbr)
{
  char ** ppData = getNodeData(node);
  putMBR(ppData, mbr);
}

void RTree::adjustTree(MBR object, int node)
{
  
  int parent_id = getParent(node);
  
  while (parent_id != -1)
  {
    expand(object, node);
    node = parent_id;
    parent_id = getParent(node);
  }
  expand(object, node);

}

void RTree::setParent(int node,int parent)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);
  putInt(ppData, parent);
}

void RTree::adjustTree(int L, int LL)
{
  int parent_id = getParent(L);
  if (parent_id == -1) {
    //create a new node as new root
    PF_PageHandle pageHandle;
    fh.AllocatePage(pageHandle);
    int new_root_id;
    pageHandle.GetPageNum(new_root_id); 
    char ** ppData = getNodeData(new_root_id);
    MBR new_root_mbr = merge_two_nodes(L,LL);
    putMBR(ppData,new_root_mbr);
    putInt(ppData, -1);
    putInt(ppData,2);
    putInt(ppData,L);
    putInt(ppData,LL);
    setParent(L,new_root_id);
    setParent(LL,new_root_id);//add L and LL as child of the new root
    //update new root
    root_node = new_root_id;
    return;
  }
  addChild(parent_id, LL);
  int numOfChild = 0;
  int * childList;
  getChildList(parent_id,numOfChild,childList);
  if (numOfChild > M)
  { 
    L = parent_id;
    LL = split(parent_id);
    adjustTree(L, LL);
  }
}

/*MBR RTree::merge_two_nodes(int node1, int node2)
{
  char ** ppData = getNodeData(node1);
  MBR mbr1 = getMBR(ppData);
  ppData = getNodeData(node2);
  MBR mbr2 = getMBR(ppData);
  MBR result;
  result.x1 = min(mbr1.x1, mbr2.x1);
  result.y1 = min(mbr1.y1, mbr2.y1);
  result.x2 = max(mbr1.x2, mbr2.x2);
  result.y2 = max(mbr1.y2, mbr2.y2);
  return result;
}*/

void RTree::expand(MBR object, int node)
{
  char ** ppData = getNodeData(node);
  MBR mbr = getMBR(ppData);
  mbr.x1 = min(mbr.x1, object.x1);
  mbr.y1 = min(mbr.y1, object.y1);
  mbr.x2 = max(mbr.x2, object.x2);
  mbr.y2 = max(mbr.y2, object.y2);
  ppData = getNodeData(node);
  putMBR(ppData,mbr);
}

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
  char ** ppData = getNodeData(node);
  MBR temp = merge_group_mbr(A);
  putMBR(ppData, temp);
  getInt(ppData); //skip parent id
  putInt(ppData, A.size()); //set num of child
  for (set<int>::iterator it=A.begin();it!=A.end();++it){
    putInt(ppData, *it);
  }



  //create a new node
  PF_PageHandle pageHandle;
  fh.AllocatePage(pageHandle);
  int new_node_id;
  pageHandle.GetPageNum(new_node_id); 
  ppData = getNodeData(new_node_id);
  int node_parent = getParent(node);
  //update mbr of new node
  temp = merge_group_mbr(B);
  putMBR(ppData, temp); //set new mbr
  //set parent id of new node
  putInt(ppData, node_parent); //set parent to be as same as parent of node
  putInt(ppData, B.size()); //set num of child

  //update parent id of B to new node
  //update node's child to B
  for (set<int>::iterator it=B.begin();it!=B.end();++it){
    setParent(*it, new_node_id);
    putInt(ppData, *it);
  }
   //update new node's parent's child list
  addChild(node_parent, new_node_id);
  
}



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


MBR RTree::merge_group_mbr(set<int> nodes)
{
  MBR mbr;
  float new_x1 = FLT_MAX ;
  float new_y1 = FLT_MAX ;
  float new_x2 = FLT_MIN ;
  float new_y2 = FLT_MIN ;
  for (set<int>::iterator it=nodes.begin();it!=nodes.end();++it){
    MBR cur = getMBRbyNode(*it);
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


MBR RTree::merge_group_mbr(int * nodes, int n)
{
  MBR mbr;
  float new_x1 = FLT_MAX ;
  float new_y1 = FLT_MAX ;
  float new_x2 = FLT_MIN ;
  float new_y2 = FLT_MIN ;
  for (int i = 0; i < n; i++){
    MBR cur = getMBRbyNode(nodes[i]);
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


set<int> RTree::split_two_groups(int numOfChild, int * childList, set<int> & all_child)
{
  set<int> temp; 
  set<int> best; 
  split_helper(numOfChild, childList, 0, temp, best);
  return best;
}

void RTree::insertEntry(int object_id, MBR mbr)
{
  cout << "insert:" << object_id << endl;
  int position;
  position = chooseLeaf(mbr);
  cout << "found leaf: " << position << endl;
  PF_PageHandle pageHandle;
  fh.AllocatePage(pageHandle);
  int new_object_id;
  pageHandle.GetPageNum(new_object_id); 
  char ** ppData = getNodeData(new_object_id);
  putMBR(ppData,mbr);
  putInt(ppData,position);
  putInt(ppData,-1*object_id);
  addChild(position, new_object_id);

  int numOfChild = 0;
  int * childList;
  getChildList(position,numOfChild,childList);
  if (numOfChild > M)
  { 
    int LL = split(position);
    adjustTree(position,LL);
  }

}

int RTree::getObjectID(int node) {
  char ** ppData = getNodeData(node);
  getMBR(ppData);
  getInt(ppData);
  return getInt(ppData) * -1;
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
      setMBRbyNode(N, temp);
    }
    N = P;
  }

  //re-insert Q to tree
  for (int i = 0; i < level.size(); i++) {
    set<int> tQ = Q[i];
    if (level[i] == -1) { //leaf level
      for (set<int>::iterator it=tQ.begin(); it!=tQ.end(); ++it){
        insertEntry(getObjectID(*it), getMBRbyNode(*it));
      }
    } else {
      int curr_level = level[i];
      for (set<int>::iterator it=tQ.begin(); it!=tQ.end(); ++it){
        insertToLevel(*it, curr_level);
      }
    }
  }
}

void RTree::insertToLevel(int node, int level) {
  int curr_node = root_node;
  int curr_level = 0;
  MBR mbr = getMBRbyNode(node);
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
    setMBRbyNode(curr_node, temp);
    curr_node = getParent(curr_node);
  }

}

int RTree::getLevel(int N){
  int level = 0;
  while (N != root_node) {
    N = getParent(N);
    level++;
  }
  return level;
}

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

// bool RTree::isOverlap(int node1, int node2)
// {
//   MBR mbr1 = getMBR(node1);
//   MBR mbr2 = getMBR(node2);

//   //  1x1 ... 1x2   2x1 .... 2x2
//   //  2x1 ... 2x2   1x1 .... 1x2
//   if (mbr1.x2 < mbr2.x1 || mbr2.x2 < mbr1.x1){
//     return false;
//   }

//   if (mbr1.y2 < mbr2.y1 || mbr1.y1 > mbr2.y2){
//     return false;
//   }

//   return true;
// }

bool RTree::isOverlap(int node1, MBR mbr2)
{
  MBR mbr1 = getMBRbyNode(node1);

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


