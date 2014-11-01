#ifndef ULIBC_STDLIB_H
#define ULIBC_STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ULIBC_SIZE_T
#define ULIBC_SIZE_T
typedef unsigned int size_t;
#endif /* ULIBC_SIZE_T */

#ifdef __cplusplus
#define NULL 0L
#else /* __cplusplus */
#define NULL ((void*)0)
#endif /* __cplusplus */

typedef char wchar_t;

typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RAND_MAX 0x7fffffff

#define MB_CUR_MAX 1

double atof(const char* nptr);
int atoi(const char* nptr);
long int atol(const char* nptr);
double strtod(const char* nptr, char** endptr);
long int strtol(const char* nptr, char** endptr, int base);
unsigned long int strtoul(const char* nptr, char** endptr, int base);
int rand(void);
void srand(unsigned int seed);
void* calloc(size_t nmemb, size_t size);
void free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
void abort(void);
int atexit(void (*func)(void));
void exit(int status);
char* getenv(const char* name);
int system(const char* string);
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
int abs(int j);
div_t div(int numer, int denom);
long int labs(long int j);
ldiv_t ldiv(long int numer, long int denom);
int mblen(const char* s, size_t n);
int mbtowc(wchar_t* pwc, const char* s, size_t n);
int wctomb(char* s, wchar_t wchar);
size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n);
size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ULIBC_STDLIB_H */

