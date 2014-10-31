#include <ulibc/stdio.h>

int fflush(FILE* f)
{
  // TODO: should use buffering here, depending on f->flags
  return 0;
}

