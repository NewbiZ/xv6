#include <ulibc/string.h>

#include <ulibc/stdlib.h>

int memcmp(const void* s1, const void* s2, size_t n)
{
  const unsigned char *us1=s1, *us2=s2;
  for (; n && *us1==*us2; n--, us1++, us2++);
  return n ? *us1-*us2 : 0;
}

