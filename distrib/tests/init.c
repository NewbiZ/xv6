#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

#include <xv6/fcntl.h>
#include <xv6/types.h>
#include <xv6/fs.h>
#include <xv6/file.h>

void run_test(char* file)
{
  int pid;
  pid = fork();
  if (pid<0)
  {
    __ulibc_printf(2, "init: fork failed\n");
    sysexit();
  }
  if (pid==0)
  {
    char* argv[] = {file, 0};
    __ulibc_printf(1, "Running test suite: %s\n", file);
    exec(file, argv);
  }
  int wpid;
  while ((wpid=wait())>=0 && wpid!=pid)
    __ulibc_printf(1, "zombie!\n");
}

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
}

int main(void)
{
  setup_devices();

  dup(0);  // stdout
  dup(0);  // stderr

  run_test("stdlib");
  run_test("string");

  halt();
  return 0;
}
