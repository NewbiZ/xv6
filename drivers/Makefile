TOP_SRCDIR = ..
COMPONENT = "DRIVERS"
include $(TOP_SRCDIR)/Makefile.common

.PHONY: all clean

all: kernel_drivers.o

KERNEL_DRIVERS_OBJS =               \
	acpi/kernel_driver_acpi.o         \
	serial/kernel_driver_serial.o     \
	keyboard/kernel_driver_keyboard.o \
	ide/kernel_driver_ide.o           \

kernel_drivers.o: $(KERNEL_DRIVERS_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

$(KERNEL_DRIVERS_OBJS):
	$(LOG_MAKE) -C acpi
	$(LOG_MAKE) -C serial
	$(LOG_MAKE) -C keyboard
	$(LOG_MAKE) -C ide

clean:
	$(LOG_MAKE) -C acpi clean
	$(LOG_MAKE) -C serial clean
	$(LOG_MAKE) -C keyboard clean
	$(LOG_MAKE) -C ide clean
	$(LOG_CMD) $(RM) -rf kernel_drivers.o
