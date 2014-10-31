#include <string.h>
#include <stdlib.h>

int strncmp(const char* s1, const char* s2, size_t n)
{
  for (; --n && *s1 && *s2 && *s1==*s2; s1++, s2++);
  return *(unsigned char*)s1-*(unsigned char*)s2;
}

