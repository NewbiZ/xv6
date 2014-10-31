#include <string.h>
#include <stdlib.h>

size_t strxfrm(char* s1, const char* s2, size_t n)
{
  size_t l = strlen(s2);
  if (n > l)
    strcpy(s1, s2);
  return l;
}

