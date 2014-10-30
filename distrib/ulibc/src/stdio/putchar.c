#include <ulibc/stdio.h>
#include <ulibc/ulibc.h>

int putchar(int c)
{
  write(1, &c, 1);
  return c;
}

