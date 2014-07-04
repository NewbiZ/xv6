TOP_SRCDIR = .
COMPONENT = KERNEL 
include $(TOP_SRCDIR)/Makefile.common

ALL_KERNEL_OBJS =          \
	kernel/kernel.o          \
	fs/kernel_fs.o           \
	boot/kernel_boot.o       \
	vmm/kernel_vmm.o         \
	drivers/kernel_drivers.o \

.PHONY: all motd kernel distrib distrib_check kerneldisk
.PRECIOUS: boot/%.o drivers/acpi/%.o drivers/serial/%.o drivers/keyboard/%.o drivers/ide/%.o kernel/%.o fs/%.o vmm/%.o

all: motd kerneldisk distrib

motd:
	@echo "\033[32;1m"
	@echo "[>>] [KERNEL ]"
	@echo -n "\033[0m"

kernel: kernel.img

distrib: distrib/distrib.img

distrib_check: distrib/distrib_check.img

kerneldisk: disk.img

disk.img: boot/bootblock kernel.img
	$(LOG_CMD) dd if=/dev/zero of=disk.img count=10000 > /dev/null 2>&1
	$(LOG_CMD) dd if=boot/bootblock of=disk.img conv=notrunc > /dev/null 2>&1
	$(LOG_CMD) dd if=kernel.img of=disk.img seek=1 conv=notrunc > /dev/null 2>&1
	@echo "\033[32;1m[>>] [KERNEL ] Created bootable disk image "\""disk.img"\""\033[0m"

distrib/distrib.img:
	$(LOG_MAKE) -C distrib

distrib/distrib_check.img:
	$(LOG_MAKE) -C distrib check

boot/bootblock:
	$(LOG_MAKE) -C boot bootblock

boot/entryother:
	$(LOG_MAKE) -C boot entryother

kernel.img: $(ALL_KERNEL_OBJS) boot/entryother kernel/initcode kernel/kernel.ld
	$(LOG_LD) $(LD) $(LDFLAGS) -T kernel/kernel.ld -o kernel.img $(ALL_KERNEL_OBJS) -b binary kernel/initcode boot/entryother
	$(LOG_CMD) $(CHMOD) -x kernel.img
	@echo "\033[32;1m[>>] [KERNEL ] Created kernel image "\""kernel.img"\""\033[0m"

$(ALL_KERNEL_OBJS):
	$(LOG_MAKE) -C kernel
	$(LOG_MAKE) -C fs
	$(LOG_MAKE) -C boot
	$(LOG_MAKE) -C vmm
	$(LOG_MAKE) -C drivers

qemu: distrib/distrib.img disk.img
	$(LOG_CMD) $(QEMU) -serial mon:stdio -hdb distrib/distrib.img disk.img -smp 2 -m 512 $(QEMUEXTRA)

check: distrib/distrib_check.img disk.img
	$(LOG_CMD) $(QEMU) -nographic -serial mon:stdio -hdb distrib/distrib_check.img disk.img -smp 2 -m 512 $(QEMUEXTRA)

clean:
	$(LOG_CMD) $(RM) -rf kernel.img disk.img
	$(LOG_MAKE) -C distrib clean
	$(LOG_MAKE) -C kernel clean
	$(LOG_MAKE) -C vmm clean
	$(LOG_MAKE) -C fs clean
	$(LOG_MAKE) -C drivers clean
	$(LOG_MAKE) -C boot clean
