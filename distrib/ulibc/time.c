#include <ulibc/time.h>

#include <ulibc/assert.h>

clock_t clock(void)
{
  assert(0 && "not implemented yet.");
  return 0;
}

double difftime(time_t time1, time_t time0)
{
  assert(0 && "not implemented yet.");
  return 0;
}

time_t mktime(struct tm* timeptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

time_t time(time_t* timer)
{
  assert(0 && "not implemented yet.");
  return 0;
}

char* asctime(const struct tm* timeptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

char* ctime(const time_t* timer)
{
  assert(0 && "not implemented yet.");
  return 0;
}

struct tm* gmtime(const time_t* timer)
{
  assert(0 && "not implemented yet.");
  return 0;
}

struct tm* localtime(const time_t* timer)
{
  assert(0 && "not implemented yet.");
  return 0;
}

size_t strftime(char* s, size_t maxsize, const char* format, const struct tm* timeptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

