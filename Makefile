# Build tools
QEMU = qemu
CC = gcc
AS = gas
LD = ld
OBJCOPY = objcopy
OBJDUMP = objdump
CFLAGS =                  \
	-fno-pic                \
	-static                 \
	-fno-builtin            \
	-fno-strict-aliasing    \
	-Wall                   \
	-ggdb                   \
	-m32                    \
	-fno-omit-frame-pointer \
	-fno-stack-protector    \
	-I$(shell pwd)/include  \

ASFLAGS =                 \
	-m32                    \
	-gdwarf-2               \
	-Wa,-divide             \
	-I$(shell pwd)/include  \

LDFLAGS += -m elf_i386

ALL_KERNEL_OBJS =       \
	$(KERNEL_OBJS)        \
	$(KERNEL_FS_OBJS)     \
	$(KERNEL_BOOT_OBJS)   \
	$(KERNEL_VMM_OBJS)    \
	$(KERNEL_DRIVER_OBJS) \

KERNEL_OBJS =       \
	kernel/console.o  \
	kernel/exec.o     \
	kernel/file.o     \
	kernel/ioapic.o   \
	kernel/kalloc.o   \
	kernel/mp.o       \
	kernel/picirq.o   \
	kernel/pipe.o     \
	kernel/proc.o     \
	kernel/spinlock.o \
	kernel/swtch.o    \
	kernel/syscall.o  \
	kernel/sysfile.o  \
	kernel/sysproc.o  \
	kernel/timer.o    \
	kernel/trapasm.o  \
	kernel/trap.o     \
	kernel/vectors.o  \
	kernel/string.o   \
	kernel/lapic.o    \

KERNEL_FS_OBJS =  \
	fs/bio.o        \
	fs/fs.o         \
	fs/log.o        \

KERNEL_BOOT_OBJS = \
	boot/main.o      \
	boot/entry.o     \

KERNEL_VMM_OBJS = \
	vmm/vm.o        \

KERNEL_DRIVER_OBJS =      \
	drivers/serial/uart.o   \
	drivers/ide/ide.o       \
	drivers/keyboard/kbd.o  \
	drivers/acpi/acpi.o     \

# Virtual targets
all: kerneldisk distrib

kernel: kernel.img

distrib: distrib/distrib.img

kerneldisk: disk.img

# Physical targets
disk.img: bootblock kernel.img
	@dd if=/dev/zero of=disk.img count=10000 > /dev/null 2>&1
	@dd if=bootblock of=disk.img conv=notrunc > /dev/null 2>&1
	@dd if=kernel.img of=disk.img seek=1 conv=notrunc > /dev/null 2>&1
	@echo "\033[36;1mCreated bootable disk image "\""disk.img"\""\033[0m"

distrib/distrib.img:
	@$(MAKE) -sC distrib

bootblock: boot/bootasm.S boot/bootmain.c
	@$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c boot/bootmain.c
	@$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/bootasm.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	@$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock > /dev/null 2>&1
	@./tools/boot_sign.pl bootblock

entryother: boot/entryother.S
	@$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/entryother.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	@$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother > /dev/null 2>&1

initcode: kernel/initcode.S
	@$(CC) $(CFLAGS) -nostdinc -I. -c kernel/initcode.S
	@$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	@$(OBJCOPY) -S -O binary initcode.out initcode > /dev/null 2>&1

kernel.img: $(ALL_KERNEL_OBJS) entryother initcode kernel.ld
	@$(LD) $(LDFLAGS) -T kernel.ld -o kernel.img $(ALL_KERNEL_OBJS) -b binary initcode entryother
	@echo "\033[36;1mCreated kernel image "\""kernel.img"\""\033[0m"

.PRECIOUS: boot/%.o drivers/acpi/%.o drivers/serial/%.o drivers/keyboard/%.o drivers/ide/%.o kernel/%.o fs/%.o vmm/%.o

$(KERNEL_OBJS):
	@$(MAKE) -sC kernel

$(KERNEL_VMM_OBJS):
	@$(MAKE) -sC vmm

$(KERNEL_FS_OBJS):
	@$(MAKE) -sC fs

$(KERNEL_BOOT_OBJS):
	@$(MAKE) -sC boot

$(KERNEL_DRIVER_OBJS):
	@$(MAKE) -sC drivers

qemu: distrib/distrib.img disk.img
	@$(QEMU) -serial mon:stdio -hdb distrib/distrib.img disk.img -smp 2 -m 512 $(QEMUEXTRA)

clean:
	$(RM) *.o *.d *.asm *.sym bootblock entryother initcode initcode.out kernel.img disk.img
	@$(MAKE) -sC distrib clean
	@$(MAKE) -sC kernel clean
	@$(MAKE) -sC vmm clean
	@$(MAKE) -sC fs clean
	@$(MAKE) -sC drivers clean
	@$(MAKE) -sC boot clean
