#include <syscall.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_kernel_name()
{
  printf("Xv6 ");
}

void print_node_name()
{
  printf("localhost ");
}

void print_kernel_release()
{
  printf("0.1 ");
}

void print_kernel_version()
{
  printf("yolo ");
}

void print_machine()
{
  printf("i386 ");
}

void print_processor()
{
  printf("i386 ");
}

void print_hardware_platform()
{
  printf("i386 ");
}

void print_operating_system()
{
  printf("Xv6 ");
}

void print_version()
{
  printf("uname (Xv6 coreutils) 0.1\n");
  printf("Written by Aurelien Vallee.\n");
  sysexit();
}

void print_help()
{
  printf("Usage: uname [OPTIONS] [--help] [--version]\n");
  printf("\n");
  printf("-a, --all               ");
  printf("print all information, except -p and -i.\n");
  printf("-s, --kernel-name       ");
  printf("print the kernel name\n");
  printf("-n, --node-name         ");
  printf("print the network node name\n");
  printf("-r, --kernel-release    ");
  printf("print the kernel release\n");
  printf("-v, --kernel-version    ");
  printf("print the kernel version\n");
  printf("-m, --machine           ");
  printf("print the machine hardware name\n");
  printf("-p, --processor         ");
  printf("print the processor type or \"unknown\"\n");
  printf("-i, --hardware-platform ");
  printf("print the hardware platform or \"unknown\"\n");
  printf("-o, --operating-system  ");
  printf("print the operating system\n");
  printf("    --help              ");
  printf("display this help and exit\n");
  printf("    --version           ");
  printf("display version information and exit\n");
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

  printf("\n");

  sysexit();
  return 0;
}

