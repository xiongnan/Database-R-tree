#ifndef MBR_H
#define MBR_H


struct MBR
{
  MBR(){
    
  }
  MBR(int x1, int y1, int x2, int y2)
  {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }
  float x1;
  float y1;
  float x2;
  float y2;	
};

#endif
