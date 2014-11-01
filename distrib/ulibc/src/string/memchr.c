#include <string.h>
#include <stdlib.h>

void* memchr(const void* s, int c, size_t n)
{
  while (n && *(unsigned char*)s!=c) { s = (const void*)((char*)s+1); --n; }
  return n ? (void*)s : NULL;
}

