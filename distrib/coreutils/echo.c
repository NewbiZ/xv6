#include "../../include/types.h"
#include "../../include/stat.h"

#include "../ulibc/ulibc.h"

int
main(int argc, char *argv[])
{
  int i;

  for(i = 1; i < argc; i++)
    printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  exit();
}
