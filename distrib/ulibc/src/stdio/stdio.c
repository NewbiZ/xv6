#include <stdio.h>

#include <xv6/fcntl.h>

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
  .eof = 0,
  .mode = O_RDONLY,
  .flags = _IOLBF
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
  .eof = 0,
  .mode = O_WRONLY,
  .flags = _IOLBF
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
  .eof = 0,
  .mode = O_WRONLY,
  .flags = _IONBF
};

FILE* const stdin  = &_stdin;
FILE* const stdout = &_stdout;
FILE* const stderr = &_stderr;

