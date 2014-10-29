#include <ulibc/ctype.h>

int ispunct(int c)
{
  return isgraph(c) && !isalnum(c);
}

