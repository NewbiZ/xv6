#include <ulibc/stdlib.h>

#include <ulibc/assert.h>

double atof(const char* nptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int atoi(const char* nptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

long int atol(const char* nptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

double strtod(const char* nptr, char** endptr)
{
  assert(0 && "not implemented yet.");
  return 0;
}

long int strtol(const char* nptr, char** endptr, int base)
{
  assert(0 && "not implemented yet.");
  return 0;
}

unsigned long int strtoul(const char* nptr, char** endptr, int base)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int rand(void)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void srand(unsigned int seed)
{
  assert(0 && "not implemented yet.");
}

void* calloc(size_t nmemb, size_t size)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void free(void* ptr)
{
  assert(0 && "not implemented yet.");
}

void* malloc(size_t size)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void* realloc(void* ptr, size_t size)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void abort(void)
{
  assert(0 && "not implemented yet.");
}

int atexit(void (*func)(void))
{
  assert(0 && "not implemented yet.");
  return 0;
}

void exit(int status)
{
  assert(0 && "not implemented yet.");
}

char* getenv(const char* name)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int system(const char* string)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
  assert(0 && "not implemented yet.");
  return 0;
}

void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
  assert(0 && "not implemented yet.");
}

int abs(int j)
{
  assert(0 && "not implemented yet.");
  return 0;
}

div_t div(int numer, int denom)
{
  assert(0 && "not implemented yet.");
  div_t r;
  return r;
}

long int labs(long int j)
{
  assert(0 && "not implemented yet.");
  return 0;
}

ldiv_t ldiv(long int numer, long int denom)
{
  assert(0 && "not implemented yet.");
  ldiv_t r;
  return r;
}

int mblen(const char* s, size_t n)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int mbtowc(wchar_t* pwc, const char* s, size_t n)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int wctomb(char* s, wchar_t wchar)
{
  assert(0 && "not implemented yet.");
  return 0;
}

size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n)
{
  assert(0 && "not implemented yet.");
  return 0;
}

size_t wcstombs(char* s, const wchar_t* pwcs, size_t n)
{
  assert(0 && "not implemented yet.");
  return 0;
}

