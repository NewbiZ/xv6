#include <ulibc/ulibc.h>
#include <ulibc/stdlib.h>
#include <ulibc/string.h>

#undef NDEBUG
#include <ulibc/assert.h>

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

// Spec: C89 section 4.11.2.1
void test_memcpy(void)
{
  char input[10] = {[0 ... 9] = 42};
  char output[10] = {[0 ... 9] = 0};
  void* res = memcpy(output, input, 10);

  assert(res == output);
  TEST_BUFFER(input, output, 10);
}

// Spec: C89 section 4.11.2.2
void test_memmove(void)
{
  char input[5] = {[0]=0, [1]=1, [2]=2, [3]=3, [4]=4};
  char expected[3] = {[0]=0, [1]=1, [2]=2};
  char* output = input+2;
  void* res = memmove(output, input, 3);

  assert(res == output);
  TEST_BUFFER(output, expected, 3);
}

// Spec: C89 section 4.11.2.3
void test_strcpy(void)
{
  char input[] = "this is a test";
  char output[sizeof(input)];

  char* res = strcpy(output, input);

  assert(res == output);
  TEST_BUFFER(output, input, sizeof(input));
}

// Spec: C89 section 4.11.2.4
void test_strncpy(void)
{
  char input[] = "test";
  char output[10] = {[0 ... 9] = '?'};

  char* res = strncpy(output, input, sizeof(input));

  assert(res == output);
  TEST_BUFFER(output, input, sizeof(input));
}

void test_strcat(void)
{
}

void test_strncat(void)
{
}

void test_memcmp(void)
{
}

void test_strcmp(void)
{
}

void test_strcoll(void)
{
}

void test_strncmp(void)
{
}

void test_strxfrm(void)
{
}

void test_memchr(void)
{
}

void test_strchr(void)
{
}

void test_strcspn(void)
{
}

void test_strpbrk(void)
{
}

void test_strrchr(void)
{
}

void test_strspn(void)
{
}

void test_strstr(void)
{
}

void test_strtok(void)
{
}

void test_memset(void)
{
}

void test_strerror(void)
{
}

void test_strlen(void)
{
}

int main(int argc, char** argv)
{
  test_memcpy();
  test_memmove();
  test_strcpy();
  test_strncpy();
  test_strcat();
  test_strncat();
  test_memcmp();
  test_strcmp();
  test_strcoll();
  test_strncmp();
  test_strxfrm();
  test_memchr();
  test_strchr();
  test_strcspn();
  test_strpbrk();
  test_strrchr();
  test_strspn();
  test_strstr();
  test_strtok();
  test_memset();
  test_strerror();
  test_strlen();

  exit(1);
  return EXIT_SUCCESS;
}

