#include <syscall.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
  int i;

  if (argc<2)
    printf("\n");

  for(i=1; i<argc; ++i)
    printf("%s%s", argv[i], i+1 < argc ? " " : "\n");

  sysexit();
}
