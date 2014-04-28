top_srcdir = ..
include $(top_srcdir)/Makefile.common

KERNEL_BOOT_OBJS = \
	main.o           \
	entry.o          \

.PHONY: all clean

all: kernel_boot.o entryother bootblock

kernel_boot.o: $(KERNEL_BOOT_OBJS)
	@echo "[LD] [BOOT   ] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

entryother: entryother.S
	@$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c entryother.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	@$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother > /dev/null 2>&1

bootblock: bootasm.S bootmain.c
	@$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c bootmain.c
	@$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c bootasm.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	@$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock > /dev/null 2>&1
	@../tools/boot_sign.pl bootblock

%.o: %.c
	@echo "[CC] [BOOT   ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	@echo "[CC] [BOOT   ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.S

clean:
	$(RM) -rf *.o
	$(RM) -rf entryother
	$(RM) -rf bootblock
