#include <string.h>
#include <stdlib.h>

int strcmp(const char* s1, const char* s2)
{
  for (; *s1 && *s2 && *s1==*s2; s1++, s2++);
  return *(unsigned char*)s1-*(unsigned char*)s2;
}

