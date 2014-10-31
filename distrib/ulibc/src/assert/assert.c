#include <ulibc/assert.h>
#include <ulibc/stdlib.h> // abort
#include <ulibc/stdio.h> // fprintf

void __ulibc_assert(const char* c, const char* file, int line)
{
  fprintf(stderr, "Assertion failed: %s (%s:%d)\n", c, file, line);
  fflush(NULL);
  abort();
}

