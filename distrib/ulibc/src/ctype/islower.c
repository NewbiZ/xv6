#include <ulibc/ctype.h>

int islower(int c)
{
  return c>='a' && c<='z';
}

