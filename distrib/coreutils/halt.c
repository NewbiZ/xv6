#include <syscall.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
  printf("The system is going down for halt NOW\n");

  sleep(100);

  if (halt() < 0)
    fprintf(stderr, "failed to halt");

  sysexit();
}

