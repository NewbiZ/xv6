#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

#include <xv6/fcntl.h>

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

int main(void)
{
  if (open("console", O_RDWR) < 0)
  {
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }

  dup(0);  // stdout
  dup(0);  // stderr

  run_test("stdlib");
  run_test("string");

  halt();
  return 0;
}
