#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

int fclose(FILE* f)
{
  fflush(f);
  close(f->fd);
  free(f->buffer);
  free(f);

  return 0;
}

