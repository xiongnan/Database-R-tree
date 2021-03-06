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

RC IX_IndexHandle::AddFileHandle(PF_FileHandle &fileHandle)
{
  fh = fileHandle;
}

RC IX_IndexHandle::GetFileHandle(PF_FileHandle &fileHandle)
{
  fileHandle = fh;
}

RC IX_IndexHandle::InsertEntry(void *pData, const RID &rid)
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




