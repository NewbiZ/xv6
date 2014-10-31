#include <ulibc/stdio.h>

#include <ulibc/stdarg.h>

int vprintf(const char* format, va_list arg)
{
  return vfprintf(stdout, format, arg);
}

