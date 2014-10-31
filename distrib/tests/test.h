#ifndef ULIBC_TESTS_TEST_H
#define ULIBC_TESTS_TEST_H

#include <ulibc/ulibc.h>
#include <ulibc/stdlib.h>
#include <ulibc/stdio.h>

#undef NDEBUG
#include <ulibc/assert.h>

#define TEST_FLOAT(c, res)                        \
  {                                               \
    float r = (c);                                \
    if (r != (res))                               \
    {                                             \
      fprintf(stderr, "Test failed: %s\n", (#c)); \
      fprintf(stderr, "Obtained: %f\n", r);       \
      fprintf(stderr, "Expected: %f\n", (res));   \
      abort();                                    \
    }                                             \
  }

#define TEST_INT(c, res)                          \
  {                                               \
    int r = (c);                                  \
    if (r != (res))                               \
    {                                             \
      fprintf(stderr, "Test failed: %s\n", (#c)); \
      fprintf(stderr, "Obtained: %d\n", r);       \
      fprintf(stderr, "Expected: %d\n", (res));   \
      abort();                                    \
    }                                             \
  }

#define TEST_LONG(c, res)                         \
  {                                               \
    long r = (c);                                 \
    if (r != (res))                               \
    {                                             \
      fprintf(stderr, "Test failed: %s\n", (#c)); \
      fprintf(stderr, "Obtained: %l\n", r);       \
      fprintf(stderr, "Expected: %l\n", (res));   \
      abort();                                    \
    }                                             \
  }

#define TEST_PTR(c, res)                          \
  {                                               \
    const void* r = (c);                          \
    if (r != (res))                               \
    {                                             \
      fprintf(stderr, "Test failed: %s\n", (#c)); \
      fprintf(stderr, "Obtained: 0x%x\n", r);     \
      fprintf(stderr, "Expected: 0x%x\n", (res)); \
      abort();                                    \
    }                                             \
  }

#define TEST_STR(s1, s2)                                  \
  {                                                       \
    if (strcmp((s1), (s2)))                               \
    {                                                     \
      fprintf(stderr, "%s:%d\n", __FILE__, __LINE__);     \
      fprintf(stderr, "\"%s\" != \"%s\"\n", (s1), (s2));  \
      abort();                                            \
    }                                                     \
  }

#define TEST_BUFFER(src, dst, sz)                      \
  {                                                    \
    int _i = 0;                                        \
    for (; _i<(sz); ++_i)                              \
    {                                                  \
      if ((src)[_i] != (dst)[_i])                      \
      {                                                \
        fprintf(stderr, "%s:%d ", __FILE__, __LINE__); \
        fprintf(stderr, "at offset %d: %d != %d\n",    \
            _i, (src)[_i], (dst)[_i]);                 \
        abort();                                       \
      }                                                \
    }                                                  \
  }

#endif // ULIBC_TESTS_TEST_H

