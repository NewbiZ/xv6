top_srcdir = ../..
include $(top_srcdir)/Makefile.common

ACPI_OBJS = \
	acpi.o    \

.PHONY: all clean

all: kernel_driver_acpi.o

kernel_driver_acpi.o: $(ACPI_OBJS)
	@echo "[LD] [DRIVERS] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [DRIVERS] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
