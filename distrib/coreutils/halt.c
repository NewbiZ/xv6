#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

int
main(int argc, char *argv[])
{
  if (halt() < 0)
    fprintf(stderr, "failed to halt");
  sysexit();
}

