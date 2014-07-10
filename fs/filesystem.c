#include <xv6/fs.h>

static struct filesystem_type __xv6_filesystems[MAX_FS];
static unsigned int __xv6_filesystems_count = 0;

void register_filesystem(struct filesystem_type* fst)
{
  if (__xv6_filesystems_count > MAX_FS)
    return;
  __xv6_filesystems[__xv6_filesystems_count++];
}

