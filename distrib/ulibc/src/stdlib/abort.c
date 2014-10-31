#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/stdio.h>

void abort(void)
{
  //TODO
  fprintf(stderr, "Abort.\n");
  sysexit();
}

