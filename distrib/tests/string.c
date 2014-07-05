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

// Spec: C89 section 4.11.4.1
void test_memcmp(void)
{
  char b1[] = {0, 1, 2, 3, 4};
  char b2[] = {0, 1, 2, 3, 4};
  char b3[] = {0, 1, 4, 3, 2};
  char b4[] = {4, 3, 2, 1, 0};

  TEST_INT(memcmp(b1, b2, sizeof(b1)), 0);
  TEST_INT(memcmp(b1, b3, sizeof(b1)), -2);
  TEST_INT(memcmp(b1, b4, sizeof(b1)), -4);
}

// Spec: C89 section 4.11.4.2
void test_strcmp(void)
{
  const char* s1 = "";
  const char* s2 = "test";
  const char* s3 = "Test";

  TEST_INT(strcmp(s1, s1), 0);
  TEST_INT(strcmp(s2, s2), 0);
  TEST_INT(strcmp(s2, s3), 't'-'T');
  TEST_INT(strcmp(s3, s2), 'T'-'t');
}

// Spec: C89 section 4.11.4.3
void test_strcoll(void)
{
  const char* s1 = "";
  const char* s2 = "test";
  const char* s3 = "Test";

  TEST_INT(strcmp(s1, s1), 0);
  TEST_INT(strcmp(s2, s2), 0);
  TEST_INT(strcmp(s2, s3), 't'-'T');
  TEST_INT(strcmp(s3, s2), 'T'-'t');
}

// Spec: C89 section 4.11.4.4
void test_strncmp(void)
{
  char s1[] = "";
  char s2[] = "test";
  char s3[] = "tesT";

  TEST_INT(strncmp(s1, s1, 5), 0);
  TEST_INT(strncmp(s2, s2, 5), 0);
  TEST_INT(strncmp(s2, s3, 5), 't'-'T');
  TEST_INT(strncmp(s3, s2, 5), 'T'-'t');
  TEST_INT(strncmp(s3, s2, 2), 0);
  TEST_INT(strncmp(s3, s2, 3), 0);
  TEST_INT(strncmp(s3, s2, 4), 'T'-'t');
  TEST_INT(strncmp(s3, s2, 5), 'T'-'t');
}

// Spec: C89 section 4.11.4.5
void test_strxfrm(void)
{
  char input[] = "test";
  char output[10] = {[0 ... 9] = '?'};

  size_t res = strxfrm(output, input, sizeof(input));

  TEST_INT(res, sizeof(input)-1);
  TEST_BUFFER(output, input, sizeof(input));
}

// Spec: C89 section 4.11.5.1
void test_memchr(void)
{
  char input[] = {1, 2, 3, 4, 5};

  TEST_PTR(memchr(input, 3, sizeof(input)), input+2);
  TEST_PTR(memchr(input, 1, sizeof(input)), input);
  TEST_PTR(memchr(input, 5, sizeof(input)), input+4);
  TEST_PTR(memchr(input, 6, sizeof(input)), NULL);
  TEST_PTR(memchr(input, 4, 3), NULL);
}

// Spec: C89 section 4.11.5.2
void test_strchr(void)
{
  const char* s1 = "";
  const char* s2 = "test";

  TEST_PTR(strchr(s1, 't'), NULL);
  TEST_PTR(strchr(s2, 't'), s2);
  TEST_PTR(strchr(s2, 's'), s2+2);
  TEST_PTR(strchr(s2, 'z'), NULL);
}

// Spec: C89 section 4.11.5.3
void test_strcspn(void)
{
  const char s1[] = "";
  const char s2[] = "test";
  const char s3[] = "se";
  const char s4[] = "s";

  TEST_INT(strcspn(s1, s2), 0);
  TEST_INT(strcspn(s2, s3), 1);
  TEST_INT(strcspn(s2, s1), sizeof(s2)-1);
  TEST_INT(strcspn(s2, s4), 2);
}

// Spec: C89 section 4.11.5.4
void test_strpbrk(void)
{
  const char s1[] = "";
  const char s2[] = "test";
  const char s3[] = "se";
  const char s4[] = "s";

  TEST_PTR(strpbrk(s1, s2), NULL);
  TEST_PTR(strpbrk(s2, s3), s2+1);
  TEST_PTR(strpbrk(s2, s1), NULL);
  TEST_PTR(strpbrk(s2, s4), s2+2);
}

// Spec: C89 section 4.11.5.5
void test_strrchr(void)
{
  char s1[] = "";
  char s2[] = "test";

  TEST_PTR(strrchr(s1, 't'), NULL);
  TEST_PTR(strrchr(s2, 't'), s2+sizeof(s2)-2);
  TEST_PTR(strrchr(s2, 'e'), s2+1);
  TEST_PTR(strrchr(s2, 'z'), NULL);
}

// Spec: C89 section 4.11.5.6
void test_strspn(void)
{
  const char s1[] = "";
  const char s2[] = "test";
  const char s3[] = "se";
  const char s4[] = "et";
  const char s5[] = "te";

  TEST_INT(strspn(s1, s2), 0);
  TEST_INT(strspn(s2, s3), 0);
  TEST_INT(strspn(s2, s1), 0);
  TEST_INT(strspn(s2, s4), 2);
  TEST_INT(strspn(s2, s5), 2);
}

// Spec: C89 section 4.11.5.7
void test_strstr(void)
{
  const char* s1 = "";
  const char* s2 = "test";
  const char* s3 = "te";
  const char* s4 = "es";
  const char* s5 = "st";

  TEST_PTR(strstr(s1, s2), NULL);
  TEST_PTR(strstr(s2, s1), s2);
  TEST_PTR(strstr(s2, s3), s2);
  TEST_PTR(strstr(s2, s4), s2+1);
  TEST_PTR(strstr(s2, s5), s2+2);
}

// Spec: C89 section 4.11.5.8
void test_strtok(void)
{
}

// Spec: C89 section 4.11.6.1
void test_memset(void)
{
  char output[10] = {[0 ... 9] = '?'};
  const char expected[10] = {[0 ... 4] = 1, [5 ... 9] = '?'};

  memset(output, 1, 5);

  TEST_BUFFER(output, expected, 10);
}
#include <ulibc/errno.h>
// Spec: C89 section 4.11.6.2
void test_strerror(void)
{
  TEST_STR(strerror(EDOM), "Domain error (EDOM).");
  TEST_STR(strerror(ERANGE), "Result out of range (ERANGE).");
  TEST_STR(strerror(0), "No error information.");
  TEST_STR(strerror(-1), "No error information.");
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

