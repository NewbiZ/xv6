#include <ulibc/string.h>

#include <ulibc/stdlib.h>

void* memchr(const void* s, int c, size_t n)
{
  for (; n && *(unsigned char*)s!=c; ++s, --n);
  return n ? (void*)s : NULL;
}

