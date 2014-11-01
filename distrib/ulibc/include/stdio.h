#ifndef ULIBC_STDIO_H
#define ULIBC_STDIO_H

#include <stdarg.h>

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

typedef unsigned int fpos_t;

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ 1024

#define EOF (-1)

#define FOPEN_MAX 1000

#define FILENAME_MAX 4096

#define L_tmpnam 20

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define TMP_MAX 10000

typedef struct __FILE {
  int    fd;
  char*  buffer;
  char*  rd_pos;
  char*  wr_pos;
  fpos_t read_off_beg;
  fpos_t read_off_pos;
  fpos_t read_off_end;
  fpos_t write_off_beg;
  fpos_t write_off_pos;
  fpos_t write_off_end;
  int    error;
  int    eof;
  int    mode;
  int    flags;
} FILE;

extern FILE* const stdin;
extern FILE* const stdout;
extern FILE* const stderr;

int remove(const char* filename);
int rename(const char* src, const char* dst);
FILE* tmpfile(void);
char* tmpnam(char* s);
int fclose(FILE* stream);
int fflush(FILE* stream);
FILE* fopen(const char* filename, const char* mode);
FILE* freopen(const char* filename, const char* mode, FILE* stream);
void setbuf(FILE* stream, char* buf);
int setvbuf(FILE* stream, char* buf, int mode, size_t size);
int fprintf(FILE* stream, const char* format, ...);
int fscanf(FILE* stream, const char* format, ...);
int printf(const char* format, ...);
int scanf(const char* format, ...);
int sprintf(char* s, const char* format, ...);
int sscanf(const char* s, const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list arg);
int vprintf(const char* format, va_list arg);
int vsprintf(char* s, const char* format, va_list arg);
int fgetc(FILE* stream);
char* fgets(char* s, int n, FILE* stream);
int fputc(int c, FILE* stream);
int fputs(const char* s, FILE* stream);
int getc(FILE* stream);
int getchar(void);
char* gets(char* s);
int putc(int c, FILE* stream);
int putchar(int c);
int puts(const char* s);
int ungetc(int c, FILE* stream);
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);
size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream);
int fgetpos(FILE* stream,fpos_t* pos);
int fseek(FILE* stream, long int offset, int whence);
int fsetpos(FILE* stream, const fpos_t* pos);
long int ftell(FILE* stream);
void rewind(FILE* stream);
void clearerr(FILE* stream);
int feof(FILE* stream);
int ferror(FILE* stream);
void perror(const char* s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ULIBC_STDIO_H */

