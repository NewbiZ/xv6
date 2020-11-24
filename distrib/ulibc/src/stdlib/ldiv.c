#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <assert.h>

ldiv_t ldiv(long int numer, long int denom)
{
  ldiv_t r;
  r.quot = 0L;
  r.rem = 0L;
  assert(0 && "not implemented yet.");
  return r;
}

