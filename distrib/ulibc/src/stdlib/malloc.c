#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

void* malloc(size_t size)
{
  //TODO
  return __ulibc_malloc(size);
}

