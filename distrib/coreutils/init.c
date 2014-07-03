#include <ulibc/ulibc.h>
#include <ulibc/stdio.h>

#include <xv6/fcntl.h>

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    fprintf(stdout, "init: starting sh\n");
    pid = fork();
    if(pid < 0){
      fprintf(stdout, "init: fork failed\n");
      sysexit();
    }
    if(pid == 0){
      exec("sh", argv);
      fprintf(stdout, "init: exec sh failed\n");
      sysexit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      fprintf(stdout, "zombie!\n");
  }
}
