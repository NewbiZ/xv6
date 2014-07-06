#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

#include <xv6/fcntl.h>

char *argv[] = { "sh", 0 };

int main(void)
{
  int pid, wpid;

  if(open("/dev/console", O_RDWR) < 0){
    mknod("/dev/console", 1, 1);
    open("/dev/console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    __ulibc_printf(1, "init: starting sh\n");
    pid = fork();
    if(pid < 0){
      __ulibc_printf(1, "init: fork failed\n");
      sysexit();
    }
    if(pid == 0){
      exec("/bin/sh", argv);
      __ulibc_printf(1, "init: exec sh failed\n");
      sysexit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      __ulibc_printf(1, "zombie!\n");
  }
}
