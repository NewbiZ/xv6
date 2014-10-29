#include <ulibc/string.h>

#include <ulibc/stdlib.h>

void* memset(void* s, int c, size_t n)
{
  void* b = s;
  for (; n-- && (*(unsigned char*)s=(unsigned char)c); ++s);
  return b;
}

