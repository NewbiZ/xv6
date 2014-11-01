#include <string.h>
#include <stdlib.h>

void* memcpy(void* s1, const void* s2, size_t n)
{
  void* b = s1;
  while (n--)
  {
    *(char*)s1 = *(const char*)s2;
    s1 = (void*)((char*)s1+1);
    s2 = (const void*)((const char*)s2+1);
  }
  return b;
}

