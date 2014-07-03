#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>
#include <ulibc/assert.h>

int
main(int argc, char *argv[])
{
  assert(1+1==2);
  
  int i;

  for(i = 1; i < argc; i++)
    fprintf(stdout, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  sysexit();
}
