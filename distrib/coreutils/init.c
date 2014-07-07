#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

#include <xv6/fcntl.h>
#include <xv6/types.h>
#include <xv6/fs.h>
#include <xv6/file.h>

char *argv[] = { "sh", 0 };

void setup_devices(void)
{
  if(open("/dev/console", O_RDWR) < 0)
  {
    mknod("/dev/console", DEV_CONSOLE, 1);
    open("/dev/console", O_RDWR);
  }

  if(open("/dev/null", O_RDWR) < 0)
    mknod("/dev/null", DEV_NULL, 1);

  if(open("/dev/zero", O_RDWR) < 0)
    mknod("/dev/zero", DEV_ZERO, 1);

  link("/dev/console", "/dev/tty");
  link("/dev/console", "/dev/tty0");
}

int main(void)
{
  int pid, wpid;

  setup_devices();

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
