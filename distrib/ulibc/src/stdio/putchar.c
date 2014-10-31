#include <stdio.h>
#include <syscall.h>

int putchar(int c)
{
  write(1, &c, 1);
  return c;
}

