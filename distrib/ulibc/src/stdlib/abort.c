#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

void abort(void)
{
  //TODO
  __ulibc_printf(2, "Abort.\n");
  sysexit();
}

