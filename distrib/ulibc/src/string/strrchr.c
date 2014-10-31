#include <string.h>
#include <stdlib.h>

char* strrchr(const char* s, int c)
{
  const char* b = s;
  while(*s++);
  for (; s>=b && *(unsigned char*)s!=c; --s);
  return s<b ? NULL : (char*)s;
}

