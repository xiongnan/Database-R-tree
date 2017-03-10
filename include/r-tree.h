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
  RTree(PF_FileHandle &fileHandle);
  RTree~();

  void insertEntry(void * pData);
  int chooseLeaf(void * pData);

  int m;
  int M;
  
 private:
  int root_node;
  PF_FileHandle fh;
  float calculateExpand(MBR object, int node);
  MBR merge_two_nodes(int node1, int node2);
  void getChildList(int node, int & numOfChild, int *& childList);
  int getParent(int node);
  void setParent(int node,int parent);
  bool isLeaf(int node);
  bool isObject(int node);
  char ** getNodeData(int node);

  int adjustTree(int nodeL, int nodeLL);
  void isFull(int node);
  void splitNode(int node, void * pData, int nodeL, int nodeLL);
};


