#include <types.h>
#include <defs.h>

#include "acpi.h"

#define KLOGINFO(msg) cprintf("[\e[9mINFO\e[7m] " msg)
#define KLOGFAIL(msg) panic("[\e[12mFAIL\e[7m] " msg)
#define KLOGOK(msg)   cprintf("[\e[10m OK \e[7m] " msg)

void acpiinit(void)
{
  /*
  KLOGINFO("Initializing ACPI\n");

  struct rsdp* rsdpp = find_rsdp();
  if (!rsdpp)
  {
    KLOGFAIL("Failed to initialize ACPI\n");
    return;
  }
  KLOGINFO("Found RSDP version 1 in EBDA\n");

  cprintf("RSDT header at: %x", rsdpp->rsdtaddr);
  struct rsdt_header* rsdthp = (struct rsdt_header*)rsdpp->rsdtaddr;
  //cprintf("signature:       %s", rsdthp->signature);
  //cprintf("length:          %u", rsdthp->length);
  //cprintf("revision:        %c", rsdthp->revision);
  //cprintf("checksum:        %c", rsdthp->checksum);
  //cprintf("oemid:           %d", rsdthp->oemid);
  //cprintf("oemtableid:      %d", rsdthp->oemtableid);
  //cprintf("oemrevision:     %u", rsdthp->oemrevision);
  //cprintf("creatorid:       %u", rsdthp->creatorid);
  //cprintf("creatorrevision: %u", rsdthp->creatorrevision);

  KLOGOK("ACPI successfully initialized\n");
  */
}

struct rsdp* find_rsdp(void)
{
  static const char* const ebda_start  = (char*)0x000E0000;
  static const char* const ebda_end    = (char*)0x00100000;
  static unsigned int rsdp_align = 0x10;
  static const char rsdp_sig[8]  = "RSD PTR ";
  const char* addr;

  // Try to find the RSDP in the Extended BIOS Data Area (EBDA)
  // Here, RSDP should aligned on 16 bytes boundaries
  for (addr=ebda_start; addr<ebda_end; addr+=rsdp_align)
  {
    // Check for RSDP signature
    if (memcmp(addr, rsdp_sig, 8) == 0)
    {
      // Verify checksum, should sum up to 0
      char checksum = 0;
      const char* a;
      for (a=addr; a<addr+sizeof(struct rsdp); ++a)
        checksum += *a;
      if (checksum)
        continue;

      return (struct rsdp*)addr;
    }
  }

  return 0;
}
