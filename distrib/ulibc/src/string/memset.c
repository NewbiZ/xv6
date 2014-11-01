#include <string.h>
#include <stdlib.h>

void* memset(void* s, int c, size_t n)
{
  void* b = s;
  while (n-- && (*(unsigned char*)s=(unsigned char)c)) { s = (void*)((char*)s+1); }
  return b;
}

