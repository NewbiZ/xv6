#include <ulibc/signal.h>
#include <ulibc/assert.h>

void (*signal(int sig, void (*func)(int)))(int)
{
  assert(0 && "not implemented yet");
  return 0;
}

int raise(int sig)
{
  assert(0 && "not implemented yet");
  return 0;
}

