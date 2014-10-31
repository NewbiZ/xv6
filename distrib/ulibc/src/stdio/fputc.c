#include <stdio.h>
#include <syscall.h>

int fputc(int c, FILE* f)
{
  // TODO: should use buffering here depending on f->flags
  write(f->fd, &c, 1);
  return 0;
}

