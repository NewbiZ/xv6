#include <stdlib.h>
#include <syscall.h>
#include <ctype.h>
#include <assert.h>

// TODO: posix requires this 32 to be ATEXIT_MAX
static void (*__ulibc_atexit_func[32])(void);
static void (**__ulibc_atexit_func_cur)(void) = __ulibc_atexit_func;

int atexit(void (*func)(void))
{
  if (__ulibc_atexit_func_cur<__ulibc_atexit_func+32)
  {
    *(__ulibc_atexit_func_cur++) = func;
    return 0;
  }
  return 1;
}

void exit(int status)
{
  while (__ulibc_atexit_func_cur>=__ulibc_atexit_func)
    (*__ulibc_atexit_func_cur--)();
  sysexit();
}

