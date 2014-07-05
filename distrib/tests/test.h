#ifndef ULIBC_TESTS_TEST_H
#define ULIBC_TESTS_TEST_H

#include <ulibc/ulibc.h>
#include <ulibc/stdlib.h>

#undef NDEBUG
#include <ulibc/assert.h>

#define TEST_FLOAT(c, res)                          \
  {                                                 \
    float r = (c);                                  \
    if (r != (res))                                 \
    {                                               \
      __ulibc_printf(2, "Test failed: %s\n", (#c)); \
      __ulibc_printf(2, "Obtained: %f\n", r);       \
      __ulibc_printf(2, "Expected: %f\n", res);     \
      abort();                                      \
    }                                               \
  }

#define TEST_INT(c, res)                            \
  {                                                 \
    int r = (c);                                    \
    if (r != (res))                                 \
    {                                               \
      __ulibc_printf(2, "Test failed: %s\n", (#c)); \
      __ulibc_printf(2, "Obtained: %d\n", r);       \
      __ulibc_printf(2, "Expected: %d\n", res);     \
      abort();                                      \
    }                                               \
  }

#define TEST_LONG(c, res)                           \
  {                                                 \
    long r = (c);                                   \
    if (r != (res))                                 \
    {                                               \
      __ulibc_printf(2, "Test failed: %s\n", (#c)); \
      __ulibc_printf(2, "Obtained: %l\n", r);       \
      __ulibc_printf(2, "Expected: %l\n", res);     \
      abort();                                      \
    }                                               \
  }

#define TEST_PTR(c, res)                            \
  {                                                 \
    const void* r = (c);                            \
    if (r != (res))                                 \
    {                                               \
      __ulibc_printf(2, "Test failed: %s\n", (#c)); \
      __ulibc_printf(2, "Obtained: 0x%x\n", r);     \
      __ulibc_printf(2, "Expected: 0x%x\n", res);   \
      abort();                                      \
    }                                               \
  }

#define TEST_STR(s1, s2)                                \
  {                                                     \
    if (strcmp(s1, s2))                                 \
    {                                                   \
      __ulibc_printf(2, "%s:%d\n", __FILE__, __LINE__); \
      __ulibc_printf(2, "\"%s\" != \"%s\"\n", s1, s2);  \
      abort();                                          \
    }                                                   \
  }

#define TEST_BUFFER(src, dst, sz)                        \
  {                                                      \
    int _i = 0;                                          \
    for (; _i<sz; ++_i)                                  \
    {                                                    \
      if (src[_i] != dst[_i])                            \
      {                                                  \
        __ulibc_printf(2, "%s:%d ", __FILE__, __LINE__); \
        __ulibc_printf(2, "at offset %d: %d != %d\n",    \
            _i, src[_i], dst[_i]);                       \
        abort();                                         \
      }                                                  \
    }                                                    \
  }

#endif // ULIBC_TESTS_TEST_H
