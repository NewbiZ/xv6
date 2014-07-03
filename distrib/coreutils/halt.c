#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

int
main(int argc, char *argv[])
{
  if (halt() < 0)
    __ulibc_printf(2, "failed to halt");
  sysexit();
}

