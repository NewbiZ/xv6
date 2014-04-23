OBJS = \
	fs/bio.o\
	kernel/console.o\
	kernel/exec.o\
	kernel/file.o\
	fs/fs.o\
	drivers/ide/ide.o\
	kernel/ioapic.o\
	kernel/kalloc.o\
	drivers/keyboard/kbd.o\
	kernel/lapic.o\
	fs/log.o\
	boot/main.o\
	kernel/mp.o\
	kernel/picirq.o\
	kernel/pipe.o\
	kernel/proc.o\
	kernel/spinlock.o\
	klibc/string.o\
	kernel/swtch.o\
	kernel/syscall.o\
	kernel/sysfile.o\
	kernel/sysproc.o\
	kernel/timer.o\
	kernel/trapasm.o\
	kernel/trap.o\
	drivers/serial/uart.o\
	kernel/vectors.o\
	vmm/vm.o\

QEMU=qemu
CC = gcc
AS = gas
LD = ld
OBJCOPY = objcopy
OBJDUMP = objdump
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)
CFLAGS += -I$(shell pwd)/include -I$(shell pwd)/klibc
ASFLAGS = -m32 -gdwarf-2 -Wa,-divide
ASFLAGS += -I$(shell pwd)/include
# FreeBSD ld wants ``elf_i386_fbsd''
LDFLAGS += -m $(shell $(LD) -V | grep elf_i386 2>/dev/null)

xv6.img: bootblock kernel.img fs.img
	dd if=/dev/zero of=xv6.img count=10000
	dd if=bootblock of=xv6.img conv=notrunc
	dd if=kernel.img of=xv6.img seek=1 conv=notrunc

bootblock: boot/bootasm.S boot/bootmain.c
	$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c boot/bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/bootasm.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(OBJDUMP) -S bootblock.o > bootblock.asm
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	./tools/boot_sign.pl bootblock

entryother: boot/entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c boot/entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother
	$(OBJDUMP) -S bootblockother.o > entryother.asm

initcode: kernel/initcode.S
	$(CC) $(CFLAGS) -nostdinc -I. -c kernel/initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode
	$(OBJDUMP) -S initcode.o > initcode.asm

kernel.img: $(OBJS) boot/entry.o entryother initcode kernel.ld
	$(LD) $(LDFLAGS) -T kernel.ld -o kernel.img boot/entry.o $(OBJS) -b binary initcode entryother
	$(OBJDUMP) -S kernel.img > kernel.asm
	$(OBJDUMP) -t kernel.img | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > kernel.sym

tags: $(OBJS) boot/entryother.S _init
	etags *.S *.c

ULIB = klibc/ulib.o klibc/usys.o klibc/printf.o klibc/umalloc.o

_%: %.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^
	$(OBJDUMP) -S $@ > $*.asm
	$(OBJDUMP) -t $@ | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > $*.sym

_forktest: forktest.o $(ULIB)
	# forktest has less library code linked in - needs to be small
	# in order to be able to max out the proc table.
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o _forktest forktest.o user/ulib.o user/usys.o
	$(OBJDUMP) -S _forktest > forktest.asm

mkfs: tools/mkfs.c include/fs.h
	gcc -Werror -Wall -o mkfs tools/mkfs.c

# Prevent deletion of intermediate files, e.g. cat.o, after first build, so
# that disk image changes after first build are persistent until clean.  More
# details:
# http://www.gnu.org/software/make/manual/html_node/Chained-Rules.html
.PRECIOUS: %.o

UPROGS=\
	user/_cat\
	user/_echo\
	user/_forktest\
	user/_grep\
	user/_init\
	user/_kill\
	user/_ln\
	user/_ls\
	user/_mkdir\
	user/_rm\
	user/_sh\
	user/_stressfs\
	user/_usertests\
	user/_wc\
	user/_zombie\
	user/_halt\

UPROGS_LOCAL=\
	_cat\
	_echo\
	_forktest\
	_grep\
	_init\
	_kill\
	_ln\
	_ls\
	_mkdir\
	_rm\
	_sh\
	_stressfs\
	_usertests\
	_wc\
	_zombie\
	_halt\

fs.img: mkfs $(UPROGS)
	cd user && ../mkfs ../fs.img $(UPROGS_LOCAL)

-include *.d

clean: 
	rm -f *.tex *.dvi *.idx *.aux *.log *.ind *.ilg \
	*.o *.d *.asm *.sym bootblock entryother \
	initcode initcode.out kernel.img xv6.img fs.img mkfs \
	.gdbinit \
	$(UPROGS)
	rm -rf user/*.o user/*.d user/*.asm user/*.sym
	rm -rf drivers/keyboard/*.o drivers/keyboard/*.d drivers/keyboard/*.asm drivers/keyboard/*.sym
	rm -rf drivers/ide/*.o drivers/ide/*.d drivers/ide/*.asm drivers/ide/*.sym
	rm -rf drivers/serial/*.o drivers/serial/*.d drivers/serial/*.asm drivers/serial/*.sym
	rm -rf klibc/*.o klibc/*.d klibc/*.asm klibc/*.sym
	rm -rf fs/*.o fs/*.d fs/*.asm fs/*.sym
	rm -rf kernel/*.o kernel/*.d kernel/*.asm kernel/*.sym
	rm -rf vmm/*.o vmm/*.d vmm/*.asm vmm/*.sym
	rm -rf boot/*.o boot/*.d boot/*.asm boot/*.sym

# QEMU's gdb stub command line changed in 0.11
QEMUGDB = $(shell if $(QEMU) -help | grep -q '^-gdb'; \
	then echo "-gdb tcp::$(GDBPORT)"; \
	else echo "-s -p $(GDBPORT)"; fi)
ifndef CPUS
CPUS := 2
endif
QEMUOPTS = -hdb fs.img xv6.img -smp $(CPUS) -m 512 $(QEMUEXTRA)

qemu: fs.img xv6.img
	$(QEMU) -serial mon:stdio $(QEMUOPTS)

qemu-memfs: xv6memfs.img
	$(QEMU) xv6memfs.img -smp $(CPUS)

qemu-nox: fs.img xv6.img
	$(QEMU) -nographic $(QEMUOPTS)

.gdbinit: .gdbinit.tmpl
	sed "s/localhost:1234/localhost:$(GDBPORT)/" < $^ > $@

qemu-gdb: fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) -serial mon:stdio $(QEMUOPTS) -S $(QEMUGDB)

qemu-nox-gdb: fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) -nographic $(QEMUOPTS) -S $(QEMUGDB)

