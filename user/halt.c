#include <types.h>
#include <klibc.h>

int
main(int argc, char *argv[])
{
  if (halt() < 0)
    printf(2, "failed to halt");
  exit();
}

