#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

long int atol(const char* nptr)
{
  long result = 0;
  long mul = 1;

  while (isspace(*nptr))
    ++nptr;

  switch (*nptr)
  {
    case '-': mul = -1;
    case '+': ++nptr;
  }

  while (isdigit(*nptr))
    result = 10*result + (*nptr++-'0');

  return mul * result;
}

