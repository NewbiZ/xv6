#include <signal.h>
#include <assert.h>

void (*signal(int sig, void (*func)(int)))(int)
{
  assert(0 && "not implemented yet");
  return 0;
}

