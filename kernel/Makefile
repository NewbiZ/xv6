top_srcdir = ..
include $(top_srcdir)/Makefile.common

KERNEL_OBJS = \
	console.o   \
	exec.o      \
	file.o      \
	ioapic.o    \
	kalloc.o    \
	mp.o        \
	picirq.o    \
	pipe.o      \
	proc.o      \
	spinlock.o  \
	swtch.o     \
	syscall.o   \
	sysfile.o   \
	sysproc.o   \
	timer.o     \
	trapasm.o   \
	trap.o      \
	vectors.o   \
	string.o    \
	lapic.o     \

.PHONY: all clean

all: kernel.o initcode

kernel.o: $(KERNEL_OBJS)
	@echo "[LD] [KERNEL ] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

initcode: initcode.S
	@$(CC) $(CFLAGS) -nostdinc -I. -c initcode.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	@$(OBJCOPY) -S -O binary initcode.out initcode > /dev/null 2>&1

%.o: %.c
	@echo "[CC] [KERNEL ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	@echo "[CC] [KERNEL ] $@"
	@$(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(RM) -rf *.o
	$(RM) -rf initcode initcode.out
