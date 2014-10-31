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

  dup(0);  // stdout
  dup(0);  // stderr
}

void run_rclocal(void)
{
  int pid;
  int wpid;
  static char* args[] = {
    "/bin/sh",
    "/etc/rc.local"
  };

  if (open("/etc/rc.local", O_RDONLY))
  {
    pid = fork();

    if (pid<0)
    {
      printf("[init] failed to fork shell for rc.local\n");
      sysexit();
    }

    if (pid==0)
    {
      printf("[init] executing rc.local\n");
      exec("/bin/sh", args);
    }

    while((wpid=wait()) >= 0 && wpid != pid)
    {
      printf("[init] zombie while executing rc.local\n");
    }
  }
}

void run_shell(void)
{
  int pid;
  int wpid;

  for (;;)
  {
    pid = fork();

    if (pid<0)
    {
      printf("[init] shell fork failed\n");
      sysexit();
    }

    if ( pid==0)
    {
      printf("[init] starting shell\n");
      exec("/bin/sh", argv);
      printf("[init] executing shell failed\n");
      sysexit();
    }

    while ((wpid=wait())>=0 && wpid!=pid)
    {
      printf("[init] zombie while executing shell\n");
    }
  }
}

int main(void)
{
  setup_devices();

  run_rclocal();

  run_shell();

  return 0;
}
