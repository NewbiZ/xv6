# Build tools
QEMU = qemu
CC = gcc
AS = gas
LD = ld
OBJCOPY = objcopy
OBJDUMP = objdump
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -MD -ggdb -m32 -fno-omit-frame-pointer -fno-stack-protector
CFLAGS += -I$(shell pwd)/include
ASFLAGS = -m32 -gdwarf-2 -Wa,-divide
ASFLAGS += -I$(shell pwd)/include
LDFLAGS += -m elf_i386

ALL_KERNEL_OBJS = 			\
	$(KERNEL_OBJS)    	 	\
	$(KERNEL_FS_OBJS) 	 	\
	$(KERNEL_BOOT_OBJS) 	\
	$(KERNEL_VMM_OBJS)	 	\
	$(KERNEL_DRIVER_OBJS)

KERNEL_OBJS = 			\
	kernel/console.o	\
	kernel/exec.o			\
	kernel/file.o			\
	kernel/ioapic.o		\
	kernel/kalloc.o		\
	kernel/mp.o				\
	kernel/picirq.o		\
	kernel/pipe.o			\
	kernel/proc.o			\
	kernel/spinlock.o	\
	kernel/swtch.o		\
	kernel/syscall.o	\
	kernel/sysfile.o	\
	kernel/sysproc.o	\
	kernel/timer.o		\
	kernel/trapasm.o	\
	kernel/trap.o			\
	kernel/vectors.o	\
	kernel/string.o		\
	kernel/lapic.o

KERNEL_FS_OBJS = 	\
	fs/bio.o				\
	fs/fs.o					\
	fs/log.o

KERNEL_BOOT_OBJS = 	\
	boot/main.o

KERNEL_VMM_OBJS = \
	vmm/vm.o

KERNEL_DRIVER_OBJS = 			\
	drivers/serial/uart.o		\
	drivers/ide/ide.o				\
	drivers/keyboard/kbd.o	\
	drivers/acpi/acpi.o

all: disk.img

disk.img: bootblock kernel.img distrib/distrib.img
	dd if=/dev/zero of=disk.img count=10000
	dd if=bootblock of=disk.img conv=notrunc
	dd if=kernel.img of=disk.img seek=1 conv=notrunc

distrib/distrib.img:
	$(MAKE) -C distrib

bootblock: boot/bootasm.S boot/bootmain.c
	$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c boot/bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/bootasm.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	#$(OBJDUMP) -S bootblock.o > bootblock.asm
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	./tools/boot_sign.pl bootblock

entryother: boot/entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother
	#$(OBJDUMP) -S bootblockother.o > entryother.asm

initcode: kernel/initcode.S
	$(CC) $(CFLAGS) -nostdinc -I. -c kernel/initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode
	#$(OBJDUMP) -S initcode.o > initcode.asm

kernel.img: $(ALL_KERNEL_OBJS) boot/entry.o entryother initcode kernel.ld
	$(LD) $(LDFLAGS) -T kernel.ld -o kernel.img boot/entry.o $(ALL_KERNEL_OBJS) -b binary initcode entryother
	#$(OBJDUMP) -S kernel.img > kernel.asm
	#$(OBJDUMP) -t kernel.img | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > kernel.sym

.PRECIOUS: %.o

-include *.d

qemu: distrib/distrib.img disk.img
	$(QEMU) -serial mon:stdio -hdb distrib/distrib.img disk.img -smp 2 -m 512 $(QEMUEXTRA)

clean:
	rm -f *.tex *.dvi *.idx *.aux *.log *.ind *.ilg \
	*.o *.d *.asm *.sym bootblock entryother \
	initcode initcode.out kernel.img disk.img \
	rm -rf drivers/keyboard/*.o drivers/keyboard/*.d drivers/keyboard/*.asm drivers/keyboard/*.sym
	rm -rf drivers/ide/*.o drivers/ide/*.d drivers/ide/*.asm drivers/ide/*.sym
	rm -rf drivers/serial/*.o drivers/serial/*.d drivers/serial/*.asm drivers/serial/*.sym
	rm -rf drivers/acpi/*.o drivers/acpi/*.d drivers/acpi/*.asm drivers/acpi/*.sym
	rm -rf fs/*.o fs/*.d fs/*.asm fs/*.sym
	rm -rf kernel/*.o kernel/*.d kernel/*.asm kernel/*.sym
	rm -rf vmm/*.o vmm/*.d vmm/*.asm vmm/*.sym
	rm -rf boot/*.o boot/*.d boot/*.asm boot/*.sym
