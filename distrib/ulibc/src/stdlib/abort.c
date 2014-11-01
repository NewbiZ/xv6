#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <stdio.h>

void abort(void)
{
  fprintf(stderr, "Abort.\n");
  sysexit();
}

