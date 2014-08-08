#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

int
main(int argc, char *argv[])
{
  __ulibc_printf(1, "The system is going down for halt NOW\n");

  if (halt() < 0)
    __ulibc_printf(2, "failed to halt");

  sysexit();
}

