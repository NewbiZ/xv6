#include <types.h>
#include <defs.h>

#include "acpi.h"

void acpiinit(void)
{
  find_rsdp();
}

const char* find_rsdp(void)
{
  static const char* const rsdp_start  = (char*)0x000E0000;
  static const char* const rsdp_end    = (char*)0x00100000;
  static const char  rsdp_sig[8] = "RSD PTR ";
  struct rsdp_t*     rsdpp = 0;
  const char*        addr;
  char               checksum = 0;

  for (addr=rsdp_start; addr<rsdp_end; addr+=0x10)
  {
    if (memcmp(addr, rsdp_sig, 8) == 0)
    {
      rsdpp = (struct rsdp_t*)addr;
      // Verify checksum
      for (; addr<(char*)rsdpp+sizeof(struct rsdp_t); ++addr)
        checksum += *addr;
      if (checksum)
        continue;

      cprintf("Found ACPI%d RSDP", (rsdpp->revision==0 ? 1 : 2));
      break;
    }
  }

  if (!rsdpp)
    cprintf("RSDP not found");

  return addr;
}
