#include <stdio.h>

#include <xv6/fcntl.h>

static FILE _stdin = {
  0,
  NULL,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  O_RDONLY,
  _IOLBF
};

static FILE _stdout = {
  1,
  NULL,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  O_WRONLY,
  _IOLBF
};

static FILE _stderr = {
  2,
  NULL,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  O_WRONLY,
  _IONBF
};

FILE* const stdin  = &_stdin;
FILE* const stdout = &_stdout;
FILE* const stderr = &_stderr;

