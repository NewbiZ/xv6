#include <ulibc/stdio.h>

#include <ulibc/stdarg.h>

int printf(const char* format, ...)
{
  int count;
  va_list ap;
  va_start(ap, format);
  count = vprintf(format, ap);
  va_end(ap);
  return count;
}

