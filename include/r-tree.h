class RTree {
 public:
  RTree();
  RTree~();

  void insertEntry(void * pData);
  int chooseLeaf(void * pData);
  
 private:
  int root_node;
  int expand(void * pData, int node);
  void getChild(int node, int & childNum, int *& childList);
  bool isLeaf(int node);
  int adjustTree(int nodeL, int nodeLL);
  void isFull(int node);
  void splitNode(int node, void * pData, int nodeL, int nodeLL);
};


