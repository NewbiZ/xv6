#include <ulibc/stdio.h>
#include <ulibc/ulibc.h>
#include <ulibc/string.h>

int puts(const char* s)
{
  static const char newline = '\n';
  int len = strlen(s);
  write(1, s, len);
  write(1, &newline, 1);
  return 1;
}

