#include <ulibc/ulibc.h>
#include <ulibc/stdlib.h>
#include <ulibc/string.h>

#include "test.h"

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
  char* output = input+2;
  char expected[3] = {[0]=0, [1]=1, [2]=2};
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

// Spec: C89 section 4.11.3.1
void test_strcat(void)
{
  char s1[] = "s1";
  char s2[] = "s2";
  char s3[] = "s3";
  char out[7] = {[0] = 0, [1 ... 6] = '?'};
  char exp[] = "s1s2s3";

  strcat(out, s1);
  strcat(out, s2);
  strcat(out, s3);

  TEST_BUFFER(out, exp, sizeof(exp));
}

// Spec: C89 section 4.11.3.2
void test_strncat(void)
{
  char s1[] = "s1";
  char s2[] = "s2";
  char s3[] = "s3";
  char out[7] = {[0] = 0, [1 ... 6] = '?'};
  char exp[] = "s1s2s3";

  strncat(out, s1, 2);
  strncat(out, s2, 2);
  strncat(out, s3, 2);

  TEST_BUFFER(out, exp, sizeof(exp));
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

// Spec: C89 section 4.11.6.3
void test_strlen(void)
{
  char s1[] = "";
  char s2[] = "test";

  TEST_INT(strlen(s1), sizeof(s1)-1);
  TEST_INT(strlen(s2), sizeof(s2)-1);
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

