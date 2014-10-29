#include <ulibc/string.h>

#include <ulibc/stdlib.h>

char* strncat(char* s1, const char* s2, size_t n)
{
  size_t dstlen = strlen(s1);
  size_t i = 0;

  for (; i<n && s2[i]!=0 ; ++i)
    s1[dstlen+i] = s2[i];
  s1[dstlen+i] = 0;

  return s1;
}

