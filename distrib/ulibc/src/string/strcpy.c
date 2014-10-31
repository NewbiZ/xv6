#include <string.h>
#include <stdlib.h>

char* strcpy(char* s1, const char* s2)
{
  char* b = s1;
  while ((*s1++=*s2++));
  return b;
}

