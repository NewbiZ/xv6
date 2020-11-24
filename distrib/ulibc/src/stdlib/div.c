#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <assert.h>

div_t div(int numer, int denom)
{
  div_t r;
  r.quot = 0;
  r.rem = 0;
  assert(0 && "not implemented yet.");
  return r;
}

