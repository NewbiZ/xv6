#include <ulibc/string.h>

#include <ulibc/stdlib.h>

void* memmove(void* s1, const void* s2, size_t n)
{
  char* bkp = (char*)malloc(n);
  memcpy(bkp, s2, n);
  memcpy(s1, bkp, n);
  free(bkp);
  return s1;
}

