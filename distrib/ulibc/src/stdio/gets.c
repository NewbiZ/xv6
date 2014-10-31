#include <stdio.h>
#include <syscall.h>

char* gets(char* s)
{
  char c;
  while (read(0, &c, 1)>0 && c!='\n' && c!='\r')
    *s++ = c;
  *s = 0;
  return s;
}

