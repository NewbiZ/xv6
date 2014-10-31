#include <string.h>
#include <stdlib.h>
#include <errno.h>

int __ulibc_error_codes[] = {
#define X(code, msg) code,
#include "strerror.h"
#undef X
};

char* __ulibc_error_msgs[] = {
#define X(code, msg) msg,
#include "strerror.h"
#undef X
};

char* strerror(int errnum)
{
  size_t i = 0;
  for (; __ulibc_error_codes[i]!=errnum && __ulibc_error_codes[i]!=0; ++i);
  return __ulibc_error_msgs[i];
}

