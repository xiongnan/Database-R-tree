//y
// File:        ix_indexmanager.cc
// Description: IX_IndexHandle handles indexes
// Author:      Yifei Huang (yifei@stanford.edu)
//

#include <unistd.h>
#include <sys/types.h>
#include "ix.h"
#include "pf.h"
#include <climits>
#include <string>
#include <sstream>
#include <cstdio>
#include "comparators.h"
#include "helper.h"

IX_Manager::IX_Manager(PF_Manager &pfm) 
{
  this->pfm = pfm;
}

IX_Manager::~IX_Manager()
{
  
}

/*
 * Creates a new index given the filename, the index number, attribute type and length.
 */
RC IX_Manager::CreateIndex(const char * fileName, int indexNo, AttrType attrType, int attrLength)
{
  std::string indexName = fileName;
  indexName = indexName + "." + std::to_string(indexNo);
  
  RC rc = pfm.CreateFile(indexName.c_str());
  if (rc != 0) 
  {
    PF_PrintError(rc);
    return IX_BADINDEXNAME;
  }
  PF_FileHandle fileHandle;
  RC rc = pfm.OpenFile(indexName.c_str(), fileHandle);
  
  PF_PageHandle pageHandle;
  fileHandle.AllocatePage(pageHandle);
  /*  
  char * pData;
  pageHandle.GetData(pData);
  
  // Store attribute info in the first page of index file
  char ** ppData = &pData;
  // Number of attribute
  putInt(ppData, attrNum);

  for (int i = 0; i < attrNum; i++)
  {
    putAttrType(ppData, attrType[i]);
    putInt(ppData, attrLength[i]);
  }
  */
}

/*
 * This function destroys a valid index given the file name and index number.
 */
RC IX_Manager::DestroyIndex(const char *fileName, int indexNo)
{
  std::string indexName = fileName;
  indexName = indexName + "." + std::to_string(indexNo);

  RC rc = pfm.DestroyFile(indexName.c_str());
  if (rc != 0)
  {
      PF_PrintError(rc);
      return IX_BADINDEXNAME;
  }
}

/*
 * This function, given a valid fileName and index Number, opens up the
 * index associated with it, and returns it via the indexHandle variable
 */
RC IX_Manager::OpenIndex(const char *fileName, int indexNo,
                 IX_IndexHandle &indexHandle)
{
  std::string indexName =fileName;
  indexName = indexName + "." + std::to_string(indexNo);

  PF_FileHandle fileHandle;
  RC rc = pfm.OpenFile(indexName.c_str(), fileHandle);
  if (rc != 0)
  {
      PF_PrintError(rc);
      return IX_BADINDEXNAME;
  }
  indexHandle.AddFileHandle(fileHandle);
}

/*
 * Given a valid index handle, closes the file associated with it
 */
RC IX_Manager::CloseIndex(IX_IndexHandle &indexHandle)
{
  std::string indexName =fileName;
  indexName = indexName + "." + std::to_string(indexNo);

  PF_FileHandle fileHandle;
  RC rc = pfm.CloseFile(indexName.c_str(), fileHandle);
  if (rc != 0)
    {
      PF_PrintError(rc);
      return IX_BADINDEXNAME;
    }

}
