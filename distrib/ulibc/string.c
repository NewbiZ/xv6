#include <ulibc/string.h>

#include <ulibc/stdlib.h>
#include <ulibc/assert.h>

void* memcpy(void* s1, const void* s2, size_t n)
{
  void* b = s1;
  while (n--)
    *(char*)s1++ = *(char*)s2++;
  return b;
}

void* memmove(void* s1, const void* s2, size_t n)
{
  char* bkp = (char*)malloc(n);
  memcpy(bkp, s2, n);
  memcpy(s1, bkp, n);
  free(bkp);
  return s1;
}

char* strcpy(char* s1, const char* s2)
{
  char* b = s1;
  while ((*s1++=*s2++));
  return b;
}

char* strncpy(char* s1, const char* s2, size_t n)
{
  size_t i = 0;

  for (; i<n && s2[i]!=0; ++i)
    s1[i] = s2[i];
  for ( ; i < n; i++)
    s1[i] = 0;

  return s1;
}

char *strcat(char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strncat(char *s1, const char *s2, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int strcmp(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int strcoll(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t strxfrm(char *s1, const char *s2, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void *memchr(const void *s, int c, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strchr(const char *s, int c)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t strcspn(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strpbrk(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strrchr(const char *s, int c)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t strspn(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strstr(const char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strtok(char *s1, const char *s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void *memset(void *s, int c, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

char *strerror(int errnum)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t strlen(const char *s)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

