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
  /*    
  MBR mbr1(1,1,2,2);
  int id1 = 1;
  
  char * pData = new char[100];
  cout << (void*)pData << endl;
  char **ppData = &pData;
  putMBR(ppData, mbr1);
  cout << (void*)pData << endl;
  ppData= &pData;
  MBR mbr = getMBR(ppData);
  cout << mbr.x1 << " " << mbr.y1 << " " << mbr.x2 << " "<< mbr.y2 << endl;
    // rtree.insertEntry(id1, mbr1);
    */
  return 0;
  
}
