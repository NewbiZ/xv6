#include <ulibc/stdio.h>

#include <ulibc/assert.h>

static FILE _stdin = {
  .fd = 0,
  .buffer = NULL,
  .read_off_beg = 0,
  .read_off_pos = 0,
  .read_off_end = 0,
  .write_off_beg = 0,
  .write_off_pos = 0,
  .write_off_end = 0,
  .error = 0,
  .eof = 0
};

static FILE _stdout = {
  .fd = 1,
  .buffer = NULL,
  .read_off_beg = 0,
  .read_off_pos = 0,
  .read_off_end = 0,
  .write_off_beg = 0,
  .write_off_pos = 0,
  .write_off_end = 0,
  .error = 0,
  .eof = 0
};

static FILE _stderr = {
  .fd = 2,
  .buffer = NULL,
  .read_off_beg = 0,
  .read_off_pos = 0,
  .read_off_end = 0,
  .write_off_beg = 0,
  .write_off_pos = 0,
  .write_off_end = 0,
  .error = 0,
  .eof = 0
};

FILE* const stdin  = &_stdin;
FILE* const stdout = &_stdout;
FILE* const stderr = &_stderr;

int remove(const char* filename)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int rename(const char* src, const char* dst)
{
  assert(0 && "not implemented yet.");
  return 0;
}

FILE* tmpfile(void)
{
  assert(0 && "not implemented yet.");
  return 0;
}

char* tmpnam(char* s)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fclose(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fflush(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

FILE* fopen(const char* filename, const char* mode)
{
  assert(0 && "not implemented yet.");
  return 0;
}

FILE* freopen(const char* filename, const char* mode, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void setbuf(FILE* stream, char* buf)
{
  assert(0 && "not implemented yet.");
}

int setvbuf(FILE* stream, char* buf, int mode, size_t size)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fprintf(FILE* stream, const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fscanf(FILE* stream, const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int printf(const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int scanf(const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int sprintf(char* s, const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int sscanf(const char* s, const char* format, ...)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int vfprintf(FILE* stream, const char* format, va_list arg)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int vprintf(const char* format, va_list arg)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int vsprintf(char* s, const char* format, va_list arg)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fgetc(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

char* fgets(char* s, int n, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fputc(int c, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fputs(const char* s, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int getc(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int getchar(void)
{
  assert(0 && "not implemented yet.");
  return 0;
}

char* gets(char* s)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int putc(int c, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int putchar(int c)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int puts(const char* s)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int ungetc(int c, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fgetpos(FILE* stream,fpos_t* pos)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fseek(FILE* stream, long int offset, int whence)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int fsetpos(FILE* stream, const fpos_t* pos)
{
  assert(0 && "not implemented yet.");
  return 0;
}

long int ftell(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void rewind(FILE* stream)
{
  assert(0 && "not implemented yet.");
}

void clearerr(FILE* stream)
{
  assert(0 && "not implemented yet.");
}

int feof(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

int ferror(FILE* stream)
{
  assert(0 && "not implemented yet.");
  return 0;
}

void perror(const char* s)
{
  assert(0 && "not implemented yet.");
}

