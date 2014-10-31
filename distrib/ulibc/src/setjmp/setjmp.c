#include <setjmp.h>

int setjmp(jmp_buf env)
{
  __asm__ __volatile__ (
    "mov %%ebx,    (%[env])   \n\t"
    "mov %%esi,    4(%[env])  \n\t"
    "mov %%edi,    8(%[env])  \n\t"
    "mov %%ebp,    12(%[env]) \n\t"
    "lea 4(%%esp), %%ecx      \n\t"
    "mov %%ecx,    16(%[env]) \n\t"
    "mov (%%esp),  %%ecx      \n\t"
    "mov %%ecx,    20(%[env]) \n\t"
    : // No outputs
    : [env] "r" (env)
  );
  return 0;
}

