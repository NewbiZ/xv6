#include <ulibc/string.h>

#include <ulibc/stdlib.h>

char* strchr(const char* s, int c)
{
  for (; *s && *(unsigned char*)s!=c; ++s);
  return *s==0 ? NULL : (char*)s;
}

