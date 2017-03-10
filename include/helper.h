void putInt(char ** ppData, int data);
void putChar(char ** ppData, char data);
void putFloat(char * ppData, float data);
void putAttrType(char * ppData, AttrType data);

int getInt(char ** ppData);
char getChar(char ** ppData);
float getFloat(char ** pData);
AttrType getAttrType(char ** pData);

void putMBR(char ** ppData, MBR& object);
MBR getMBR(char ** ppData);
