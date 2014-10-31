#include <ulibc/stdio.h>

#include <ulibc/stdarg.h>

int fprintf(FILE* f, const char* format, ...)
{
  int count;
  va_list ap;
  va_start(ap, format);
  count = vfprintf(f, format,ap);
  va_end(ap);
  return count;
}

