#ifndef DIRENT_H
#define DIRENT_H

#include <xv6/stdio.h>

struct dirent
{
  ushort d_ino;
  char   d_name[NAME_MAX];
};

#endif // DIRENT_H
