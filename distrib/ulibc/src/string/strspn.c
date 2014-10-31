#include <string.h>
#include <stdlib.h>

size_t strspn(const char* s1, const char* s2)
{
  const char* b = s1;
  for (; *s1 && strchr(s2, *s1); ++s1);
  return s1-b;
}

