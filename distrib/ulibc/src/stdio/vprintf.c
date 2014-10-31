#include <stdio.h>
#include <stdarg.h>

int vprintf(const char* format, va_list arg)
{
  return vfprintf(stdout, format, arg);
}

