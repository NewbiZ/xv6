top_srcdir = .
include $(top_srcdir)/Makefile.common

ALL_KERNEL_OBJS =          \
	kernel/kernel.o          \
	fs/kernel_fs.o           \
	boot/kernel_boot.o       \
	vmm/kernel_vmm.o         \
	drivers/kernel_drivers.o \

all: kerneldisk distrib

kernel: kernel.img

distrib: distrib/distrib.img

kerneldisk: disk.img

disk.img: boot/bootblock kernel.img
	@dd if=/dev/zero of=disk.img count=10000 > /dev/null 2>&1
	@dd if=boot/bootblock of=disk.img conv=notrunc > /dev/null 2>&1
	@dd if=kernel.img of=disk.img seek=1 conv=notrunc > /dev/null 2>&1
	@echo "\033[36;1mCreated bootable disk image "\""disk.img"\""\033[0m"

distrib/distrib.img:
	@$(MAKE) -sC distrib

boot/bootblock:
	@$(MAKE) -sC boot bootblock

boot/entryother:
	@$(MAKE) -sC boot entryother

kernel.img: $(ALL_KERNEL_OBJS) boot/entryother kernel/initcode kernel/kernel.ld
	@$(LD) $(LDFLAGS) -T kernel/kernel.ld -o kernel.img $(ALL_KERNEL_OBJS) -b binary kernel/initcode boot/entryother
	@echo "\033[36;1mCreated kernel image "\""kernel.img"\""\033[0m"

.PRECIOUS: boot/%.o drivers/acpi/%.o drivers/serial/%.o drivers/keyboard/%.o drivers/ide/%.o kernel/%.o fs/%.o vmm/%.o

$(ALL_KERNEL_OBJS):
	@$(MAKE) -sC kernel
	@$(MAKE) -sC fs
	@$(MAKE) -sC boot
	@$(MAKE) -sC vmm
	@$(MAKE) -sC drivers

qemu: distrib/distrib.img disk.img
	@$(QEMU) -serial mon:stdio -hdb distrib/distrib.img disk.img -smp 2 -m 512 $(QEMUEXTRA)

clean:
	$(RM) -rf kernel.img disk.img
	@$(MAKE) -sC distrib clean
	@$(MAKE) -sC kernel clean
	@$(MAKE) -sC vmm clean
	@$(MAKE) -sC fs clean
	@$(MAKE) -sC drivers clean
	@$(MAKE) -sC boot clean
