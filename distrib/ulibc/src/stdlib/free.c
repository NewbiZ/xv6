#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <assert.h>

void __ulibc_free(void *);

void free(void* ptr)
{
  //TODO
  __ulibc_free(ptr);
}

