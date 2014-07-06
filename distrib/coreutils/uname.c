#include <ulibc/ulibc.h>
#include <ulibc/string.h>
#include <ulibc/stdlib.h>

void print_kernel_name()
{
  __ulibc_printf(1, "Xv6 ");
}

void print_node_name()
{
  __ulibc_printf(1, "localhost ");
}

void print_kernel_release()
{
  __ulibc_printf(1, "0.1 ");
}

void print_kernel_version()
{
  __ulibc_printf(1, "yolo ");
}

void print_machine()
{
  __ulibc_printf(1, "i386 ");
}

void print_processor()
{
  __ulibc_printf(1, "i386 ");
}

void print_hardware_platform()
{
  __ulibc_printf(1, "i386 ");
}

void print_operating_system()
{
  __ulibc_printf(1, "Xv6 ");
}

void print_version()
{
  __ulibc_printf(1, "uname (Xv6 coreutils) 0.1\n");
  __ulibc_printf(1, "Written by Aurelien Vallee.\n");
  sysexit();
}

void print_help()
{
  __ulibc_printf(1, "Usage: uname [OPTIONS] [--help] [--version]\n");
  __ulibc_printf(1, "\n");
  __ulibc_printf(1, "-a, --all               ");
  __ulibc_printf(1, "print all information, except -p and -i.\n");
  __ulibc_printf(1, "-s, --kernel-name       ");
  __ulibc_printf(1, "print the kernel name\n");
  __ulibc_printf(1, "-n, --node-name         ");
  __ulibc_printf(1, "print the network node name\n");
  __ulibc_printf(1, "-r, --kernel-release    ");
  __ulibc_printf(1, "print the kernel release\n");
  __ulibc_printf(1, "-v, --kernel-version    ");
  __ulibc_printf(1, "print the kernel version\n");
  __ulibc_printf(1, "-m, --machine           ");
  __ulibc_printf(1, "print the machine hardware name\n");
  __ulibc_printf(1, "-p, --processor         ");
  __ulibc_printf(1, "print the processor type or \"unknown\"\n");
  __ulibc_printf(1, "-i, --hardware-platform ");
  __ulibc_printf(1, "print the hardware platform or \"unknown\"\n");
  __ulibc_printf(1, "-o, --operating-system  ");
  __ulibc_printf(1, "print the operating system\n");
  __ulibc_printf(1, "    --help              ");
  __ulibc_printf(1, "display this help and exit\n");
  __ulibc_printf(1, "    --version           ");
  __ulibc_printf(1, "display version information and exit\n");
  sysexit();
}

enum {
  KERNEL_NAME       = 0x001,
  NODE_NAME         = 0x002,
  KERNEL_RELEASE    = 0x004,
  KERNEL_VERSION    = 0x008,
  MACHINE           = 0x010,
  PROCESSOR         = 0x020,
  HARDWARE_PLATFORM = 0x040,
  OPERATING_SYSTEM  = 0x080,
  HELP              = 0x100,
  VERSION           = 0x200,
  ALL               = 0x08F,
} args;

int main(int argc, char** argv)
{
  args = KERNEL_NAME;
  int i = 1;
  for (; i<argc; ++i)
  {
    if (!strcmp("-a", argv[i]) || !strcmp("--all", argv[i]))
    {
      args |= ALL;
      continue;
    }
    if (!strcmp("-s", argv[i]) || !strcmp("--kernel-name", argv[i]))
    {
      args |= KERNEL_NAME;
      continue;
    }
    if (!strcmp("-n", argv[i]) || !strcmp("--node-name", argv[i]))
    {
      args |= NODE_NAME;
      continue;
    }
    if (!strcmp("-r", argv[i]) || !strcmp("--kernel-release", argv[i]))
    {
      args |= KERNEL_RELEASE;
      continue;
    }
    if (!strcmp("-v", argv[i]) || !strcmp("--kernel-version", argv[i]))
    {
      args |= KERNEL_VERSION;
      continue;
    }
    if (!strcmp("-m", argv[i]) || !strcmp("--machine", argv[i]))
    {
      args |= MACHINE;
      continue;
    }
    if (!strcmp("-p", argv[i]) || !strcmp("--processor", argv[i]))
    {
      args |= PROCESSOR;
      continue;
    }
    if (!strcmp("-i", argv[i]) || !strcmp("--hardware-platform", argv[i]))
    {
      args |= HARDWARE_PLATFORM;
      continue;
    }
    if (!strcmp("-o", argv[i]) || !strcmp("--operating-system", argv[i]))
    {
      args |= OPERATING_SYSTEM;
      continue;
    }
    if (!strcmp("--help", argv[i]))
    {
      args |= HELP;
      continue;
    }
    if (!strcmp("--version", argv[i]))
    {
      args |= VERSION;
      continue;
    }

    print_help();
    sysexit();
  }

  if (args & HELP)
    print_help();
  if (args & VERSION)
    print_version();
  if (args & KERNEL_NAME)
    print_kernel_name();
  if (args & NODE_NAME)
    print_node_name();
  if (args & KERNEL_RELEASE)
    print_kernel_release();
  if (args & KERNEL_VERSION)
    print_kernel_version();
  if (args & MACHINE)
    print_machine();
  if (args & PROCESSOR)
    print_processor();
  if (args & HARDWARE_PLATFORM)
    print_hardware_platform();
  if (args & OPERATING_SYSTEM)
    print_operating_system();

  __ulibc_printf(1, "\n");

  sysexit();
  return 0;
}

