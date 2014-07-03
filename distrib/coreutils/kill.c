#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>
#include <ulibc/stdlib.h>

int
main(int argc, char **argv)
{
  int i;

  if(argc < 1){
    __ulibc_printf(2, "usage: kill pid...\n");
    sysexit();
  }
  for(i=1; i<argc; i++)
    kill(atoi(argv[i]));
  sysexit();
}
