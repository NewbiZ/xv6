#include <ulibc/stdio.h>

#include <ulibc/ulibc.h>

size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* f)
{
  // TODO: should use buffering here depending on f->flags
  write(f->fd, ptr, size*nmemb);

//out:
  return nmemb;
}

