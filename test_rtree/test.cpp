#include<iostream>
#include<cstdlib>
#include "r-tree.h"
#include "pf.h"
#include "mbr.h"
#include "helper.h"
using namespace std;
int  main(){
  PF_Manager pf_manager;
  pf_manager.CreateFile("test_file");
  
  PF_FileHandle fileHandle;
  pf_manager.OpenFile("test_file", fileHandle);

  RTree rtree(fileHandle);
  rtree.createTree();
  
  for (int i = 0; i < 10; i++) {
    MBR mbr1(1+i,1+i,2+i,2+i);
    int id1 = i+1;
    rtree.insertEntry(id1, mbr1);
  }

  for (int i = 1; i < 10; i++) {
    //  rtree.printNode(i);
  }
  return 0;
  
}
