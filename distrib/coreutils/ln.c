#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

int
main(int argc, char *argv[])
{
  if(argc != 3){
    __ulibc_printf(2, "Usage: ln old new\n");
    sysexit();
  }
  if(link(argv[1], argv[2]) < 0)
    __ulibc_printf(2, "link %s %s: failed\n", argv[1], argv[2]);
  sysexit();
}
