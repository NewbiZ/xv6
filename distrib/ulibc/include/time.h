#ifndef ULIBC_TIME_H
#define ULIBC_TIME_H

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

#define CLK_TCK 100

typedef long clock_t;
typedef long time_t;

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

clock_t clock(void);
double difftime(time_t time1, time_t time0);
time_t mktime(struct tm* timeptr);
time_t time(time_t* timer);
char* asctime(const struct tm* timeptr);
char* ctime(const time_t* timer);
struct tm* gmtime(const time_t* timer);
struct tm* localtime(const time_t* timer);
size_t strftime(char* s, size_t maxsize, const char* format, const struct tm* timeptr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ULIBC_TIME_H */

