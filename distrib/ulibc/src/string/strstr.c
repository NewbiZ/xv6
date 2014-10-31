#include <string.h>
#include <stdlib.h>

char* strstr(const char* s1, const char* s2)
{
  const char* b2 = s2;
  if (!*s2)
    return (char*)s1;
  for (; *s1 && *s2; ++s1)
  {
    if (*s1==*s2)
      ++s2;
    else
      s2 = b2;
  }
  return *s2 ? NULL : (char*)(s1-(s2-b2));
}

