#include <xv6/fs.h>

static struct filesystem_type procfs_type = {
  .name = "procfs",
  .flags = 0,
};

static void init(void)
{
  register_filesystem(&procfs_type);
}

