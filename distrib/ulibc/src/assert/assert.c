#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void __ulibc_assert(const char* c, const char* file, int line)
{
  fprintf(stderr, "Assertion failed: %s (%s:%d)\n", c, file, line);
  fflush(NULL);
  abort();
}

