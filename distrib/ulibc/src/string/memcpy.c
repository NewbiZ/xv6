#include <string.h>
#include <stdlib.h>

void* memcpy(void* s1, const void* s2, size_t n)
{
  void* b = s1;
  while (n--)
    *(char*)s1++ = *(char*)s2++;
  return b;
}

