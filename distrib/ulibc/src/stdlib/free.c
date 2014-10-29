#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

void free(void* ptr)
{
  //TODO
  __ulibc_free(ptr);
}

