#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>
#include <ulibc/string.h>

char buf[512];

void
wc(int fd, char *name)
{
  int i, n;
  int l, w, c, inword;

  l = w = c = 0;
  inword = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    for(i=0; i<n; i++){
      c++;
      if(buf[i] == '\n')
        l++;
      if(__ulibc_strchr(" \r\t\n\v", buf[i]))
        inword = 0;
      else if(!inword){
        w++;
        inword = 1;
      }
    }
  }
  if(n < 0){
    __ulibc_printf(1, "wc: read error\n");
    sysexit();
  }
  __ulibc_printf(1, "%d %d %d %s\n", l, w, c, name);
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    wc(0, "");
    sysexit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      __ulibc_printf(1, "wc: cannot open %s\n", argv[i]);
      sysexit();
    }
    wc(fd, argv[i]);
    close(fd);
  }
  sysexit();
}
