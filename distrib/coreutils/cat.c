#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

char buf[512];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0)
    write(1, buf, n);
  if(n < 0){
    __ulibc_printf(1, "cat: read error\n");
    sysexit();
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    sysexit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      __ulibc_printf(1, "cat: cannot open %s\n", argv[i]);
      sysexit();
    }
    cat(fd);
    close(fd);
  }
  sysexit();
}
