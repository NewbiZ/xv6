#include <ulibc/stdio.h>

#include <ulibc/stdlib.h>
#include <ulibc/ulibc.h>

int fclose(FILE* f)
{
  fflush(f);
  close(f->fd);
  free(f->buffer);
  free(f);

  return 0;
}

