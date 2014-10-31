#include <setjmp.h>

void longjmp(jmp_buf env, int val)
{
  if (val==0)
   val = 1;
  __asm__ __volatile__ (
    "mov (%[val]),   %%eax    \n\t"
    "mov (%[env]),   %%ebx    \n\t"
    "mov 4(%[env]),  %%esi    \n\t"
    "mov 8(%[env]),  %%edi    \n\t"
    "mov 12(%[env]), %%ebp    \n\t"
    "mov 16(%[env]), %%ecx    \n\t"
    "mov %%ecx,      %%esp    \n\t"
    "mov 20(%[env]), %%ecx    \n\t"
    "jmp *%%ecx               \n\t"
    : // No outputs
    : [env] "r" (env),
      [val] "r" (val)
  );
}

