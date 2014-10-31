#include <ulibc/stdio.h>

#include <ulibc/ulibc.h>

size_t fread(void* ptr, size_t size, size_t nmemb, FILE* f)
{
  // TODO: should use buffering here depending on f->flags
  read(f->fd, ptr, size*nmemb);

//out:
  return nmemb;
}

