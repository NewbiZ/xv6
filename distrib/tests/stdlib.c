#include <ulibc/ulibc.h>
#include <ulibc/stdlib.h>
#include <ulibc/limits.h>

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

// Spec: C89 section 4.10.1.2
void test_atoi(void)
{
  // Simple cases
  TEST_INT(atoi("1"), 1);
  TEST_INT(atoi("42"), 42);
  // Handle signs
  TEST_INT(atoi("+42"), 42);
  TEST_INT(atoi("-42"), -42);
  // Handle beginning whitespaces
  TEST_INT(atoi("   42"), 42);
  TEST_INT(atoi("  +42"), 42);
  TEST_INT(atoi(" -42"), -42);
  // Handle limit cases
  TEST_INT(atoi("2147483647"), INT_MAX); //TODO: i386 only
  TEST_INT(atoi("+2147483647"), INT_MAX); //TODO: i386 only
  TEST_INT(atoi("-2147483648"), INT_MIN); //TODO: i386 only
  // Everything else is undefined behavior by spec
}

// Spec: C89 section 4.10.1.3
void test_atol(void)
{
  // Simple cases
  TEST_LONG(atol("1"), 1);
  TEST_LONG(atol("42"), 42);
  // Handle signs
  TEST_LONG(atol("+42"), 42);
  TEST_LONG(atol("-42"), -42);
  // Handle beginning whitespaces
  TEST_LONG(atol("   42"), 42);
  TEST_LONG(atol("  +42"), 42);
  TEST_LONG(atol(" -42"), -42);
  // Handle limit cases
  TEST_LONG(atol("2147483647"), LONG_MAX); //TODO: i386 only
  TEST_LONG(atol("+2147483647"), LONG_MAX); //TODO: i386 only
  TEST_LONG(atol("-2147483648"), LONG_MIN); //TODO: i386 only
  // Everything else is undefined behavior by spec
}

// Spec: C89 section 4.10.4.2
void test_atexit(void)
{
  // We should support at least 32 atexit functions
  // We will add 31 functions that increment this counter
  static unsigned int counter = 0;
  void func_inc(void) { counter++; }
  // And one function to check that it has been incremented 31 times
  void func_check(void) { assert(counter == 31); } //TODO: posix requires ATEXIT_MAX
  // Register the functions, checking that return is 0
  if (atexit(func_check))
    abort();
  int i = 0;
  for (; i<31; ++i) //TODO: posix requires ATEXIT_MAX
    if (atexit(func_inc))
      abort();
  // Force exit
  exit(EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
  test_atoi();
  test_atol();
  test_atexit(); // This should be tested last!

  return EXIT_SUCCESS;
}

