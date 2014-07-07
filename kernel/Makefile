TOP_SRCDIR = ..
COMPONENT = KERNEL 
include $(TOP_SRCDIR)/Makefile.common

KERNEL_OBJS = \
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
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

initcode: initcode.S
	$(LOG_CC) $(CC) $(CFLAGS) -nostdinc -I. -c initcode.S
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(LOG_CMD) $(OBJCOPY) -S -O binary initcode.out initcode > /dev/null 2>&1

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	$(LOG_CC) $(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(LOG_CMD) $(RM) -rf *.o
	$(LOG_CMD) $(RM) -rf initcode initcode.out
