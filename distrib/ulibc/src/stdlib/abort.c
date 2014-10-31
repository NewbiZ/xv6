#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <stdio.h>

void abort(void)
{
  //TODO
  fprintf(stderr, "Abort.\n");
  sysexit();
}

