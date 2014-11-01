#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syscall.h>

#include <xv6/fcntl.h>

FILE* fopen(const char* filename, const char* mode)
{
  int fmode = 0;
  struct __FILE* f = NULL;
  int fd;

  switch (*mode)
  {
    case 'r':
      fmode |= O_RDONLY;
      break;
    case 'w':
      fmode |= O_WRONLY;
      fmode |= O_CREAT;
      fmode |= O_TRUNC;
      break;
    case 'a':
      fmode |= O_WRONLY;
      fmode |= O_CREAT;
      fmode |= O_APPEND;
      break;
    default:
      goto out;
  }

  switch (*++mode)
  {
    case '+': 
      fmode |= O_RDWR;
      break;
    case 0:
      break;
    default:
      goto out;
  }

  if (!(fd=open(filename, fmode)))
    goto out;

  f = (struct __FILE*)malloc(sizeof(struct __FILE));
  memset(f, 0, sizeof(struct __FILE));
  f->fd = fd;
  f->buffer = (char*)malloc(BUFSIZ);
  f->mode = fmode;
  f->flags = _IOFBF; /* TODO: Should be _IOLBF if f is a tty */

out:
  return f;
}

