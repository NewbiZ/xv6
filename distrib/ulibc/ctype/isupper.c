#include <ulibc/ctype.h>

int isupper(int c)
{
  return c>='A' && c<='Z';
}

