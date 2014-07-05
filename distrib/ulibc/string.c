#include <ulibc/string.h>

#include <ulibc/stdlib.h>
#include <ulibc/assert.h>
#include <ulibc/errno.h>

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

char* strcat(char* s1, const char* s2)
{
  char* b = s1;

  while (*s1) ++s1;
  while (*s2) *s1++ = *s2++;
  *s1 = 0;

  return b;
}

char* strncat(char* s1, const char* s2, size_t n)
{
  size_t dstlen = strlen(s1);
  size_t i = 0;

  for (; i<n && s2[i]!=0 ; ++i)
    s1[dstlen+i] = s2[i];
  s1[dstlen+i] = 0;

  return s1;
}

int memcmp(const void* s1, const void* s2, size_t n)
{
  const unsigned char *us1=s1, *us2=s2;
  for (; n && *us1==*us2; n--, us1++, us2++);
  return n ? *us1-*us2 : 0;
}

int strcmp(const char* s1, const char* s2)
{
  for (; *s1 && *s2 && *s1==*s2; s1++, s2++);
  return *(unsigned char*)s1-*(unsigned char*)s2;
}

int strcoll(const char* s1, const char* s2)
{
  return strcmp(s1, s2);
}

int strncmp(const char* s1, const char* s2, size_t n)
{
  for (; --n && *s1 && *s2 && *s1==*s2; s1++, s2++);
  return *(unsigned char*)s1-*(unsigned char*)s2;
}

size_t strxfrm(char* s1, const char* s2, size_t n)
{
  size_t l = strlen(s2);
  if (n > l)
    strcpy(s1, s2);
  return l;
}

void* memchr(const void* s, int c, size_t n)
{
  for (; n && *(unsigned char*)s!=c; ++s, --n);
  return n ? (void*)s : NULL;
}

char* strchr(const char* s, int c)
{
  for (; *s && *(unsigned char*)s!=c; ++s);
  return *s==0 ? NULL : (char*)s;
}

size_t strcspn(const char* s1, const char* s2)
{
  const char* b = s1;
  for (; *s1 && !strchr(s2, *s1); ++s1);
  return s1-b;
}

char* strpbrk(const char* s1, const char* s2)
{
  s1 += strcspn(s1, s2);
  return *s1 ? (char*)s1 : NULL;
}

char* strrchr(const char* s, int c)
{
  const char* b = s;
  while(*s++);
  for (; s>=b && *(unsigned char*)s!=c; --s);
  return s<b ? NULL : (char*)s;
}

size_t strspn(const char* s1, const char* s2)
{
  const char* b = s1;
  for (; *s1 && strchr(s2, *s1); ++s1);
  return s1-b;
}

char* strstr(const char* s1, const char* s2)
{
  const char* b2 = s2;
  if (!*s2)
    return (char*)s1;
  for (; *s1 && *s2; ++s1)
  {
    if (*s1==*s2)
      ++s2;
    else
      s2 = b2;
  }
  return *s2 ? NULL : (char*)(s1-(s2-b2));
}

char* strtok(char* s1, const char* s2)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void* memset(void* s, int c, size_t n)
{
  void* b = s;
  for (; n-- && (*(unsigned char*)s=(unsigned char)c); ++s);
  return b;
}

int __ulibc_error_codes[] = {
#define X(code, msg) code,
#include "strerror.h"
#undef X
};

char* __ulibc_error_msgs[] = {
#define X(code, msg) msg,
#include "strerror.h"
#undef X
};

char* strerror(int errnum)
{
  size_t i = 0;
  for (; __ulibc_error_codes[i]!=errnum && __ulibc_error_codes[i]!=0; ++i);
  return __ulibc_error_msgs[i];
}

size_t strlen(const char* s)
{
  const char* b = s;
  while (*s++);
  return s-b-1;
}

