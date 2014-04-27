CC = gcc
AS = gas
LD = ld
CFLAGS =                    \
	-fno-pic                  \
	-static                   \
	-fno-builtin              \
	-fno-strict-aliasing      \
	-Wall                     \
	-ggdb                     \
	-m32                      \
	-fno-omit-frame-pointer   \
	-fno-stack-protector      \
	-I$(shell pwd)/../include \

ASFLAGS =                   \
	-m32                      \
	-gdwarf-2                 \
	-Wa,-divide               \
	-I$(shell pwd)/../include \

LDFLAGS += -m elf_i386

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

all: $(KERNEL_OBJS)

%.o: %.c
	@echo "[CC] [KERNEL ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	@echo "[CC] [KERNEL ] $@"
	@$(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(RM) -rf *.o
