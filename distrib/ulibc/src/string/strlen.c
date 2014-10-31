#include <string.h>
#include <stdlib.h>

size_t strlen(const char* s)
{
  const char* b = s;
  while (*s++);
  return s-b-1;
}

