#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <assert.h>

void* __ulibc_malloc(size_t);

void* malloc(size_t size)
{
  //TODO
  return __ulibc_malloc(size);
}

