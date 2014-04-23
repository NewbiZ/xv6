#ifndef ACPI_H
#define ACPI_H

struct rsdp_t
{
  // Should be "RDP PTR "
  char  signature[8];
  // Designed so that adding all bytes of this header overflow to 0
  char  checksum;
  // ACPI implementer
  char  oemid[6];
  // ACPI1=0, else ACPI2
  char  revision;
  // Address of RSDT
  char* rsdtaddr;
} __attribute__((packed));

void        acpiinit(void);
const char* find_rsdp(void);

#endif // ACPI_H
