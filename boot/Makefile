TOP_SRCDIR = ..
COMPONENT = BOOT   
include $(TOP_SRCDIR)/Makefile.common

KERNEL_BOOT_OBJS = \
	main.o           \
	entry.o          \

.PHONY: all clean

all: kernel_boot.o entryother bootblock

kernel_boot.o: $(KERNEL_BOOT_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

entryother: entryother.S
	$(LOG_CC) $(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c entryother.S
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(LOG_CMD) $(OBJCOPY) -S -O binary -j .text bootblockother.o entryother > /dev/null 2>&1

bootblock: bootasm.S bootmain.c
	$(LOG_CC) $(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c bootmain.c
	$(LOG_CC) $(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c bootasm.S
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(LOG_CMD) $(OBJCOPY) -S -O binary -j .text bootblock.o bootblock > /dev/null 2>&1
	$(LOG_CMD) ../tools/boot_sign.pl bootblock

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.S

clean:
	$(LOG_CMD) $(RM) -rf *.o
	$(LOG_CMD) $(RM) -rf entryother
	$(LOG_CMD) $(RM) -rf bootblock
