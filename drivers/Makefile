top_srcdir = ..
include $(top_srcdir)/Makefile.common

.PHONY: all clean

all: kernel_drivers.o

KERNEL_DRIVERS_OBJS =               \
	acpi/kernel_driver_acpi.o         \
	serial/kernel_driver_serial.o     \
	keyboard/kernel_driver_keyboard.o \
	ide/kernel_driver_ide.o           \

kernel_drivers.o: $(KERNEL_DRIVERS_OBJS)
	@echo "[LD] [DRIVERS] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

$(KERNEL_DRIVERS_OBJS):
	@$(MAKE) -sC acpi
	@$(MAKE) -sC serial
	@$(MAKE) -sC keyboard
	@$(MAKE) -sC ide

clean:
	$(MAKE) -sC acpi clean
	$(MAKE) -sC serial clean
	$(MAKE) -sC keyboard clean
	$(MAKE) -sC ide clean
	$(RM) -rf kernel_drivers.o
