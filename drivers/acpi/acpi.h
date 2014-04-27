#ifndef ACPI_H
#define ACPI_H

/*
  This struct represents a pointer to a RSD table
  as specified in ACPI1:

  - signature, should be "RDP PTR "
  - checksum,  designed so that if you add all bytes of the header, the least
               significant byte is 0
  - oemid,     ACPI implementer
  - revision,  0=ACPI1, 1=ACPI2
  - rsdtaddr,  address of RSDT
*/
struct rsdp
{
  char          signature[8];
  char          checksum;
  char          oemid[6];
  unsigned char revision;
  char*         rsdtaddr;
} __attribute__((packed));

/*
  This structure represents the RSD table itself.
*/
struct rsdt_header
{
  char          signature[4];
  unsigned int  length;
  unsigned char revision;
  unsigned char checksum;
  char          oemid[6];
  char          oemtableid[8];
  unsigned int  oemrevision;
  unsigned int  creatorid;
  unsigned int  creatorrevision;
} __attribute__((packed));

void         acpiinit(void);
struct rsdp* find_rsdp(void);

#endif // ACPI_H
