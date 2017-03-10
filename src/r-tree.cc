RTree::RTree(PF_FileHandle &fileHandle)
{
  fh = fileHandle;
}

int RTree::chooseLeaf(MBR object)
{
  int curr_node = root_node;
  while(!isleaf(curr_node)){
    int childNum;
    int * childList;
    getChildList(curr_node, childNum, childList);
    int min_child = 0;
    int min_area = Maxvalue;
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
  pageHandle.GetData (pdata);
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
  char ** ppData = getNodeData(node);
  getMBR(ppData); //skip MBR
  getInt(ppData); //skip parent node id
  getInt(ppData); //skip child number
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
  numOfChild = getInt(ppData);
  putInt(tmp, numOfChild + 1);
  for (int i = 0; i < numOfChild-1; i++){
    getInt(ppData);
  }
  putInt(ppData, child_id);
}

int RTree::getParent(int node)
{
  char ** ppData = getNodeData(node);
  getMBR(ppData);
  return getInt(ppData);
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
  expand(node);

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

  //get child of node
  //get all mbr of all child

  //[algorithm]
  //split all child into 2 group: A, B

  //update node's child to A
  //update mbr of node


  //create a new node
  //update parent id of B to new node
  //update node's child to B
  //update mbr of new node


  //set parent id of new node
  //update new node's parent's child list


  



}

int * RTree::get_complement(int * all_child, int * A)
{

}

int * RTree::split_two_groups(int * all_child)
{
  
}

void RTree::insertEntry(int object_id, MBR mbr)
{
  int position;
  position = chooseLeaf(mbr);
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
