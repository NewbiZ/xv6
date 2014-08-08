#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

int
main(int argc, char *argv[])
{
  int i;

  if (argc<2)
  {
    __ulibc_printf(1, "\n");
  }

  for(i=1; i<argc; ++i)
  {
    __ulibc_printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  }

  sysexit();
}
