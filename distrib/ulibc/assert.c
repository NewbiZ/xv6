#include <ulibc/assert.h>
#include <ulibc/stdio.h>
#include <ulibc/stdlib.h>
#include <ulibc/stddef.h>
#include <ulibc/ulibc.h>

void __ulibc_assert(const char* c, const char* file, int line)
{
  __ulibc_printf(2, "Assertion failed: %s (%s:%d)\n", c, file, line);
  //fflush(NULL);
  abort();
}

