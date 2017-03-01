//
// File:        ix_indexhandle.cc
// Description: IX_IndexHandle handles manipulations within the index
// Author:      <Nan Xiong, Liuqing Yang>
//

#include <unistd.h>
#include <sys/types.h>
#include "ix.h"
#include "pf.h"
#include "comparators.h"
#include <cstdio>

IX_IndexHandle::IX_IndexHandle()
{
  // Implement this
}

IX_IndexHandle::~IX_IndexHandle()
{
  // Implement this
}

RC AddFileHandle(PF_FileHandle &fileHandle)
{
  fh = fileHandle;
  PF_PageHandle pageHandle;
  fh.GetThisPage(0, pageHandle);
  char * pData;
  pageHandle.GetData(pData);
  
  //Read attribute from in the first page of index file                             
  char ** ppData = &pData;
  // Number of attribute                                                              
  attrNum = getInt(ppData);
  attrType = new AttrType[attrNum];
  attrLength = new int[attrNum];

  for (int i = 0; i < attrNum; i++)
  {
      attrType[i] = getAttrType(ppData);
      attrLength[i] = putInt(ppData);
  }

}
RC IX_IndexHandle::InsertEntry(void **ppData, const RID &rid)
{
  
}

RC IX_IndexHandle::DeleteEntry(void *pData, const RID &rid)
{
  // Implement this
}

RC IX_IndexHandle::ForcePages()
{
  // Implement this
}


