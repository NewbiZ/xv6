#include <ulibc/ctype.h>

int isgraph(int c)
{
  return c>='!' && c<='~';
}

