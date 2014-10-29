#include <ulibc/ctype.h>

int isalpha(int c)
{
  return islower(c) || isupper(c);
}

