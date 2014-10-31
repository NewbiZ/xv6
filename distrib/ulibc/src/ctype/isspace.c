#include <ctype.h>

int isspace(int c)
{
  return c==' ' || c=='\f' || c=='\n' || c=='\r' || c=='\t' || c=='\v';
}

