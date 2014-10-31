#include <string.h>
#include <stdlib.h>

char* strpbrk(const char* s1, const char* s2)
{
  s1 += strcspn(s1, s2);
  return *s1 ? (char*)s1 : NULL;
}

