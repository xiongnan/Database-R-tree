#include "redbase.h"

void putInt(char ** ppData, int data)
{
  char * pData = *ppData;
  int * ipointer = (int *)pData;
  * ipointer = data;
  ipointer ++;
  pData = (char *) ipointer;
  *ppData = pData;
}

void putChar(char ** ppData, char data)
{
  char * pData = *ppData;
  * pData = data;
  pData ++;
  *ppData = pData;
}

void putFloat(char * ppData, float data)
{
  char * pData = *ppData;
  float * fpointer = (int *)pData;
  * fpointer = data;
  fpointer ++;
  pData = (char *) fpointer;
  *ppData = pData;
}

void putAttrType(char * ppData, AttrType data)
{
  char * pData = *ppData;
  AttrType * apointer = (AttrType *)pData;
  * apointer = data;
  apointer ++;
  pData = (char *) apointer;
  *ppData = pData;
}

int getInt(char ** ppData)
{
  char * pData = *ppData;
  int * ipointer = (int *)pData;
  int data = * ipointer;
  ipointer++;
  pData = (char *) ipointer;
  *ppData = pData;
  return data;
}

char getChar(char ** ppData)
{
  char * pData = *ppData;
  char data = * pData;
  pData ++;
  *ppData = pData;
  return data;
}

float getFloat(char ** pData)
{
  char * pData = *ppData;
  float *fpointer = (float *)pData;
  float data = * fpointer;
  fpointer ++;
  pData = (char *) fpointer;
  *ppData = pData;
  return data;
}


AttrType getAttrType(char ** pData)
{
  char * pData = *ppData;
  AttrType * apointer = (AttrType *)pData;
  AttrType data = * apointer;
  apointer ++;
  pData = (char *) apointer;
  *ppData = pData;
  return data;
}
