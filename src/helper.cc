#include "redbase.h"

void putMBR(char ** ppData, MBR& object)
{
  char * pData = *ppData;
  MBR * ipointer = (MBR *)pData;
  * ipointer = object;
  ipointer ++;
  pData = (char *) ipointer;
  *ppData = pData;
}

MBR getMBR(char ** ppData)
{
  char * pData = *ppData;
  MBR * ipointer = (MBR *)pData;
  MBR object = * ipointer;
  ipointer++;
  pData = (char *) ipointer;
  *ppData = pData;
  return object;
}



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


void add(int& b){
  // int b2 = *b
  b++;
  // *b = b2;
}

a = 2;
add(a)
a
*/

