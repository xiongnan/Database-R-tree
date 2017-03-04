int RTree::chooseLeaf(MBR object)
{
  int curr_node = root_node;
  while(!isleaf(curr_node)){
    int childNum;
    int * childList;
    getChild(curr_node, childNum, childList);
    int min_child = 0;
    int min_area = Maxvalue;
    for (int i = 0 ;i < childNum ; i++){
      int temp = expand(object, childList[i]);
      if (temp < min_area){
	min_child = i;
	min_area = temp;
      }
    }
    curr_node = min_child;
  }
  return curr_node;
}

void RTree::insertEntry(void * pData)
{


}
