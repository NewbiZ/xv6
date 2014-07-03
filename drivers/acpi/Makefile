TOP_SRCDIR = ../..
COMPONENT = "DRIVERS"
include $(TOP_SRCDIR)/Makefile.common

ACPI_OBJS = \
	acpi.o    \

.PHONY: all clean

all: kernel_driver_acpi.o

kernel_driver_acpi.o: $(ACPI_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
